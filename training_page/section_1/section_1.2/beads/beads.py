"""
LANG: PYTHON3
PROG: beads
"""
# f_in = open("/Users/harold/usaco_training/section_1/section_1.2/beads/beads.in", "r")
f_in = open("beads.in", "r")
f_out = open("beads.out", "w")

contents = f_in.readlines()
N = int(contents[0].rstrip())
beads = contents[1].rstrip()

max = 0
for cut in range(0, N+1):
    one = beads[0:cut+1]
    two = beads[cut+1:N]
    new_pattern = two + one

    # front
    counter_A = 1
    if new_pattern[0] != "b":
        while new_pattern[counter_A] != "b":
            counter_A += 1
            if counter_A == N:
                break
    elif new_pattern[0] != "r":
        while new_pattern[counter_A] != "r":
            counter_A += 1
            if counter_A == N:
                break

    # back
    counter_B = 1
    if new_pattern[-1] != "b":
        while new_pattern[-(counter_B+1)] != "b":
            counter_B += 1
            if counter_B == N:
                break
    elif new_pattern[-1] != "r":
        while new_pattern[-(counter_B+1)] != "r":
            counter_B += 1
            if counter_B == N:
                break

    if counter_B + counter_A > N:
        max = N
    elif counter_B +counter_A > max:
        max = counter_B +counter_A


f_out.write("{}\n".format(max))

f_in.close()
f_out.close()




