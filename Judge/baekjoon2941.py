
def match_sub_to_str (s, s_list):
    for comp in s_list:
        if comp in s:
            return comp
    return None


def extract_sub_str (sub, s):
    start = s.index(sub)
    left = s[:start]
    right = s[start+len(sub):]
    return left + " " + right


special_list = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

input_str = input()

cnt = 0

while True:
    sub = match_sub_to_str(input_str, special_list)

    if sub is None:
        break

    cnt += 1
    input_str = extract_sub_str(sub, input_str)

input_str = input_str.replace(" ", "")
answer = cnt + len(input_str)

print(answer)


