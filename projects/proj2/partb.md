---
title: Project 2 - Part B Details
nav_exclude: true
---

# Project 2: Connect Four: Part B Details

## Guaranteed Wins

The guaranteed wins in Part B are identical to Part A.  This is because using alpha-beta
pruning always returns the same results as minimax, except for situations where pruning
removes sections of the game tree that will never be encountered during optimal play.

Like in Part A, your program should result in a transposition table
with the same number of states, same number of prunings,
 and the same first player win/second player win/tie
information from the two tables below.

<table border=1>
	<tr>
		<td>Cols &rarr;<br>Rows &darr;</td><td>3</td><td>4</td><td>5</td><td>6</td><td>7</td>		
	</tr>
	<tr>
		<td>3</td>
			<td>Tie<br>&lt; 1 sec<br>206 states<br>149 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>926 states<br>986 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>6792 states<br>8393 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>29559 states<br>34420 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>170295 states<br>206168 prunings</td>
	</tr>
	<tr>
		<td>4</td>
			<td>Tie<br>&lt; 1 sec<br>606 states<br>522 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>4102 states<br>4619 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>32020 states<br>34919 prunings</td>
			<td>1st player wins<br>~1 sec<br>192754 states<br>201936 prunings</td>
			<td>1st player wins<br>~17 sec<br>1448119 states<br>1775110 prunings</td>
	</tr>
	<tr>
		<td>5</td>
			<td>Tie<br>&lt; 1 sec<br>1465 states<br>1169 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>16224 states<br>17815 prunings</td>
			<td>1st player wins<br>~1 sec<br>129471 states<br>159790 prunings</td>
			<td>1st player wins<br>~15 sec<br>1000588 states<br>1183048 prunings</td>
	</tr>
	<tr>
		<td>6</td>
			<td>Tie<br>&lt; 1 sec<br>4455 states<br>4129 prunings</td>
			<td>1st player wins<br>&lt; 1 sec<br>47536 states<br>50343 prunings</td>
			<td>1st player wins<br>&lt; 6 sec<br>517915 states<br>636557 prunings</td>
	</tr>
</table>


Here are the details of guaranteed wins for <b>Connect-Four</b> for various board sizes.

<table border=1>
	<tr>
		<td>Cols &rarr;<br>Rows &darr;</td><td>3</td><td>4</td><td>5</td><td>6</td>
	</tr>
	<tr>
		<td>3</td>
			<td>Tie<br>&lt; 1 sec<br>106 states<br>87 prunings</td>
			<td>Tie<br>&lt; 1 sec<br>632 states<br>694 prunings</td>
			<td>Tie<br>&lt; 1 sec<br>6517 states<br>11440 prunings</td>
			<td>Tie<br>&lt; 1 sec<br>62907 states<br>412495 prunings</td>
	</tr>
	<tr>
		<td>4</td>
			<td>Tie<br>&lt; 1 sec<br>349 states<br>292 prunings</td>
			<td>Tie<br>&lt; 1 sec<br>7115 states<br>9004 prunings</td>
			<td>Tie<br>~5 sec<br>289554 states<br>945534 prunings</td>
	</tr>
	<tr>
		<td>5</td>
			<td>Tie<br>&lt; 1 sec<br>1021 states<br>895 prunings</td>
			<td>Tie<br>&lt; 1 sec<br>55040 states<br>92778 prunings</td>
	</tr>
	<tr>
		<td>6</td>
			<td>Tie<br>~1 sec<br>3118 states<br>3109 prunings</td>
			<td>Tie<br>~16 sec<br>535235 states<br>1886175 prunings</td>
	</tr>
</table>

## Output

Here is an example of how the program for Part B might look. 
Your output should include the same information (minimax values, number of prunings, 
optimal moves, size of the transposition table), but the formatting does not have to match exactly. 
You do not need to report the search time.

Here is the same first example from the sample output from Part A.  This is a situation where
MAX will win no matter what, but notice that MIN (the human) picks some suboptimal moves, and
each time this triggers a re-run of alpha-beta because the resulting states from 
each of those moves aren't in the transposition table. Additionally, notice that the game proceeds
in exactly the same fashion: the computer wins in exactly the same way and the minimax values
for all states are identical to those in Part A.

