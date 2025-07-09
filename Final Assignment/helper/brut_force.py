import itertools

# Digits 1-8
digits = list(range(1, 9))

with open("perms.txt", "w") as f:
    for perm in itertools.permutations(digits):
        password = "".join(str(d) for d in perm)
        f.write(password + "\n")
