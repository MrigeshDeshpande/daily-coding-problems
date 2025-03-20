from math import gcd
from functools import reduce

# Function to calculate GCD of a list
def gcd_list(numbers):
    return reduce(gcd, numbers)

# Input
n, k = map(int, input().split())  # Number of denominations, base of the system
a = list(map(int, input().split()))  # Denominations of banknotes

# Calculate the GCD of all the denominations modulo k
g = gcd_list([x % k for x in a])

# Collect all valid values of d
result = []
for d in range(0, k, g):  # Possible values are multiples of GCD within range
    result.append(d)

# Output the results
print(len(result))
print(" ".join(map(str, result)))
