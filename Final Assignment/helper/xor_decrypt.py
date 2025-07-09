# fix_xor_bomb.py


def xor_bomb_fix(input_path, output_path):
    key = b"BOMB"
    key_len = len(key)
    with open(input_path, "rb") as f_in, open(output_path, "wb") as f_out:
        i = 0
        while byte := f_in.read(1):
            fixed_byte = bytes([byte[0] ^ key[i % key_len]])
            f_out.write(fixed_byte)
            i += 1


if __name__ == "__main__":
    xor_bomb_fix("AttackIRGC.dll", "AttackIRGC_fixed.dll")
    print("DLL fixed! Check 'AttackIRGC_fixed.dll'")
