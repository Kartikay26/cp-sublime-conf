import solution

ans1 = solution.solution([0], [3], [
        [0, 7, 0, 0],
        [0, 0, 6, 0],
        [0, 0, 0, 8],
        [9, 0, 0, 0],
    ])

exp1 = 6

ans2 = solution.solution([0, 1], [4, 5], [
        [0, 0, 4, 6, 0, 0],
        [0, 0, 5, 2, 0, 0],
        [0, 0, 0, 0, 4, 4],
        [0, 0, 0, 0, 6, 6],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
    ])

exp2 = 16

def testcase(no,ans,exp):
    if ans == exp:
        print "Testcase #%d passed!" % no
    else:
        print "Testcase #%d failed! Ans, Exp:" % no, ans, exp

testcase(1, ans1, exp1)
testcase(2, ans2, exp2)
