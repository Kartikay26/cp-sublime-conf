# 0-1 KNAPSACK PROBLEM
# ======================

weight = [1,2,4,2,5]
values = [5,3,5,3,2]
#         0 1 2 3 4

n = 5

max_wt = 10

max_val = 0

# make each coice and check wt/val

# 5**5 operations, all permutations including repeats

for x in range(n):
	for y in range(n):
		for z in range(n):
			for a in range(n):
				for b in range(n):
					# convert permutation to subset
					choice = set([x,y,z,a,b])
					value = sum(values[i] for i in choice)
					wt = sum(weight[i] for i in choice)
					if wt <= max_wt:
						max_val = max(max_val, value)

print "max val given wt = %d is %d"%(max_wt, max_val)

# generate subsets properly

chosen_wt_0 = 0
chosen_val_0 = 0
max_val = 0

# 2**5 operations, all subsets only

for x1 in [0,1]:
	if x1:
		chosen_wt_1 = weight[0] + chosen_wt_0
		chosen_val_1 = values[0] + chosen_val_0
	else:
		chosen_wt_1 = chosen_wt_0
		chosen_val_1 = chosen_val_0
	for x2 in [0,1]:
		if x2:
			chosen_wt_2 = weight[1] + chosen_wt_1
			chosen_val_2 = values[1] + chosen_val_1
		else:
			chosen_wt_2 = chosen_wt_1
			chosen_val_2 = chosen_val_1
		for x3 in [0,1]:
			if x3:
				chosen_wt_3 = weight[2] + chosen_wt_2
				chosen_val_3 = values[2] + chosen_val_2
			else:
				chosen_wt_3 = chosen_wt_2
				chosen_val_3 = chosen_val_2
			for x4 in [0,1]:
				if x4:
					chosen_wt_4 = weight[3] + chosen_wt_3
					chosen_val_4 = values[3] + chosen_val_3
				else:
					chosen_wt_4 = chosen_wt_3
					chosen_val_4 = chosen_val_3
				for x5 in [0,1]:
					if x5:
						chosen_wt_5 = weight[4] + chosen_wt_4
						chosen_val_5 = values[4] + chosen_val_4
					else:
						chosen_wt_5 = chosen_wt_4
						chosen_val_5 = chosen_val_4
					if chosen_wt_5 <= max_wt:
						max_val = max(max_val, chosen_val_5)

print "max val given wt = %d is %d"%(max_wt, max_val)

# recursive, generates 2**n subsets in 2**n operations

def gen_subsets(lst, index=-2, prev_set=tuple()):
	if index==-1:
		return
	if index==-2:
		yield prev_set
		index = len(lst)-1
	sst_1 = prev_set
	sst_2 = prev_set + (lst[index],)
	yield sst_2
	for x in gen_subsets(lst, index-1, sst_1):
		yield x
	for x in gen_subsets(lst, index-1, sst_2):
		yield x

max_val = 0

for sst in gen_subsets(range(n)):
	# print sst
	chosen_wt = sum(weight[i] for i in sst)
	chosen_val = sum(values[i] for i in sst)
	if chosen_wt <= max_wt:
		max_val = max(max_val, chosen_val)

print "max val given wt = %d is %d"%(max_wt, max_val)

# direct recursive

def func(index=n-1, prev_wt = 0, prev_val = 0):
	if index==-1:
		return prev_val if prev_wt <= max_wt else 0
	return max(func(index-1, prev_wt, prev_val), func(index-1, prev_wt + weight[index], prev_val + values[index]))

print "max val given wt = %d is %d"%(max_wt, func())

# memoizable recursive

def knapsack(i=n-1, wt_allowed = max_wt):
	if i==-1:
		return 0
	return max(knapsack(i-1, wt_allowed),(knapsack(i-1, wt_allowed-weight[i])+values[i] if wt_allowed-weight[i]>=0 else 0))

print "max val given wt = %d is %d"%(max_wt, knapsack())

# direct bottom up DP

dp = [[0]*max_wt for i in range(n+1)]

for i in range(1,n+1):
	for w in range(max_wt):
		dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i-1]] + values[i-1] if w-weight[i-1]>=0 else 0)

# for x in dp:
# 	print x

print "max val given wt = %d is %d"%(max_wt, dp[n][max_wt-1])