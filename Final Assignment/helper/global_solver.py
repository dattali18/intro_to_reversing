# Patch only the bytes in the corrupted file that don't match the reference,
# but only at the positions found in the first HEADER_SIZE bytes.

HEADER_SIZE = 0x200  # 512 bytes, adjust if needed


def patch_by_position(good_path, bad_path, output_path, header_size=HEADER_SIZE):
    with open(good_path, "rb") as f:
        good = f.read(header_size)
    with open(bad_path, "rb") as f:
        bad = bytearray(f.read())

    patched_count = 0
    for i in range(header_size):
        if bad[i] != good[i]:
            bad[i] = good[i]
            patched_count += 1

    with open(output_path, "wb") as f:
        f.write(bad)

    print(
        f"Patched {patched_count} bytes in header region only (location-based patch)."
    )
    print(f"Result written to {output_path}")


if __name__ == "__main__":
    patch_by_position(
        "dll_example.dll", "AttackIRGC.dll", "AttackIRGC_headerpatched.dll"
    )
