import binascii


def read_hex_file(file_path):
    with open(file_path, "r") as file:
        hex_string = file.read().replace("\n", "").replace(" ", "")
    return binascii.unhexlify(hex_string)


def replace_bomb_with_key(input_path, output_path, key):
    with open(input_path, "rb") as f:
        data = f.read()

    # Replace all b'BOMB' chunks with 4 bytes from the key, cycling through the key
    key_chunks = [key[i : i + 4] for i in range(0, len(key), 4)]
    new_data = bytearray()
    i = 0
    chunk_idx = 0
    while i < len(data):
        if data[i : i + 4] == b"BOMB":
            # Replace with next key chunk
            new_data += key_chunks[chunk_idx % len(key_chunks)]
            i += 4
            chunk_idx += 1
        else:
            new_data.append(data[i])
            i += 1

    with open(output_path, "wb") as f:
        f.write(new_data)


if __name__ == "__main__":
    key = read_hex_file("DroneAttack.txt")
    replace_bomb_with_key("AttackIRGC.dll", "Patched_AttackIRGC.dll", key)
    print("Patched file written as Patched_AttackIRGC.dll")
