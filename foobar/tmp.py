# kartikay26

"""
https://codeforces.com/contest/1364/problem/C

Idea:
- whenever MEX increases it means that number was added
- when MEX increases by more than 1 it means the numbers
  in between were previously added
- create "slots" for numbers we do not know, then fill later
  with n+1 or the  numbers that we find later which should
  have come before
"""

def main():
    n = int(input())
    mex = [int(x) for x in input().split()]
    arr = [n+1] * n
    prev_mex = 0
    slots = []
    for i in range(n):
        if mex[i] > prev_mex:
            arr[i] = prev_mex
            nums_to_add = range(prev_mex+1,mex[i])
            for num in nums_to_add:
                if len(slots) == 0:
                    print(-1)
                    return
                slot = slots.pop()
                arr[slot] = num
        else:
            slots.append(i)
        prev_mex = mex[i]

    # print(arr)
    print(" ".join(str(x) for x in arr))

if __name__ == "__main__":
    main()

