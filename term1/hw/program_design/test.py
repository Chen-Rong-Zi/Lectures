def total(lst):
    new_lst = [lst[0]]
    for i in range(1, len(lst)):
        new_lst.append(new_lst[i - 1] + lst[i])
    return sum(new_lst)

def minimal(lst):
    if len(lst) == 1: return [lst]
    new_lst = []
    for i in range(len(lst)):
        for s in minimal(lst[0:i] + lst[i+1:]):
            new_lst.append([lst[i]] + s)
    return new_lst

def minimal_waiting_time(lst):
    min = float('inf')
    for i in minimal(lst):
        test = total(i)
        if test < min:
            min = test
    return min

