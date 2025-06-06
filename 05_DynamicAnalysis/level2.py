import sys


def xor_string_with_4byte_key(input_str, key_hex):
    key = int(key_hex, 16)
    key_bytes = [(key >> 24) & 0xFF, (key >> 16) & 0xFF, (key >> 8) & 0xFF, key & 0xFF]
    result = []
    for i, c in enumerate(input_str):
        xored = ord(c) ^ key_bytes[i % 4]
        result.append(chr(xored))
    return result


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: python {sys.argv[0]} <string> <4byte_key_hex>")
        sys.exit(1)
    input_str = sys.argv[1]
    key_hex = sys.argv[2]
    xored_chars = xor_string_with_4byte_key(input_str, key_hex)
    print("XORed char array:", xored_chars)
    print("XORed as string:", "".join(xored_chars))
