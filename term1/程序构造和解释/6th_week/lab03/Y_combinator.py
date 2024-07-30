#!/usr/bin/python3
from operator import sub, mul

def Y(f):
    return f(lambda : Y(f))

def Y_tester():
    return Y(lambda x: lambda n: mul(x()(n-1), n) if n != 1 else 1)
