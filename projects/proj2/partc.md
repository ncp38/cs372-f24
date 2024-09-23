---
title: Project 2 - Part C Details
nav_exclude: true
---

# Project 2: Connect Four: Part C Details

## General information

Because Part C uses a cut-off depth and heuristics, the computer player may not 
win all the time even when it can. For instance, in the full version of Connect Four, 
with 6 rows and 7 columns, the first player has a guaranteed win. Your program does not need 
to win all the time when asked to play on this size board, particularly if the cut-off depth  
is small. That being said, for a reasonably good heuristic, I find that my computer 
player can beat me most of the time if I let it look ahead even five moves. It will 
certainly prevent me from winning, though we may tie sometimes.

My heuristic  is 10 points for each 3-in-a-row found in the game board, 
and 3 points for each 2-in-a-row. Points are positive for MAX and negative 
for MIN.  
Note that this heuristic 
doesn't even look for open spaces on the ends of the 3-in-a-rows or 2-in-a-rows, so it will make dumb moves every so often.
This heuristic is used for all non-terminal states; terminal states still
use the utility function defined in Part A.

## Output

Here is an example of how the program for Part C might look. 
Your output should include the same information (minimax values, number of prunings, 
optimal moves, size of the transposition table), but the formatting does not have to match exactly,
and **unlike in Parts A and B, the numbers will not necessarily match,** because everyone's search 
heuristic will be different.

