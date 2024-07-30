def make_change(total, biggest):
    result = []
    def helper(total, biggest, so_far):
        if total < 0 or biggest <= 0:
            return None
        if total == 0:
            return result.append(so_far)
        with_biggest = helper(total - biggest, biggest, so_far + [biggest])
        without_biggest = helper(total, biggest - 1, so_far)
        return result
    return helper(total, biggest, [])

# def make_change(amount, max_coin):
#     def make_change_helper(amount, max_coin):
#         if amount == 0:
#             return [[]]
#         elif amount < 0 or max_coin == 0:
#             return []
#         else:
#             with_max_coin = [[max_coin] + x for x in make_change_helper(amount - max_coin, max_coin)]
#             without_max_coin = make_change_helper(amount, max_coin - 1)
#             return with_max_coin + without_max_coin
# 
#     return make_change_helper(amount, max_coin)

def nats():
    i = 0
    while 1:
        i += 1
        yield i

def factorial():
    yield 1
    backup = factorial()
    natural = nats()
    while 1:
        yield next(backup) * next(natural)

def weird_trangle():
    from time import sleep
    for i in factorial():
        print(i)
        sleep(0.05)
