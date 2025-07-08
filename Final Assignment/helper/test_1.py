def func(x, y):
    return ((x ^ y) + (x & y)) - (x | y)

def main():
    for i in range(1000):
        for j in range(1000):
            if func(i, j) != 0:
                print(f"Not zero for func({i}, {j})")

if __name__ == '__main__':
    main()
