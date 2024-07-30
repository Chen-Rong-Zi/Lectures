#!/usr/bin/python3
import sys

for line in sys.stdin:
    tokens = line.split()
    if len(tokens) > 3:
        print(' '.join(tokens[3:]))

