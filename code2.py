# THE COUNT AND SAY SEQUENCE
# Carot Labs Coding Assesment No. 2
# Submitted by: Kumar Kartikay, NIT Hamirpur
# Language: Python 3
# ===========================================

# INPUT: A number N upto 30
# Sample input: 5

# OUTPUT: The Nth term of the count-and-say sequence.
# Sample output: 111221

def main():
	n = int(input())
	seq = "1"
	for i in range(n-1):
		seq = count_and_say(seq)
	print(seq)

# this function returns the next element of the sequence given the previous one
# `seq` is given as string

def count_and_say(seq):
	nums = []
	counts = []
	for cur_num in seq:
		if nums and nums[-1] == cur_num:
			counts[-1] += 1
		else:
			nums.append(cur_num)
			counts.append(1)
	ans = ""
	for num, count in zip(nums, counts):
		ans += str(count) + num
	return ans

# ===========================================

if __name__ == '__main__':
	main()