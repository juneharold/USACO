"""
LANG: PYTHON3
PROG: gift1
"""
# reading files
f_in = open("gift1.in", "r")
f_out = open("gift1.out", "w")
contents = f_in.readlines()

# number and names of people
NP = int(contents[0])
names = []
bank = {}
for i in range(NP):
    names.append(contents[i+1])
    bank[contents[i+1]] = 0

# iteration at person giving
iteration = NP+1

for i in range(NP):
    giver = contents[iteration]
    # iteration at amount and number of person
    iteration = iteration + 1
    amount, num_person = contents[iteration].split()
    amount = int(amount)
    num_person = int(num_person)
    if num_person == 0:
        given = 0
        left = 0
    else:
        given = amount // num_person
        left = amount - num_person * given
    bank[giver] = (bank[giver] - amount + left)
    # iteration at first person receiving money
    iteration = iteration + 1
    for i in range(num_person):
        name = contents[iteration+i]
        bank[name] = (bank[name] + given)
    iteration = iteration + num_person

new_names = []
for i in range(len(names)):
    new_names.append(names[i].rstrip())

for i in range(NP):
    f_out.write("{} {}\n".format(new_names[i], bank[names[i]]))

f_in.close()
f_out.close()










