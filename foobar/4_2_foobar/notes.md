# Foobar Challenge

## Level 4, question 2

```sh
foobar:~/ roykartikay.26.03$ status
Current level: 4
Challenges left to complete level: 1

Level 1: 100% [==========================================]
Level 2: 100% [==========================================]
Level 3: 100% [==========================================]
Level 4:  50% [=====================.....................]
Level 5:   0% [..........................................]

Refer a friend: "https://foobar.withgoogle.com/?eid=IQyxV" (Used)
```

## In brief:

### Given:

- Entrances [Int] : Starting point
- Exits [Int]     : Exit points
- Path [[Int]]    : Graph flow constraints

### Constraints:

Nodes upto:        50
Max value of flow: 2e6

### Example 1:

(0)             (1) // source
 | \           / |
 4  --6    -5--  2
 v     \  /      v
(2)<----><----->(3)
 | \           / |
 4  --4    -6--  6
 v     \  /      v
(4)<----><----->(5) // sinks

Ans: 16

### Example 2:

   7
     -> (1)
   /     |
(0)      6      (3)
  ^      v     /  |
  |     (2) ->    |
  |            8  |
  |  9            v
  |----------------

//source ..... sink

Ans: 6

### We have to output:

- Simply total max flow through the graph.

### Plan:

- Study stagndard algo (Edmonds Karp?) and implement and submit.

- Hint: (from Skiena)

What if I have multiple sources and/or sinks? – No problem. We can handle
this by modifying the network to create a vertex to serve as a super-source
that feeds all the sources, and a super-sink that drains all the sinks.


