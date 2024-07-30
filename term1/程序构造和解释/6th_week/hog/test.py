from hog import picky_piggy, swine_swap, swine_strategy


for i in range(101, 0, -1):
    for j in range(101, 0, -1):
        print(f"swine_strategy({i}, {j}, 10, 4) = {swine_strategy(i, j, 10, 4)}")
