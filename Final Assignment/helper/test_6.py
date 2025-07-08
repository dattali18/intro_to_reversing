import hashlib

with open("AttackIRGC.dll", "rb") as f:
    data = f.read()

expected_md5 = (
    "ccd90a326e2b11966e3d8f471ff9d252".lower()
)  # from DroneAttack.txt (remove spaces)

print("Computed MD5:", hashlib.md5(data).hexdigest())
print("Expected MD5:", expected_md5)
print("Match:", hashlib.md5(data).hexdigest() == expected_md5)