```
Run part A, B, or C? c
Include debugging info? (y/n) n
Enter rows: 6
Enter columns: 7
Enter number in a row to win: 4
Number of moves to look ahead (depth): 5
Who plays first? 1=human, 2=computer: 2

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
0 1 2 3 4 5 6 
Search completed in 0.016 seconds.
Transposition table has 885 states.
Minimax value for this state: 13, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
X . . . . . . 
0 1 2 3 4 5 6 
Search completed in 0.002 seconds.
Transposition table has 237 states.
Minimax value for this state: 0, optimal move: 0
It is MIN's turn!
Enter move: 3

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
X . . O . . . 
0 1 2 3 4 5 6 
Search completed in 0.006 seconds.
Transposition table has 769 states.
Minimax value for this state: 16, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
X . . . . . . 
X . . O . . . 
0 1 2 3 4 5 6 
Search completed in 0.001 seconds.
Transposition table has 284 states.
Minimax value for this state: 3, optimal move: 0
It is MIN's turn!
Enter move: 4

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
X . . . . . . 
X . . O O . . 
0 1 2 3 4 5 6 
Search completed in 0.003 seconds.
Transposition table has 233 states.
Minimax value for this state: 43, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . . . . . 
. . . . . . . 
. . . . . . . 
X . . . . . . 
X . . . . . . 
X . . O O . . 
0 1 2 3 4 5 6 
Search completed in 0.005 seconds.
Transposition table has 567 states.
Minimax value for this state: -3, optimal move: 0
It is MIN's turn!
Enter move: 0

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . . . . 
X . . . . . . 
X . . O O . . 
0 1 2 3 4 5 6 
Search completed in 0.008 seconds.
Transposition table has 1250 states.
Minimax value for this state: 23, optimal move: 5
It is MAX's turn!
Computer chooses move: 5

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . . . . 
X . . . . . . 
X . . O O X . 
0 1 2 3 4 5 6 
Search completed in 0.007 seconds.
Transposition table has 1303 states.
Minimax value for this state: -26, optimal move: 3
It is MIN's turn!
Enter move: 4

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . . . . 
X . . . O . . 
X . . O O X . 
0 1 2 3 4 5 6 
Search completed in 0.009 seconds.
Transposition table has 1659 states.
Minimax value for this state: 0, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . . . . 
X . . . O . . 
X X . O O X . 
0 1 2 3 4 5 6 
Search completed in 0.006 seconds.
Transposition table has 1547 states.
Minimax value for this state: -33, optimal move: 3
It is MIN's turn!
Enter move: 5

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . . . . 
X . . . O O . 
X X . O O X . 
0 1 2 3 4 5 6 
Search completed in 0.005 seconds.
Transposition table has 1273 states.
Minimax value for this state: 7, optimal move: 4
It is MAX's turn!
Computer chooses move: 4

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . X . . 
X . . . O O . 
X X . O O X . 
0 1 2 3 4 5 6 
Search completed in 0.003 seconds.
Transposition table has 1181 states.
Minimax value for this state: -43, optimal move: 3
It is MIN's turn!
Enter move: 5

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . X O . 
X . . . O O . 
X X . O O X . 
0 1 2 3 4 5 6 
Search completed in 0.008 seconds.
Transposition table has 1509 states.
Minimax value for this state: -10, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . X O . 
X X . . O O . 
X X . O O X . 
0 1 2 3 4 5 6 
Search completed in 0.004 seconds.
Transposition table has 1288 states.
Minimax value for this state: -40, optimal move: 5
It is MIN's turn!
Enter move: 6

. . . . . . . 
. . . . . . . 
O . . . . . . 
X . . . X O . 
X X . . O O . 
X X . O O X O 
0 1 2 3 4 5 6 
Search completed in 0.002 seconds.
Transposition table has 930 states.
Minimax value for this state: 73, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

. . . . . . . 
. . . . . . . 
O . . . . . . 
X X . . X O . 
X X . . O O . 
X X . O O X O 
0 1 2 3 4 5 6 
Search completed in 0.001 seconds.
Transposition table has 594 states.
Minimax value for this state: 0, optimal move: 1
It is MIN's turn!
Enter move: 1

. . . . . . . 
. . . . . . . 
O O . . . . . 
X X . . X O . 
X X . . O O . 
X X . O O X O 
0 1 2 3 4 5 6 
Search completed in 0.004 seconds.
Transposition table has 1357 states.
Minimax value for this state: 43, optimal move: 3
It is MAX's turn!
Computer chooses move: 3

. . . . . . . 
. . . . . . . 
O O . . . . . 
X X . . X O . 
X X . X O O . 
X X . O O X O 
0 1 2 3 4 5 6 
Search completed in 0.003 seconds.
Transposition table has 1146 states.
Minimax value for this state: 20, optimal move: 5
It is MIN's turn!
Enter move: 6

. . . . . . . 
. . . . . . . 
O O . . . . . 
X X . . X O . 
X X . X O O O 
X X . O O X O 
0 1 2 3 4 5 6 
Search completed in 0.003 seconds.
Transposition table has 760 states.
Minimax value for this state: 20000, optimal move: 2
It is MAX's turn!
Computer chooses move: 2

. . . . . . . 
. . . . . . . 
O O . . . . . 
X X . . X O . 
X X . X O O O 
X X X O O X O 
0 1 2 3 4 5 6 
Search completed in 0.002 seconds.
Transposition table has 632 states.
Minimax value for this state: 20000, optimal move: 0
It is MIN's turn!
Enter move: 5

. . . . . . . 
. . . . . . . 
O O . . . O . 
X X . . X O . 
X X . X O O O 
X X X O O X O 
0 1 2 3 4 5 6 
Search completed in 0.001 seconds.
Transposition table has 450 states.
Minimax value for this state: 20000, optimal move: 2
It is MAX's turn!
Computer chooses move: 2
Game over!
. . . . . . . 
. . . . . . . 
O O . . . O . 
X X . . X O . 
X X X X O O O 
X X X O O X O 
0 1 2 3 4 5 6 
The winner is MAX (computer)
Play again? (y/n): n
```

Here is an interesting case.  For my (not that great) heuristic, the first time
the true optimal first move for MAX is found by alpha-beta is with a look-ahead
depth of 10 (moving in the center column).  However, it is interesting that the 
heuristic stays positive for a while, with optimal play on both sides,
suggesting that alpha-beta thinks that MAX
(the computer will win), then it abruptly switches to a very negative number, 
indicating a guaranteed win for MIN (the human), and this is how the end of the
game plays out.

I believe this is due to the fact that my heuristic awards points for 3-in-a-rows
and 2-in-a-rows even with no empty spots on one or both ends, and I think the algorithm
tries to make some of these vertically towards the top of the board, not realizing
that they will not be able to be completed into a 4-in-a-row because it will run
out of space at the top.  And then it searches deeply enough and stumbles into
a situation where MIN has a guaranteed win (not a coincidence that it realizes
this exactly ten moves before the end of the game).  I believe this could be fixed with
a better heuristic.

