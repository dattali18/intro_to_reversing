from Crypto.Cipher import AES

key = bytes.fromhex("ccd90a326e2b11966e3d8f471ff9d252")
with open("AttackIRGC.dll", "rb") as f:
    data = f.read()

# Try ECB mode first (most common in CTFs)
cipher = AES.new(key, AES.MODE_ECB)
decrypted = cipher.decrypt(data)

with open("Decrypted_AttackIRGC.dll", "wb") as f:
    f.write(decrypted)
print("Decryption with AES-ECB done. Check Decrypted_AttackIRGC.dll")
