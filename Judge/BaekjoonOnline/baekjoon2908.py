
data = input()

data_list = data.split(" ")

a = int(data_list[0][::-1])
b = int(data_list[1][::-1])

if a > b:
    print(a)
else:
    print(b)

