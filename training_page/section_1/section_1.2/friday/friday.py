"""
LANG: PYTHON3
PROG: friday
"""
# f_in = open("/Users/harold/usaco_training/section_1/section_1.2/friday/friday.in", "r")
f_in = open("friday.in", "r")
f_out = open("friday.out", "w")

N = int(f_in.read())

# variable "years" represent the current year.
# divide case into leap year and non-leap year
# use for loop to compute N loops
# find day at jan 1st, jan 13th, and dec 31st
days_of_week = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
tracker = {"Mon": 0, "Tue": 0, "Wed": 0, "Thu": 0, "Fri": 0, "Sat": 0, "Sun": 0}

days = 0
for year in range(1900, 1900+N):
    if year % 400 == 0: # leap year
        days += 12
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 29
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 19
    elif year % 100 == 0: # not leap year
        days += 12
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 28
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 19
    elif year % 4 == 0: # leap year
        days += 12
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 29
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 19
    else: # not leap year
        days += 12
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 28
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 31
        tracker[days_of_week[days % 7]] += 1
        days += 30
        tracker[days_of_week[days % 7]] += 1
        days += 19

f_out.write("{} {} {} {} {} {} {}\n".format(tracker["Sat"], tracker["Sun"], tracker["Mon"], tracker["Tue"], tracker["Wed"], tracker["Thu"], tracker["Fri"]))

f_in.close()
f_out.close()

