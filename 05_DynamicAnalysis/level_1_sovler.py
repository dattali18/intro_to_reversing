import sys

def xor_string_with_key(input_str, key_hex):
    key = int(key_hex, 16)
    result = []
    for c in input_str:
        xored = ord(c) ^ key
        result.append(chr(xored))
    return result

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: python {sys.argv[0]} <string> <key_hex>")
        sys.exit(1)
    input_str = sys.argv[1]
    key_hex = sys.argv[2]
    xored_chars = xor_string_with_key(input_str, key_hex)
    print("XORed char array:", xored_chars)
    print("XORed as string:", ''.join(xored_chars))