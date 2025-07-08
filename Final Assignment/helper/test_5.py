def replace_bomb_patterns_with_null(data):
    from re import finditer

    # Patterns to replace (add more if you find more variants)
    patterns = [b"BOMB", b"OMBB", b"OMB", b"MB"]

    for pat in patterns:
        start = 0
        while True:
            idx = data.find(pat, start)
            if idx == -1:
                break
            data = data[:idx] + b"\x00" * len(pat) + data[idx + len(pat) :]
            start = idx + 1  # move forward to catch overlapping patterns

    return data


if __name__ == "__main__":
    with open("AttackIRGC.dll", "rb") as f:
        data = f.read()

    new_data = replace_bomb_patterns_with_null(data)

    # Save to new file
    with open("Repaired_AttackIRGC.dll", "wb") as f:
        f.write(new_data)
    print("Wrote Repaired_AttackIRGC.dll")
