def reverse_str (target):
    target = target[::-1]
    return target


n = int(input())

pw_list = []
for i in range(0, n):
    s = input()
    pw_list.append(s)

password = None
for cur in pw_list:
    rev = reverse_str(cur)
    if rev in pw_list:
        password = cur
        break

if password is not None:
    length = len(password)
    print(length)
    
    mid = int((0 + length) / 2)
    print(password[mid])
