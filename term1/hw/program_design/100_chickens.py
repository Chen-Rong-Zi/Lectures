lst = [0 for i in range(1_000)]
def purchase(money, number, types, prices):
    if  money < 0 or (not prices) or types <= 0:
        return
    if  money == 0 and number == 0:
        for i in range(len(prices)):
            print(lst[i], end=" " if i != len(prices) - 1 else '\n')
        return

    purchase(money-prices[len(prices) - types], number-1, types, prices)
    lst[len(prices) - types] += 1
    purchase(money, number, types-1, prices)

def main():
    prices = [15, 9, 1]
    purchase(300, 100, 3, prices)
    return 0

if __name__ == '__main__':
    main()
