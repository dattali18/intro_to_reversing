"""
This program is used to test an hypothesis about the CTF
The problem is has follows I have a "AttackIRGC.dll" file which is not a correct PE file
and I also was given a "DroneAttack.txt" which contains the following text:
```
CCD9 0A32 6E2B 1196 6E3D 8F47 1FF9 D252
```
which might be some kind of key or hash.
The goal of this program is to try and test different combinations of decrypting the
"AttackIRGC.dll" file using the "DroneAttack.txt" as a key.

1. First step is to read the "DroneAttack.txt" file and convert the hex values into bytes.
2. Then, we will read the "AttackIRGC.dll" file as binary and try to decrypt it using the bytes
"""

import binascii

def read_hex_file(file_path):
    """
    Reads a file containing hex values and converts them to bytes.
    
    :param file_path: Path to the file containing hex values.
    :return: Bytes object representing the hex values.
    """
    with open(file_path, 'r') as file:
        hex_string = file.read().replace('\n', '').replace(' ', '')
    return binascii.unhexlify(hex_string)

def read_binary_file(file_path):
    """
    Reads a binary file and returns its content.
    
    :param file_path: Path to the binary file.
    :return: Bytes object representing the content of the binary file.
    """
    with open(file_path, 'rb') as file:
        return file.read()
    
def decrypt_with_key(binary_data, key):
    """
    Decrypts the binary data using the provided key.
    
    :param binary_data: Bytes object representing the binary data to decrypt.
    :param key: Bytes object representing the key to use for decryption.
    :return: Decrypted bytes object.
    """
    decrypted_data = bytearray()
    key_length = len(key)
    
    for i in range(len(binary_data)):
        decrypted_byte = binary_data[i] ^ key[i % key_length]
        decrypted_data.append(decrypted_byte)
    
    return bytes(decrypted_data)

def main():
    # Read the hex file and convert it to bytes
    print("Reading key from DroneAttack.txt...")
    key = read_hex_file('DroneAttack.txt')

    # print the key in hex
    print("Key read successfully. Key in hex:", key.hex())
    
    print("Ready to decrypt the binary file using the key...")
    # Read the binary file
    binary_data = read_binary_file('AttackIRGC.dll')
    
    print("Decrypting the binary data...")
    # Decrypt the binary data using the key
    decrypted_data = decrypt_with_key(binary_data, key)
    
    print("Decryption complete. Writing to file...")
    # Save the decrypted data to a new file
    with open('Decrypted_AttackIRGC.dll', 'wb') as file:
        file.write(decrypted_data)
    
    print("Decryption complete. Decrypted data saved to 'Decrypted_AttackIRGC.dll'.")

if __name__ == "__main__":
    main()