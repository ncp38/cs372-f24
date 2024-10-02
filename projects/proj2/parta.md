---
title: Project 2 - Part A Details
nav_exclude: true
---

# Project 2: Connect Four: Part A Details

## Guaranteed Wins

Here are the details of guaranteed wins for 
**Connect-Three** for various board sizes, along with the total number of possible 
states of the game, and roughly how long it took my computer to run minimax on the state space. My code is in Java 
on a relatively modern laptop; your code, especially if in Python, may run slower.

Your solution for Part A should result in a transposition table
with the same number of states and the same first player win/second player win/tie
information from the two tables below.

The links in the table below will let you see the entire transposition table for different
board configurations, which may help you debug your code.  (I sorted the transposition table states alphabetically
to make the table easier to read.)

<base href="https://ncp38.github.io/cs372-f24/projects/proj2/" />
<table border=1>
	<tr>
		<td>Cols &rarr;<br>Rows &darr;</td><td>3</td><td>4</td><td>5</td><td>6</td>		
	</tr>
	<tr>
		<td>3</td>
			<td>Tie<br>&lt; 1 sec<br><a href="a333.txt">694 states</a></td>
			<td>1st player wins<br>&lt; 1 sec<br><a href="a343.txt">7157 states</a></td>
			<td>1st player wins<br>&lt; 1 sec<br>70914 states</td>
			<td>1st player wins<br>~4 sec<br>692970 states</td>
	</tr>
	<tr>
		<td>4</td>
			<td>Tie<br>&lt; 1 sec<br><a href="a433.txt">2715 states</a></td>
			<td>1st player wins<br>&lt; 1 sec<br>41750 states</td>
			<td>1st player wins<br>~4 sec<br>613459 states</td>
	</tr>
	<tr>
		<td>5</td>
			<td>Tie<br>&lt; 1 sec<br>8789 states</td>
			<td>1st player wins<br>~1 sec<br>195472 states</td>
	</tr>
	<tr>
		<td>6</td>
			<td>Tie<br>&lt; 1 sec<br>25753 states</td>
			<td>1st player wins<br>~4 sec<br>844488 states</td>
	</tr>
</table>

Here are the details of guaranteed wins for <b>Connect-Four</b> for various board sizes.

<table border=1>
	<tr>
		<td>Cols &rarr;<br>Rows &darr;</td><td>3</td><td>4</td><td>5</td><td>6</td>
	</tr>
	<tr>
		<td>3</td>
			<td></td>
			<td>Tie<br>&lt; 1 sec<br>12031 states</td>
			<td>Tie<br>~1 sec<br>158911 states</td>
			<td>Tie<br>~23 sec<br>2087325 states</td>
	</tr>
	<tr>
		<td>4</td>
			<td>Tie<br>&lt; 1 sec<br>6000 states</td>
			<td>Tie<br>~1 sec<br>161029 states</td>
	</tr>
	<tr>
		<td>5</td>
			<td>Tie<br>&lt; 1 sec<br>38310 states</td>
			<td>Tie<br>~27 sec<br>1706255 states</td>
	</tr>
	<tr>
		<td>6</td>
			<td>Tie<br>~1 sec<br>235781 states</td>
	</tr>
</table>

## Output

Here is an example of how the program for Part A might look. 
Your output should include the same information (minimax values, optimal moves, size of the transposition table),
but the formatting does not have to match exactly. You do not need to report the search time.


Example where MAX (the computer) will win no matter what:

```
Run part A, B, or C? A
Include debugging info? (y/n) n
Enter rows: 4
Enter columns: 5
Enter number in a row to win: 3
Search completed in 3.697 seconds.
Transposition table has 613459 states.
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

Example where MAX (the computer) will normally tie if MIN (the user) plays optimally, but the user makes lots of mistakes here and the computer eventually wins:

```
Run part A, B, or C? A
Include debugging info? (y/n) n
Enter rows: 4
Enter columns: 4
Enter number in a row to win: 4
Search completed in 0.956 seconds.
Transposition table has 161029 states.
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
