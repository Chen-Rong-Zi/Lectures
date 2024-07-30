#!/usr/bin/python
import signal, time

def handler(signum, time):
    print(f"I see the {signum} signal, but no way!")

signal.signal(signal.SIGINT, handler)
signal.signal(signal.SIGTERM, handler)
signal.signal(signal.SIGQUIT, handler)

i = 0
while True:
    time.sleep(0.1)
    print(f"\r{i}", end='')
    i += 1
