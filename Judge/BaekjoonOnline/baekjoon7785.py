
entrance_list = {}
target_list = []

n = int(input())

for i in range(0, n):
    key, val = input().split(' ')
    entrance_list[key] = val

for key in entrance_list.keys():
    if entrance_list[key] == 'enter':
        target_list.append(key)

target_list.sort(reverse=True)

for val in target_list:
    print(val)
