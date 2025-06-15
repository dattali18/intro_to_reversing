def generate_password(username):
    # Validate username requirements
    if len(username) < 4 or len(username) > 15:
        return "Error: Username must be between 4-15 characters"
    if username[0] == " ":
        return "Error: Username cannot start with a space"

    # Step 1: Process the username to generate values (dword_401055)
    processed_values = []
    running_sum = 0
    for i in range(len(username)):
        # The algorithm from the C code
        counter = i + 1
        val = ord(username[i])
        val = val * counter
        val = val + counter
        # These bit shifts look odd in C, but they effectively reset most bits
        # The shifts are so large they essentially keep only the lower bits
        val = (val << 0xDE) & 0xFFFFFFFF
        val = (val >> 0xAD) & 0xFFFFFFFF
        val = val ^ counter
        val = (val + 0x35) & 0xFF  # Keep as byte
        processed_values.append(val)
        running_sum += val

    # Step 2: Calculate the "hash" value
    # Multiply running sum by first processed value
    edx = (running_sum * processed_values[0]) & 0xFFFFFFFF
    # Bitwise NOT
    edx = (~edx) & 0xFFFFFFFF

    # Step 3: Convert to string and prepare for transformation
    # This simulates the sprintf to address 0x40121D
    formatted_string = str(edx)

    # Step 4: Apply XOR decryption (simulates xor_decrypt_string)
    # In real code each byte is XOR with 0xDEADBABE, but effective with just 0xBE for bytes
    xor_decrypted = [ord(c) ^ 0xBE for c in formatted_string]

    # Step 5: Apply code patching transformations (simulates anti_debug_code_patcher)
    transformed = []
    for i, val in enumerate(xor_decrypted):
        if val == 0:  # End of string
            transformed.extend([0xF293, 0xFBFB, 0xEA])
            break
        elif val <= 0x8E or val == 0x8F:  # Do nothing
            transformed.append(val)
        elif val == 0x93:  # Write 0x8D
            transformed.append(0x8D)
        else:  # Decrement by 1
            transformed.append(val - 1)

    # Step 6: Calculate the password by XORing back with 0xBE
    password = "".join([chr(b ^ 0xBE) for b in transformed])

    return password


# Example usage
if __name__ == "__main__":
    while True:
        username = input("Enter a username (4-15 chars, no leading space): ")
        if not username:
            break
        password = generate_password(username)
        print(f"Generated password: {password}")
