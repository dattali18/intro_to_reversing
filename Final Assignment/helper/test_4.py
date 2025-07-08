corrupted = b"It should not be possible to read thislB@HfOMBBOMB"
expected = b"This program cannot be run in DOS mode."
key = bytearray()
for c, e in zip(corrupted, expected):
    key.append(c ^ e)
print(str(key))
