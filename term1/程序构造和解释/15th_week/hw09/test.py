def find_nest(target, lst):
    """
    >>> a = [1, 2, 3, 4, [5, 6, 7, [8, 9, 10]], 11]
    >>> find_nest(11, a)
    >>> '(car (cdr (cdr (cdr (cdr (cdr a))))))'
    """
    def helper(lst, so_far):
        if len(lst) == 0:
            return None
        if lst[0] == target:
            return f'(car {so_far})'

        if isinstance(lst[0], list):
            check = helper(lst[0], f'(car {so_far})')
            if check is not None:
                return check
        return helper(lst[1:], f'(cdr {so_far})')

    return helper(lst, 'a')