```
Run part A, B, or C? c
Include debugging info? (y/n) n
Enter rows: 6
Enter columns: 7
Enter number in a row to win: 4
Number of moves to look ahead (depth): 10
Who plays first? 1=human, 2=computer: 2

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
0 1 2 3 4 5 6 
Search completed in 1.503 seconds.
Transposition table has 195754 states.
Minimax value for this state: 6, optimal move: 3
It is MAX's turn!
Computer chooses move: 3

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . X . . . 
0 1 2 3 4 5 6 
Search completed in 4.458 seconds.
Transposition table has 321548 states.
Minimax value for this state: 39, optimal move: 2
It is MIN's turn!
Enter move: 2

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . O X . . . 
0 1 2 3 4 5 6 
Search completed in 3.618 seconds.
Transposition table has 279593 states.
Minimax value for this state: 13, optimal move: 4
It is MAX's turn!
Computer chooses move: 4

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . O X X . . 
0 1 2 3 4 5 6 
Search completed in 25.72 seconds.
Transposition table has 770610 states.
Minimax value for this state: 36, optimal move: 3
It is MIN's turn!
Enter move: 3

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . O . . . 
. . O X X . . 
0 1 2 3 4 5 6 
Search completed in 12.227 seconds.
Transposition table has 498681 states.
Minimax value for this state: 3, optimal move: 3
It is MAX's turn!
Computer chooses move: 3

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . X . . . 
. . . O . . . 
. . O X X . . 
0 1 2 3 4 5 6 
Search completed in 19.071 seconds.
Transposition table has 666834 states.
Minimax value for this state: 40, optimal move: 5
It is MIN's turn!
Enter move: 5

. . . . . . . 
. . . . . . . 
. . . . . . . 
. . . X . . . 
. . . O . . . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 3.245 seconds.
Transposition table has 386124 states.
Minimax value for this state: 3, optimal move: 3
It is MAX's turn!
Computer chooses move: 3

. . . . . . . 
. . . . . . . 
. . . X . . . 
. . . X . . . 
. . . O . . . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 2.453 seconds.
Transposition table has 337936 states.
Minimax value for this state: 33, optimal move: 4
It is MIN's turn!
Enter move: 4

. . . . . . . 
. . . . . . . 
. . . X . . . 
. . . X . . . 
. . . O O . . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 3.13 seconds.
Transposition table has 293746 states.
Minimax value for this state: 10, optimal move: 5
It is MAX's turn!
Computer chooses move: 5

. . . . . . . 
. . . . . . . 
. . . X . . . 
. . . X . . . 
. . . O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 3.031 seconds.
Transposition table has 328794 states.
Minimax value for this state: 56, optimal move: 4
It is MIN's turn!
Enter move: 4

. . . . . . . 
. . . . . . . 
. . . X . . . 
. . . X O . . 
. . . O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 1.929 seconds.
Transposition table has 206633 states.
Minimax value for this state: 33, optimal move: 4
It is MAX's turn!
Computer chooses move: 4

. . . . . . . 
. . . . . . . 
. . . X X . . 
. . . X O . . 
. . . O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.855 seconds.
Transposition table has 146446 states.
Minimax value for this state: 56, optimal move: 2
It is MIN's turn!
Enter move: 2

. . . . . . . 
. . . . . . . 
. . . X X . . 
. . . X O . . 
. . O O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.433 seconds.
Transposition table has 81484 states.
Minimax value for this state: 30, optimal move: 3
It is MAX's turn!
Computer chooses move: 3

. . . . . . . 
. . . X . . . 
. . . X X . . 
. . . X O . . 
. . O O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.216 seconds.
Transposition table has 56431 states.
Minimax value for this state: 63, optimal move: 3
It is MIN's turn!
Enter move: 3

. . . O . . . 
. . . X . . . 
. . . X X . . 
. . . X O . . 
. . O O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.138 seconds.
Transposition table has 37882 states.
Minimax value for this state: 40, optimal move: 2
It is MAX's turn!
Computer chooses move: 2

. . . O . . . 
. . . X . . . 
. . . X X . . 
. . X X O . . 
. . O O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.144 seconds.
Transposition table has 37487 states.
Minimax value for this state: 63, optimal move: 2
It is MIN's turn!
Enter move: 2

. . . O . . . 
. . . X . . . 
. . O X X . . 
. . X X O . . 
. . O O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.093 seconds.
Transposition table has 28480 states.
Minimax value for this state: 37, optimal move: 4
It is MAX's turn!
Computer chooses move: 4

. . . O . . . 
. . . X X . . 
. . O X X . . 
. . X X O . . 
. . O O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.045 seconds.
Transposition table has 17381 states.
Minimax value for this state: 63, optimal move: 4
It is MIN's turn!
Enter move: 4

. . . O O . . 
. . . X X . . 
. . O X X . . 
. . X X O . . 
. . O O O X . 
. . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.019 seconds.
Transposition table has 8003 states.
Minimax value for this state: 40, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . O O . . 
. . . X X . . 
. . O X X . . 
. . X X O . . 
. . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.012 seconds.
Transposition table has 5552 states.
Minimax value for this state: 63, optimal move: 0
It is MIN's turn!
Enter move: 0

. . . O O . . 
. . . X X . . 
. . O X X . . 
. . X X O . . 
O . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.012 seconds.
Transposition table has 4886 states.
Minimax value for this state: 40, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . O O . . 
. . . X X . . 
. . O X X . . 
X . X X O . . 
O . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.006 seconds.
Transposition table has 2740 states.
Minimax value for this state: 63, optimal move: 0
It is MIN's turn!
Enter move: 0

. . . O O . . 
. . . X X . . 
O . O X X . . 
X . X X O . . 
O . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.006 seconds.
Transposition table has 2090 states.
Minimax value for this state: 40, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . O O . . 
X . . X X . . 
O . O X X . . 
X . X X O . . 
O . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.002 seconds.
Transposition table has 809 states.
Minimax value for this state: 63, optimal move: 0
It is MIN's turn!
Enter move: 0

O . . O O . . 
X . . X X . . 
O . O X X . . 
X . X X O . . 
O . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 379 states.
Minimax value for this state: -12352, optimal move: 2
It is MAX's turn!
Computer chooses move: 2

O . . O O . . 
X . X X X . . 
O . O X X . . 
X . X X O . . 
O . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 154 states.
Minimax value for this state: -12352, optimal move: 2
It is MIN's turn!
Enter move: 2

O . O O O . . 
X . X X X . . 
O . O X X . . 
X . X X O . . 
O . O O O X . 
X . O X X O . 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 99 states.
Minimax value for this state: -12352, optimal move: 6
It is MAX's turn!
Computer chooses move: 6

O . O O O . . 
X . X X X . . 
O . O X X . . 
X . X X O . . 
O . O O O X . 
X . O X X O X 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 90 states.
Minimax value for this state: -12352, optimal move: 6
It is MIN's turn!
Enter move: 6

O . O O O . . 
X . X X X . . 
O . O X X . . 
X . X X O . . 
O . O O O X O 
X . O X X O X 
0 1 2 3 4 5 6 
Search completed in 0.001 seconds.
Transposition table has 69 states.
Minimax value for this state: -12352, optimal move: 6
It is MAX's turn!
Computer chooses move: 6

O . O O O . . 
X . X X X . . 
O . O X X . . 
X . X X O . X 
O . O O O X O 
X . O X X O X 
0 1 2 3 4 5 6 
Search completed in 0.001 seconds.
Transposition table has 60 states.
Minimax value for this state: -12352, optimal move: 6
It is MIN's turn!
Enter move: 6

O . O O O . . 
X . X X X . . 
O . O X X . O 
X . X X O . X 
O . O O O X O 
X . O X X O X 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 39 states.
Minimax value for this state: -12352, optimal move: 6
It is MAX's turn!
Computer chooses move: 6

O . O O O . . 
X . X X X . X 
O . O X X . O 
X . X X O . X 
O . O O O X O 
X . O X X O X 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 30 states.
Minimax value for this state: -12352, optimal move: 6
It is MIN's turn!
Enter move: 6

O . O O O . O 
X . X X X . X 
O . O X X . O 
X . X X O . X 
O . O O O X O 
X . O X X O X 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 8 states.
Minimax value for this state: -12352, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

O . O O O . O 
X . X X X . X 
O . O X X . O 
X . X X O . X 
O . O O O X O 
X X O X X O X 
0 1 2 3 4 5 6 
Search completed in 0.0 seconds.
Transposition table has 3 states.
Minimax value for this state: -12352, optimal move: 1
It is MIN's turn!
Enter move: 1
Game over!
O . O O O . O 
X . X X X . X 
O . O X X . O 
X . X X O . X 
O O O O O X O 
X X O X X O X 
0 1 2 3 4 5 6 
The winner is MIN (human)
Play again? (y/n): n
```
