from typing import Callable
def enum(length):
    if length == 0: return [[]]
    t_case = [[True]  + case for case in enum(length - 1)]
    f_case = [[False] + case for case in enum(length - 1)]
    return t_case + f_case

def bool_to_logic(args):
    if not isinstance(args, list):
        return 'T' if args else '⊥'
    return [bool_to_logic(arg) for arg in args]

def pretty_print(expr_func, length):
    for case in enum(length):
        case_str = bool_to_logic(case)
        expr_str = bool_to_logic(expr_func(*case))
        table_str = '|  ' + '  |  '.join([*case_str, *expr_str]) + '  |'
        print(table_str)


def func1(W, X, Y, Z):
    return (not(W and X)) and (not(not Y or not Z))

def func2(A, B, C, D):
    return (A and B) or (not(B) and C) or (not(C) and D) or (not(D) and A)

def main(variables: str, expresion: str, expr_func: Callable):
    print(*variables, expresion, sep='  ')
    pretty_print(expr_func, 4)



