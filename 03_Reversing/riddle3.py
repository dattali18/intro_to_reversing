import sys
import struct


def xor_string_dword(key: int, string: str):
    result = ""
    # Make sure string length is a multiple of 4 by padding with zeros if needed
    while len(string) % 4 != 0:
        string += "\0"

    for i in range(0, len(string), 4):
        # Take 4 characters and convert to dword (little-endian)
        chunk = string[i : i + 4]
        dword_value = struct.unpack("<I", chunk.encode())[0]

        # XOR the entire dword with the key
        xored_dword = dword_value ^ key

        # Convert back to 4 characters
        xored_chunk = struct.pack("<I", xored_dword).decode(errors="replace")
        result += xored_chunk

    return result


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python riddle2.py <key_in_hex> <string>")
        sys.exit(1)

    # Parse key in hexadecimal
    key = int(sys.argv[1], 16)
    string = sys.argv[2]

    result = xor_string_dword(key, string)
    print(result)
