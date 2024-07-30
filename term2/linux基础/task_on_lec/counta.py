#!/usr/bin/python3
import sys

for line in sys.stdin:
    token = max(line.split(), key=len)
    if token.count('a') >=4:
        print(line)
