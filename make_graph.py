def getl():
	return map(int, input().split())

n, m = getl()
print("digraph G{")
for i in range(m):
	a, b = getl()
	print(f"\t{a} -> {b};")
print("}")
