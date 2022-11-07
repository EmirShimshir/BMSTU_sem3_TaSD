from random import *

count = 10

file = open("in.txt", "w")

file.write("1\n")
file.write(str(count) + "\n")

for i in range(count):
    file.write(str(randint(0, 10)) + "\n")

file.write("0\n")

file.close()