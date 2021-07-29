#!/usr/bin/python3

import sys 

def search_cap():
    states = {
"Oregon" : "OR",
"Alabama" : "AL",
"New Jersey": "NJ",
"Colorado" : "CO"
}
    capital_cities = {
"OR": "Salem",
"AL": "Montgomery",
"NJ": "Trenton",
"CO": "Denver"
}
    s = dict(states)
    c = dict(capital_cities)
    if len(sys.argv) != 2:
        sys.exit()
    input = sys.argv[1]
    c_result = None
    for key, value in c.items():
        if value == input:
            c_result = key
    if c_result == None:
        print("Unknown captial city")
    for key, value in s.items():
        if value == c_result :
            print(key)


if __name__ == '__main__':
    search_cap()
