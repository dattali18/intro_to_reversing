import hashlib

candidate = bytes.fromhex("CCD90A326E2B11966E3D8F471FF9D252")
print(hashlib.md5(candidate).hexdigest().upper())
