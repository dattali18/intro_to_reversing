# this file will be used a a script that recives a string and xor each by with a given key
# usage name.py <key> <string>

import sys

import binascii

def xor_string(key: int, string: str):
    res = ""
    for ch in string:
        # Convert the character to its ASCII value
        ascii_value = ord(ch)
        # XOR the ASCII value with the key
        xor_value = ascii_value ^ key
        # Convert the XOR value to a hexadecimal string
        res += chr(xor_value)
    return res

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python riddle2.py <key> <string>")
        sys.exit(1)

    key = int(sys.argv[1])
    string = sys.argv[2]

    result = xor_string(key, string)
    print(result)