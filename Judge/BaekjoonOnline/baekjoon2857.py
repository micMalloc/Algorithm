
count = 0
list = []

for i in range(1, 6):
    s = input();
    list.append(s)

for i in range(1, 6):
    if list[i - 1].__contains__('FBI'):
        print(i)
        count += 1

if count == 0:
    print("HE GOT AWAY!")