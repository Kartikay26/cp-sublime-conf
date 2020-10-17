from collections import deque

"""
Solves problem using Edmonds-Karp in O(V*E^2) == O(N^3)

Idea of the Edmonds-Karp algo:
+-- max flow = 0
|   while True:
|   |   start from source, find path to sink that still has remaining capacity
|   |   if no such path:
|   |   |   break
|   |   max flow += bottleneck of this path
|   |   augment the path and the reverse path too
+----------------------------------------------------------------------

We will let node [0,N) be the graph nodes as given,
the node N be the "super-source"
and node N+1 be "super-sink"
"""

def solution(sources, sinks, graph):

    # Initialise some variables
    inf = 1e9           # infinity
    n = len(graph) + 2  # no of nodes in full flow graph
    s = n-2             # super source
    t = n-1             # super sink

    # Set up new graph with super source and sink
    
    capacity = [[0]*n for i in range(n)]
    flow = [[0]*n for i in range(n)]

    for i in range(n-2):
        for j in range(n-2):
            capacity[i][j] = graph[i][j]
    for ss in sources:
        capacity[s][ss] = inf
    for tt in sinks:
        capacity[tt][t] = inf

    def findMaxFlow():
        # Edmonds-Karp algorithm

        max_flow = 0 # will store the answer

        while True:
            # find a path from s to t which has remaining capacity
            path = bfs()
            if not path:
                break

            # bottleneck = min(capacity in path)
            bottleneck = min(capacity[i][j] for i,j in zip(path, path[1:]))
            max_flow += bottleneck

            # augment path
            for i,j in zip(path, path[1:]):
                added_flow = bottleneck - flow[i][j]
                flow[i][j] += added_flow
                flow[j][i] -= added_flow

        return max_flow

    def bfs():
        q = deque([s])
        parent = [-1] * n
        while len(q) > 0:
            i = q.popleft()
            if i == t:
                # reached the end, return path
                path = [t]
                node = t
                while node != s:
                    node = parent[node]
                    path.append(node)
                path.reverse()
                return path
            for j in range(n):
                if capacity[i][j] > flow[i][j] and parent[j] == -1:
                    q.append(j)
                    parent[j] = i

    return findMaxFlow()
