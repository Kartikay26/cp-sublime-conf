# checker.py

## automated testing for competitive algos

# automatically generates test cases
# and compare outputs of your solution
# with a brute force soln

##############################################################

# Write code here:

programA = './a.out'
programB = 'python3 python.py'

N_tests = 10

def generate_test():
	n = randint(1,5)
	print(n)
	for i in range(n):
		print(choice(['A','B']), end='')
	print()

def check_answer(ansa, ansb, hint):
	return ansa == ansb

##############################################################

import sys
from math import *
from pprint import *
from collections import *
from itertools import *
from functools import *
from random import *
from io import StringIO
from subprocess import run
def getl(t=int): return [t(x) for x in input().split()]
def get(t=int): return t(input())
alphabet = [chr(x) for x in range(ord('a'), ord('z')+1)]
alnum = lambda x: ord(x) - ord('a')

def main():
	old_stdout = sys.stdout
	failing_tests = set()
	print("Testing: ")
	for i in range(N_tests):
		# generate a test
		sys.stdout = StringIO()
		hint = generate_test()
		test = sys.stdout.getvalue()
		sys.stdout = old_stdout
		
		# run both programs on the test input
		A = run(programA.split(), input=test.encode(),
				capture_output=True).stdout.decode().strip()
		A_lines = A.splitlines()
		A = "\n".join(line for line in A_lines if not line.startswith("debug"))
		B = run(programB.split(), input=test.encode(),
				capture_output=True).stdout.decode().strip()
		B_lines = B.splitlines()
		B = "\n".join(line for line in B_lines if not line.startswith("debug"))

		if not check_answer(A, B, hint):
			failing_tests.update([(test, hint, A, B)])
			print("x",end="")
		else:
			print(".",end="")
		if i % 50 == 49:
			print()
		sys.stdout.flush()
	print("\n")

	failing_tests = sorted(failing_tests, key=lambda test: len(test[0]))

	print(f"{N_tests - len(failing_tests)} / {N_tests} passed. [{(N_tests - len(failing_tests)) * 100 // N_tests} %]\n")
	if len(failing_tests) > 0:
		print("Failing tests:\n")
		for i, (test, hint, A, B) in enumerate(failing_tests):
			if hint is not None:
				print(f"Test #{i+1}:\n{test}\n(hint: {hint})\nOutput A:\t{A}\nOutput B:\t{B}")
			else:
				print(f"Test #{i+1}:\n{test}\nOutput A:\t{A}\nOutput B:\t{B}")
			print("-"*80)

if __name__ == '__main__':
	main()