# Google Foobar - Level 5

Given grid of bools c,

     <---3 to 50--->
^    xxxxxxxxxxxxxxx
3    xxxxxxxxxxxxxxx
to   xxxxxxxxxxxxxxx
9    xxxxxxxxxxxxxxx
v    xxxxxxxxxxxxxxx

and a function
    f(grid) -> smaller grid

count number of possible grids g, so that f(g) = c

f([a b c        [abde bcef
   d e f    =    degh fihe]
   g h i])

abde := (cnt(a,b,d,e) == 1)
