# Google Foobar

## Level 4 - Running with the bunnies

The problem in short:

    - We are given a matrix representing weights in a graph,
    - and a 'time limit' T
    - There are no more than 7 nodes.
    - There is a start node and an end node.
    - We want to reach from the start node to the end node, while
        - visiting maximum number of nodes in total
        - sum of all weights should be <= T

Let's try DP in the style of Errichto!

- Attempt 1:
    state:
        (i)   current position // 7
        (ii)  (bitmask) nodes that we have visited // 2^5 = 32

    int total_sum[pos][vis]
    -- start with total_sum[start][000..] = 0
    -- transitions are there for each graph edge, choose min total_sum
    -- Answer will be
    --    argmax_vis(
    --        num_nodes(x) for vis in all_vis
    --        where total_sum[end][vis] <= T)

    let's try a dry run

    total_sum

         000   001   010   011   100   101   110   111
    s     0    inf   inf   inf   inf   inf   inf   inf
    0    inf   inf   inf   inf    2    inf   inf   inf
    1    inf   inf    2    inf   inf   inf   inf   inf
    2    inf    2    inf   inf   inf   inf   inf   inf
    e    -1    inf   inf   inf   inf   inf   inf   inf


    -- PROBLEM! order?
    -- ANOTHER PROBLEM: We have to choose one with most visits!
        otherwise that -1 there at e is stuck!
    -- try adding time to state?


- Attempt 2:

    state:
        (i)   current position // 7
        (ii)  (bitmask) nodes that we have visited // 2^5 = 32
        (iii) total sum so far // 1000+?

    value:
        -> number of nodes visited

    let's try the dry run ... in a spreadsheet

    algo should be somewhat like this

    bool possible[pos][vis][time];

    -- start with possible[s][000][0] = 1, rest all 0
    -- transitions acc to graph edges, apply bfs?
    -- finally answer should be 
        highest num(vis) of all vis
            for which possible[e][vis][time] is true for any time >= 0
