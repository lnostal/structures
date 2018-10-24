import math

#o = n * math.log2(n)
def getO(n):
    return int(n * math.log2(n))


# формула из курсача
# (1 + 9 + 9 + 4 + log(n)(6 + 17 + 19 + 17 + 19) + 5 + 2 + 4 + 9 + 5 + 2 + 2 + 6 + 17 + 19 + log(n)(4 + 17 + 19))n =  (94 + 80log(n) + 40 log(n))n = (94 + 120log(n))n => nlog(n)

def getF(n):
    return int(n * (94 + 120 * math.log2(n)))

n100 = 123934
n1000 = 1707662
n10000 = 21965118
n22000 = 51966702

print('\nРучное\t\tПрожка\t\tРазница\n')
print('{}\t\t{}\t\t{}'.format(getF(100), n100, getF(100) - n100))
print('{}\t\t{}\t\t{}'.format(getF(1000), n1000, getF(1000) - n1000))
print('{}\t{}\t{}'.format(getF(10000), n10000, getF(10000) - n10000))
print('{}\t{}\t{}\n'.format(getF(22000), n22000, getF(22000) - n22000))

print('F(n)\t\tO(F(n))\t\tT(n) ms\n')
print('{}\t\t{}\t\t{}'.format(getF(100), getO(100), 0))
print('{}\t\t{}\t\t{}'.format(getF(1000), getO(1000), 4))
print('{}\t{}\t\t{}'.format(getF(10000), getO(10000), 46))
print('{}\t{}\t\t{}\n'.format(getF(22000), getO(22000), 110))

