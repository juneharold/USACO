import sys
import json
import random


def output(ii, jj):
    print(json.dumps({"i": ii, "j": jj}))


def search(x, y):
    # count how many 1 tiles there are around arena[i][j]
    ret = 0
    for ii in range(x-2, x+3):
        for jj in range(y-2, y+3):
            if ii < 0 or ii > 24 or jj < 0 or jj > 24:
                continue
            if arena[ii][jj] == 1:
                ret += 1

    return ret


while True:
    _data = json.loads(input())
    arena = _data["arena"]
    players = _data["players"]
    my_index = _data["my_index"]
    grace_moves_left = _data["grace_moves_left"]

    tile_score = [[0] * 25 for _ in range(25)]
    my_i, my_j = players[my_index]["i"], players[my_index]["j"]

    for i in range(my_i-2, my_i+3):
        for j in range(my_j-2, my_j+3):
            if grace_moves_left != 0 and (i == my_i and j == my_j):
                continue
            if i < 0 or i > 24 or j < 0 or j > 24 or arena[i][j] == 0:
                continue
            tile_score[i][j] = search(i, j)

    for player in range(0, 12):
        if _data["players"][player]["alive"] == false:
            continue
        pi, pj = _data["players"][player]["i"], _data["players"][player]["j"]
        if pi == my_i and pj == my_j:
            continue
        cnt = 0
        for i in range(pi - 2, pi + 3):
            for j in range(pj - 2, pj + 3):
                if i < 0 or i > 24 or j < 0 or j > 24:
                    continue
                if arena[i][j] == 1:
                    cnt += 1
        val = 1/cnt
        for i in range(pi - 2, pi + 3):
            for j in range(pj - 2, pj + 3):
                if i < 0 or i > 24 or j < 0 or j > 24:
                    continue
                if arena[i][j] == 1:
                    tile_score[i][j] -= val

    max_score, ni, nj = -100, -1, -1

    for i in range(my_i-2, my_i+3):
        for j in range(my_j-2, my_j+3):
            if grace_moves_left == 0 and (i == my_i and j == my_j):
                continue
            if i < 0 or i > 24 or j < 0 or j > 24 or arena[i][j] == 0:
                continue
            if tile_score[i][j] > max_score:
                ni = i
                nj = j
                max_score = tile_score[i][j]

    output(ni, nj)
