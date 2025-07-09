# Build substitution table from DLL headers and apply it to the entire corrupted file

HEADER_SIZE = 0x200  # Compare first 512 bytes for the mapping


def build_substitution_table(good_path, bad_path, header_size=HEADER_SIZE):
    with open(good_path, "rb") as f:
        good_header = f.read(header_size)
    with open(bad_path, "rb") as f:
        bad_header = f.read(header_size)
    table = {}
    for g, b in zip(good_header, bad_header):
        if g != b and b not in table:
            table[b] = g
    return table


def apply_table_to_whole_file(bad_path, output_path, table):
    with open(bad_path, "rb") as f:
        data = bytearray(f.read())
    count = 0
    for i in range(len(data)):
        orig = data[i]
        if orig in table:
            data[i] = table[orig]
            count += 1
    with open(output_path, "wb") as f:
        f.write(data)
    print(f"Patched file written to {output_path}")
    print(f"Total substitutions made: {count}")
    print("Substitution table (corrupted: correct):")
    for c, g in table.items():
        print(f"  {c:02X} -> {g:02X}")


if __name__ == "__main__":
    ref = "dll_example.dll"
    corrupted = "AttackIRGC.dll"
    output = "AttackIRGC_fullypatched.dll"
    table = build_substitution_table(ref, corrupted)
    apply_table_to_whole_file(corrupted, output, table)
