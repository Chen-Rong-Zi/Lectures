#!/usr/bin/python3
import sys

def backthree(input):
    if len(input) < 3:
        return ''
    elif len(input) == 3:
        return input
    return backthree(input[1:])

for line in sys.stdin:
    lst = list(filter(lambda x : len(x) >= 3, line.split()))
    if lst:
        token = sorted(lst, key=len, reverse=True)[0]
        print(backthree(token))
