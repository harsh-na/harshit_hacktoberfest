a=int(input('Enter the 1st number :'))
b=int(input('Enter the 2nd number :'))
def gcd(a,b):
    if a==0:
        return b
    else:
        return gcd(b%a,a)
def lcm(a,b):
	return (a / gcd(a,b))* b
print('LCM of', a, 'and', b, 'is', lcm(a, b))
