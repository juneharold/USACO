import sys
import json
import random

def output(buys):
    print(json.dumps({"buys": buys}))

buying_history = []
day = 0

while True:
    _data = json.loads(input())
    yesterday = _data["yesterday"]
    scores = _data["scores"]
    my_index = _data["my_index"]
    # End input

    buys = [2, 4, 5, 7, 9, 11, 13, 15, 16, 18]
    buying_history.append(buys)
    output(buys)
    day += 1