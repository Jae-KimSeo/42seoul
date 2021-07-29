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
    input = sys.argv[1]
    if len(sys.argv) != 2:
        sys.exit()
    s_result = s.get(input)
    if s_result == None :
        print("Unknown state")
    else :
        c_result = c.get(s_result)
        print(c_result)
        

if __name__ == '__main__':
    search_cap()
