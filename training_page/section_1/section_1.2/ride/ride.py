"""
LANG: PYTHON3
PROG: ride
"""
f_in = open("ride.in", "r")
f_out = open("ride.out", "w")

contents = f_in.read()

lines = contents.splitlines()
comet = lines[0]
group = lines[1]

characters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
numbers = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26']

comet_num = 1
for i in range(len(comet)):
    comet_num *= int((numbers[characters.index(comet[i])]))

group_num = 1
for i in range(len(group)):
    group_num *= int((numbers[characters.index(group[i])]))

if group_num % 47 == comet_num % 47:
    f_out.write("GO\n")
else:
    f_out.write("STAY\n")

f_in.close()
f_out.close()








