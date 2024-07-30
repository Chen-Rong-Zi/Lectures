from hog import swine_strategy, picky_piggy, swine_swap
k = 0
for i in range(100):
    for j in range(100):
        print(f"swine_strategy({i}, {j}, {k}, 999) = {swine_strategy(i, j, k, 999)}")
