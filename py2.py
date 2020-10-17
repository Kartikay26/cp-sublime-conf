n = int(input())

A = []
for i in range(n):
	A.append([int(x) for x in input().split()])

B = []
for i in range(n):
	B.append([int(x) for x in input().split()])

# The following code could be used if we were using numpy

# import numpy as np
#
# A = np.array(A)
# B = np.array(B)
# C = np.matmul(A, B)
#
# print(C)

# Otherwise, the manual way to multiply matrices is written below:

C = [[0 for i in range(n)] for i in range(n)]

for i in range(n):
	for j in range(n):
		for k in range(n):
			C[i][k] += A[i][j] * B[j][k]

for i, l in enumerate(C):
	for x in l:
		print(x, end=" ")
	print("")