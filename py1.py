n, m = [int(x) for x in input().split()]

l = [int(x) for x in input().split()]

A = set([int(x) for x in input().split()])
B = set([int(x) for x in input().split()])

ans = 0

for i in l:
	if i in A:
		ans += 1
	if i in B:
		ans -= 1

print(ans)