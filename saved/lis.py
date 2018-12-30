# LONGEST INCREASING SUBSEQUENCE
# ===============================

vec = [9, 4, 7, 5, 1, 6, 0, 10]

n = len(vec)

dp = [(0,0)]*n # return: lis(i) length, max_el.

for i in range(n):
	mx = (1, vec[i])
	for j in range(i):
		if vec[i]>dp[j][1]:
			mx = max(mx, (dp[j][0]+1, vec[i]))
	dp[i] = mx

print "LIS Length: ", dp[n-1][0]

# With DP pointers

dp = [(0,0,0)]*n # return: lis(i) length, max_el, dp pointer

for i in range(n):
	mx = (1, vec[i], i)
	for j in range(i):
		if vec[i]>dp[j][1]:
			mx = max(mx, (dp[j][0]+1, vec[i], j))
	dp[i] = mx

print "LIS:",
i = n-1
sq = []
while True:
	sq.append(i)
	if i == dp[i][2]:
		break
	i = dp[i][2]
sq.reverse()
print [vec[i] for i in sq]