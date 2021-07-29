#!/usr/bin/python3

f = open('numbers.txt', 'r')
res = f.read()
print(res)

res = res.split(',')
print(res)
for i in res:
    print(i)
