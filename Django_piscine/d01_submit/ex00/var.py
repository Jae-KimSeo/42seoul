#!/usr/bin/python3

def my_var():
       print('42 has a type ', type(42))
       print('42 has a type ', type('42'))
       print('quarante-deux has a type ', type("quarante-deux"))
       print('42.0 has a type ', type(42.0))
       print('True has a type ', type(True))
       print('[42] has a type ', type([42]))
       print('{42 : 42} has a type', type({42: 42}))
       print('(42, ) has a type', type((42, )))
       print('set() has a type', type(set()))

if __name__ == '__main__':
    my_var()