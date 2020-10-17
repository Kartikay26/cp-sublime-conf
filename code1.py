# LONGEST PALINDROMIC SUBSTRING
# Carot Labs Coding Assesment No. 1
# Submitted by: Kumar Kartikay, NIT Hamirpur
# Language: Python 3
# ===========================================

# INPUT: A string s upto length 1000
# Sample input: abababbaba

# OUTPUT: The longest palindromic substring of s
# Sample output: ababbaba

def main():
	s = input()

	# first we will insert '#' in between every character
	# to make any possible palindrome of odd length
	new_s = ['#']
	for c in s:
		new_s.append(c)
		new_s.append('#')

	# now we will start from each position and
	# try to find the longest palindrome with
	# that position at the center and store the lengths
	n = len(new_s)
	longest_palindrome_len = [0] * n
	for i in range(n):
		j = 0
		while (i - j >= 0) and (i + j < n):
			if new_s[i-j] == new_s[i+j]:
				# palindrome found
				longest_palindrome_len[i] = j
			else:
				break
			j += 1

	# now just find the longest palindrome and print it
	max_len = max(longest_palindrome_len)
	max_len_idx = longest_palindrome_len.index(max_len)
	i,j = max_len_idx - max_len,  max_len_idx + max_len
	ans = "".join(c for c in new_s[i:j+1] if c != "#")

	print(ans)


# ===========================================

if __name__ == '__main__':
	main()