```
Run part A, B, or C? b
Include debugging info? (y/n) n
Enter rows: 4
Enter columns: 5
Enter number in a row to win: 3
Search completed in 0.169 seconds.
Transposition table has 32020 states.
The tree was pruned 34919 times.
First player has a guaranteed win with perfect play.
Who plays first? 1=human, 2=computer: 2

. . . . . 
. . . . . 
. . . . . 
. . . . . 
0 1 2 3 4 
Minimax value for this state: 22222, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

. . . . . 
. . . . . 
. . . . . 
. X . . . 
0 1 2 3 4 
Minimax value for this state: 22222, optimal move: 0
It is MIN's turn!
Enter move: 2

. . . . . 
. . . . . 
. . . . . 
. X O . . 
0 1 2 3 4 
This is a state that was previously pruned; re-running alpha beta from here.
Minimax value for this state: 22222, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

. . . . . 
. . . . . 
. X . . . 
. X O . . 
0 1 2 3 4 
Minimax value for this state: 22222, optimal move: 1
It is MIN's turn!
Enter move: 1

. . . . . 
. O . . . 
. X . . . 
. X O . . 
0 1 2 3 4 
Minimax value for this state: 22222, optimal move: 2
It is MAX's turn!
Computer chooses move: 2

. . . . . 
. O . . . 
. X X . . 
. X O . . 
0 1 2 3 4 
Minimax value for this state: 22222, optimal move: 1
It is MIN's turn!
Enter move: 4

. . . . . 
. O . . . 
. X X . . 
. X O . O 
0 1 2 3 4 
This is a state that was previously pruned; re-running alpha beta from here.
Minimax value for this state: 22222, optimal move: 3
It is MAX's turn!
Computer chooses move: 3

. . . . . 
. O . . . 
. X X . . 
. X O X O 
0 1 2 3 4 
Minimax value for this state: 22222, optimal move: 0
It is MIN's turn!
Enter move: 3

. . . . . 
. O . . . 
. X X O . 
. X O X O 
0 1 2 3 4 
This is a state that was previously pruned; re-running alpha beta from here.
Minimax value for this state: 22222, optimal move: 3
It is MAX's turn!
Computer chooses move: 3
Game over!
. . . . . 
. O . X . 
. X X O . 
. X O X O 
0 1 2 3 4 
The winner is MAX (computer)
Play again? (y/n): n
```

Same example from Part A, where MAX (the computer) will normally tie if MIN (the user) 
plays optimally, but the user makes lots of mistakes here and the computer eventually wins.

As above, the computer proceeds in exactly the same fashion and computes the same values
as in Part A.

```
Run part A, B, or C? b
Include debugging info? (y/n) n
Enter rows: 4
Enter columns: 4
Enter number in a row to win: 4
Search completed in 0.064 seconds.
Transposition table has 7115 states.
The tree was pruned 9004 times.
Neither player has a guaranteed win; game will end in tie with perfect play on both sides.
Who plays first? 1=human, 2=computer: 2

. . . . 
. . . . 
. . . . 
. . . . 
0 1 2 3 
Minimax value for this state: 0, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . . 
. . . . 
. . . . 
X . . . 
0 1 2 3 
Minimax value for this state: 0, optimal move: 0
It is MIN's turn!
Enter move: 3

. . . . 
. . . . 
. . . . 
X . . O 
0 1 2 3 
This is a state that was previously pruned; re-running alpha beta from here.
Minimax value for this state: 0, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

. . . . 
. . . . 
X . . . 
X . . O 
0 1 2 3 
Minimax value for this state: 0, optimal move: 0
It is MIN's turn!
Enter move: 0

. . . . 
O . . . 
X . . . 
X . . O 
0 1 2 3 
Minimax value for this state: 0, optimal move: 0
It is MAX's turn!
Computer chooses move: 0

X . . . 
O . . . 
X . . . 
X . . O 
0 1 2 3 
Minimax value for this state: 0, optimal move: 1
It is MIN's turn!
Enter move: 2

X . . . 
O . . . 
X . . . 
X . O O 
0 1 2 3 
This is a state that was previously pruned; re-running alpha beta from here.
Minimax value for this state: 0, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

X . . . 
O . . . 
X . . . 
X X O O 
0 1 2 3 
Minimax value for this state: 0, optimal move: 1
It is MIN's turn!
Enter move: 3

X . . . 
O . . . 
X . . O 
X X O O 
0 1 2 3 
This is a state that was previously pruned; re-running alpha beta from here.
Minimax value for this state: 0, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

X . . . 
O . . . 
X X . O 
X X O O 
0 1 2 3 
Minimax value for this state: 0, optimal move: 1
It is MIN's turn!
Enter move: 3

X . . . 
O . . O 
X X . O 
X X O O 
0 1 2 3 
This is a state that was previously pruned; re-running alpha beta from here.
Minimax value for this state: 10666, optimal move: 3
It is MAX's turn!
Computer chooses move: 3

X . . X 
O . . O 
X X . O 
X X O O 
0 1 2 3 
Minimax value for this state: 10666, optimal move: 1
It is MIN's turn!
Enter move: 1

X . . X 
O O . O 
X X . O 
X X O O 
0 1 2 3 
Minimax value for this state: 10666, optimal move: 1
It is MAX's turn!
Computer chooses move: 1

X X . X 
O O . O 
X X . O 
X X O O 
0 1 2 3 
Minimax value for this state: 10666, optimal move: 2
It is MIN's turn!
Enter move: 2

X X . X 
O O . O 
X X O O 
X X O O 
0 1 2 3 
Minimax value for this state: 10666, optimal move: 2
It is MAX's turn!
Computer chooses move: 2
Game over!
X X . X 
O O X O 
X X O O 
X X O O 
0 1 2 3 
The winner is MAX (computer)
Play again? (y/n): n
```
