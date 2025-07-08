# Substitute just the header region of a DLL using a reference DLL.

HEADER_SIZE = 0x200  # 512 bytes, adjust as needed


def header_patch(reference_path, corrupted_path, output_path, header_size=HEADER_SIZE):
    with open(reference_path, "rb") as f:
        ref = f.read(header_size)
    with open(corrupted_path, "rb") as f:
        corrupted = bytearray(f.read())

    # Overwrite just the header region
    corrupted[:header_size] = ref[:header_size]

    with open(output_path, "wb") as f:
        f.write(corrupted)
    print(
        f"Patched header from {reference_path} into {output_path}, first {header_size} bytes."
    )


if __name__ == "__main__":
    header_patch("dll_example.dll", "AttackIRGC.dll", "AttackIRGC_headerpatched.dll")
