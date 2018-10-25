
file = input()
target = input()

length = len(target)

cnt = 0

while True:
    if target not in file:
        break
    idx = file.index(target)
    file = file[idx + length:]
    cnt += 1

print(cnt)
