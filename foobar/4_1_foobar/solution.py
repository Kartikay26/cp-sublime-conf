from collections import defaultdict, deque

graph = []
time_limit = 0
N = 0

def solution(g, T):
    global graph, time_limit, N
    graph = g
    time_limit = T
    N = len(g)
    # apply a bfs and mark possible elements
    visited = set()
    # start with only node (pos=start, vis=000, time=T)
    queue = deque([(0, 0, T)])
    visited.add((0, 0, T))
    i = 0
    while len(queue) > 0:
        cur_node = queue.popleft()
        #print(cur_node)
        for child in children(cur_node):
            if child not in visited:
                visited.add(child)
                queue.append(child)
        i += 1
    max_val, max_vis = 0, 0
    for node in visited:
        (pos, vis, time) = node
        if pos == N-1 and time >= 0:
            val = count_bits(vis)
            if val > max_val:
                max_vis = vis
                max_val = val
            elif val == max_val:
                max_vis = min(vis, max_vis)
                max_val = val
    ans = []
    for i in range(N):
        if max_vis & (2**i):
            ans.append(i)
    #print(ans)
    return ans

def children(node):
    (pos, vis, time) = node
    new_nodes = []
    for i in range(N):
        if i != 0 and i != N-1:
            new_vis = vis | (2**(i-1))
        else:
            new_vis = vis
        new_time = time - graph[pos][i]
        new_node = (i, new_vis, new_time)
        if new_time >= -2000 and new_time <= 2000:
            new_nodes.append(new_node)
    return new_nodes

def count_bits(num):
    i = num
    a = 0
    while i:
        a += (i & 1)
        i //= 2
    return a

