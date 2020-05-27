
def binary_search (target, data):
    left = 0
    right = len(data) - 1

    while left <= right:
        mid = int((left + right) / 2)
        if data[mid] == target:
            return target
        elif data[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return None


input_list = input()
input_list = input_list.split(" ")

n = int(input_list[0])
m = int(input_list[1])

listen_list = []
see_list = []

for i in range(0, n):
    s = input()
    listen_list.append(s)

for i in range(0, m):
    s = input()
    see_list.append(s)

listen_list.sort()
see_list.sort()

both_of_list = []
for name in listen_list:
    result = binary_search(name, see_list)

    if result is None:
        continue
    both_of_list.append(result)

print(len(both_of_list))
for name in both_of_list:
    print(name)