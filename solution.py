def brute_force(n, k):
    # this means count number of staircase combinations where n blocks are given
    # and max number we're allowed to use is k
    if n < 3:
        return 1 if n <= k else 0
    cur_sum = 0
    for i in range(1,n+1):
        if i <= k:
            cur_sum += dp_soln(n-i, i-1) # for i and combs(n-i, i-1)
    return cur_sum

def memoize(func):
    dp = {}
    def ret(*args):
        if tuple(args) not in dp:
            dp[tuple(args)] = func(*args)
        # print(args, "->", dp[tuple(args)])
        return dp[tuple(args)]
    return ret

dp_soln = memoize(brute_force)

def solution(n):
    return dp_soln(n, n) - 1

