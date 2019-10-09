class Permutation():
	"""permutation of list of integers, 0-based indexing"""
	def __init__(self, p: list):
		self.n = len(p)
		self.p = p
	def apply(self, other_list):
		"""Applies current permutation to other list and returns new list"""
		ans = []
		for i in self.p:
			ans.append( other_list[i] )
		return ans
	def inv(self):
		"""returns inverse of current permutation"""
		ans = [0]*self.n
		for i,x in enumerate(self.p):
			ans[x] = i
		return ans
	def cycles(self):
		# returns list of cycles in itself, as pairs of swaps
		ans = []
		vis = [False] * self.n
		for i,x in enumerate(self.p):
			if vis[i]:
				continue
			else:
				vis[i] = True
			new_cycle = []
			ptr = i
			while True:
				vis[ptr] = True
				new_cycle += [(ptr, self.p[ptr])]
				ptr = self.p[ptr]
				if ptr == i:
					break
			ans += [new_cycle]
		return ans
	def __str__(self):
		return str(self.p)