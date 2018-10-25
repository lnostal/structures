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

# данные из прожки
data = ({'Nop': (n100, n1000, n10000, n22000),
         'time': (0.33, 3.88, 44.78, 117.13),
         'Fn': (getF(100), getF(1000), getF(10000), getF(22000)),
         'On': (getO(100), getO(1000), getO(10000), getO(22000))})

# вывод всяких табличек
print('\nРучное\t\tПрожка\t\tРазница\n')
for i in range(0, 4):
    if i < 2:
        print('{}\t\t{}\t\t{}'.format(data['Fn'][i], data['Nop'][i], data['Fn'][i] - data['Nop'][i]))
    else:
        print('{}\t{}\t{}'.format(data['Fn'][i], data['Nop'][i], data['Fn'][i] - data['Nop'][i]))

print('\n\nF(n)\t\tO(F(n))\t\tT(n) ms\t\tNop\n')
for i in range(0, 4):
    if i < 2:
        print('{}\t\t{}\t\t{}\t\t{}'.format(data['Fn'][i], data['On'][i], data['time'][i], data['Nop'][i]))
    else:
        print('{}\t{}\t\t{}\t\t{}'.format(data['Fn'][i], data['On'][i], data['time'][i], data['Nop'][i]))

# расчет всяких Ci для графиков
print('\n\nC1\t\t\tC2\t\t\tC3\t\t\tC4')
print('T(n)/F(n)\t\tT(n)/O(F(n))\t\tNop/T(n)\t\tNop/O(F(n))\n')
for i in range(0, 4):
    print('{}\t{}\t{}\t{}'.format(data['time'][i]/data['Fn'][i],
                                  data['time'][i]/data['On'][i],
                                  data['Nop'][i]/data['time'][i],
                                  data['Nop'][i]/data['On'][i]))
