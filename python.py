# kartikay26

from math import *
from pprint import *
from sys import *
from collections import *
from itertools import *
from functools import *
from random import *
def getl(t=int): return [t(x) for x in input().split()]
def get(t=int): return t(input())
def debug(*x, **y): print("debug: ", *x, **y)
alphabet = [chr(x) for x in range(ord('a'), ord('z')+1)]
alnum = lambda x: ord(x) - ord('a')

def main():
	n = get()
	s = input()
	ans = 0
	for i in range(n+1):
		for j in range(i-1):
			if check(s[j:i]):
				debug(j,i,s[j:i])
				ans += 1
	print(ans)

def check(s):
	n = len(s)
	palin = []
	for i in range(n+1):
		for j in range(i-1):
			if s[j:i] == s[j:i][::-1]:
				palin.append((j,i))
	def checkp(x):
		for i, j in palin:
			if i <= x < j:
				return True
		return False
	return all(checkp(i) for i in range(n))

if __name__ == "__main__":
	main()
