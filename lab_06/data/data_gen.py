import random

counts = [10, 50, 100, 500, 1000]
for count in counts:
    file = open("sorted_" + str(count) + ".txt", "w")
    for i in range(count):
        file.write(chr(69 + i) + "\n")
    file.close()

for count in counts:
    file = open("balanced_" + str(count) + ".txt", "w")
    list = []
    for i in range(count):
        list.append(i)
    file.write(str(int(count / 2)) + "\n")
    list.remove(count / 2)
    random.shuffle(list)
    for i in list:
        file.write(str(i) + "\n")

    file.close()
