'''
from random import randint

x = randint(1, 30)
#change the range if needed
print(x)
'''

# numbers in () can be changed, if it's needed
for i in range(13+1):
    for j in range(13+1):
        x = (6*(i**2 + j**2) + i**2 + j**2 + i + j) % 10
        print(f"w({i},{j}) = {x}")
