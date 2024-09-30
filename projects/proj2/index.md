---
title: Project 2
parent: Projects
---

<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>


# AI Project 2: Connect Four
{: .no_toc }

1. TOC
{:toc}


In this project, you will use the minimax and alpha-beta pruning algorithms to study the game of Connect Four (or sometimes Connect Three). You will implement three versions of the minimax algorithm: (A) regular minimax, (B) minimax with alpha-beta pruning, and (C) minimax with alpha-beta pruning and heuristics.

For Parts A and B, your output should match mine, in that everyone should be implementing the algorithms in the exact same way.  For Part C, however, you are given the freedom to design a heuristic as you see fit.

## Initial setup

- [Java starter code](java-starter.zip)
- [Python starter code](python-starter.zip)

I am providing you with starter code in Java and Python.  This starter code contains a data type modeling a Connect Four board that you may use in your program.  It is not required that you use my code, but it saves you time in having to write a lot of boilerplate code from scratch.  You should feel free to add anything you want to the starter code to make it easier to use.

It is optional, but you may want to begin the overall project by writing a piece of code that allows the user to play Connect Four, with both players (MIN and MAX) being controlled from the keyboard.  This is useful because it will give you some practice using the starter code and also all three parts below end with having the user play against the computer, so having code that plays the game already written will be useful.

## Guide to the project

I have put together some [technical details](minimax-impl.pdf) for the three algorithms, including improved pseudocode.

### How the program should work

You should have one single program that allows the user to choose whether they want to run Part A, B, or C. The code for these three parts is very similar, and so it's not as much work as you might think to get all three parts working.  The fun in the project is in Part C, where you have complete creativity into how you want your heuristic to work.

When your program begins, it must prompt the user for the following pieces of information:
- Whether the user wants to run **Part A, B, or C**.
- Whether to **print debugging information** (for this project, debugging information is just the contents of the transposition table).
- The **size** of the desired board, in rows and columns.
- The **number of consecutive tokens on the board needed to win** (my starter code supports 2, 3, and 4; if you write your own Board class, it should support at least 3 and 4).
	- Note that having code that works with Connect-2 and Connect-3 is very helpful for debugging, because while these games aren't very interesting, they have small state spaces that you can look through without getting overwhelmed.

After these steps, your program will follow Part A, B, or C below.  All three parts end in a similar fashion:
having the user play the game against the computer.

### Part A: Minimax, with transposition table
*This part is worth 50% of your grade.*

[Part A sample output](parta.md)

In this part, your program will then use the minimax algorithm to traverse the entire game tree to determine if the first player (MAX) has a guaranteed win, the second player (MIN) has a guaranteed win, or neither player is guaranteed to win (perfect play on both sides results in a draw).

The minimax value for a terminal state (a state where MAX has won, MIN has won, or the game is a draw) should be the calculated as follows. If MAX has won, the value of the state is  `int(10000.0 * rows * cols / moves)`, where  `moves`  is the number of moves the game has lasted. For instance, if you are playing on a 4-by-5 grid and MAX wins in 12 moves, then the value of this state is  `10000 * 4 * 5 / 12`  =  `16666`. Dividing by the length of the game will prioritize quicker-winning moves. If MIN has won, use the same formula, but negated. If there is a draw, the value of the state is zero.

After the user types in values for the board dimensions and the number in a row needed to win, you must run the minimax algorithm with a transposition table (see the pseudocode) to compute the optimal way to play the game from any possible state. Then, print out the following pieces of information:
- The **size of the transposition table** (this is an easy way to test if your algorithm is working, because this number should match mine exactly).
- Whether the first player (MAX) has **a guaranteed win, loss, or draw** assuming perfect play on both sides.
- If the user asked for debugging information, **print the entire contents of the table** as well.

Next, let the user play against the computer. The user must be able to choose if **they want to move first**, or if they want to the computer to move first. The computer should used the saved minimax actions & values in the transposition table to look up each state and figure out what to do.  After the game concludes, your program must prompt the player to see if **they want to play again**.

**If your minimax algorithm determined that there is a guaranteed win for one of the players, and the computer acts as that player, then the computer should never lose.**

As the game is being played, the program should print out, for each state as it is encountered, the minimax value of that state, and the optimal action from that state.  These values are also helpful for debugging, as they should match mine.

### Part B: Minimax, with alpha-beta pruning and transposition table
*This part is worth 25% of your grade.*

[Part B sample output](partb.md)

You will notice that Part A will not be able to search the full state space for the “traditionally-sized” game of Connect Four (6 rows, 7 columns) in any reasonable amount of time — there are just too many board configurations to consider, even with using a transposition table.  In Part B, we will add code to use alpha-beta pruning to remove large sections of the game tree that the algorithm can determine will never be encountered during perfect play. 

If the user chooses Part B, your program must act similarly to Part A, **except using the pseudocode for alpha-beta pruning**, rather than regular minimax.  To match my output, your algorithm must **consider the possible moves of the game in order from left-to-right**.  That is, consider the columns of the board starting with column zero (the leftmost column).  Alpha-beta works best when one considers the "best" move first, and so this particular move-ordering scheme is not great, but we are using it so that your output will match mine exactly.  In Part C, you can change the order in which you consider moves to improve the algorithm more, if you want.

There are a few additional changes you must implement:
- After running alpha-beta search before the game begins, in addition to the same information printed in Part A, you should also print **the number of times the tree was pruned**.  This should match mine.
- When letting the user play against the computer, it is possible that if the user makes a sub-optimal move, the computer may encounter a part of the game tree that alpha-beta pruned away. You will know when this happens because the transposition table will not have the current game board in it. This is ok! If this happens during the game, just **re-run alpha-beta**, *starting from the current state of the game*.  The algorithm will work just fine starting from partway through the game.  After the re-run of the algorithm finishes, the new transposition table should have the current game board in it, and you can continue playing with the updated table.  It is possible, that if the user continues to play sub-optimally, that you will need to re-run alpha-beta more than once.

### Part C: Minimax, with alpha-beta pruning, heuristics, and transposition table
*This part is worth 25% of your grade.*

[Part C sample output](partc.md)

It turns out even alpha-beta pruning will not make the full board size of Connect Four feasible. Instead, what we will do is similar to what humans do when faced with a game that can continue for a large number of moves: we will only look ahead a fixed number of moves. To do this, we will require a heuristic function that can estimate the quality of an unfinished game state. (See section 5.3 of the textbook or your notes from class).

Here, the first additional thing Part C must do is prompt the user for the **depth to which the algorithm should search** for solutions.  This is a variable that refers to the number of moves to "look ahead" in the game tree.  For instance, with a depth of 1, the algorithm will only be able to examine the game states resulting from its own next move. If  depth is 2, the algorithm will be able to examine game states resulting from its own next move and the user’s response move.

Unlike in Parts A and B, where we used minimax or alpha-beta to “pre-process” the game tree to get the best moves, in Part C we must **re-run the algorithm before *each* move** of the game is made.  The reason for this is since we are using a cut-off depth, if we run a search after each move, we will always be able to look a fixed number of moves ahead of wherever we are in the game.

In other words, immediately after asking for the depth to search, your program should start the game (as always, let the user pick who goes first). Then the algorithm will run alpha-beta with heuristics, looking ahead the number of moves asked for, and calculate what it thinks is the best move.  If the computer moves first, it will make that move, otherwise it will just be printed, and the user can choose to follow it or ignore it.  Once the move is made, restart the search again from the new board position, again looking the same number of moves ahead (though now we can look one level relatively deeper in the tree), and continue on until the game ends.

Note: Because we are using a cut-off depth, the computer player is not expected to play perfectly, even in cases where in Part A or B it would have always won. That being said, if we use a deep enough cut-off depth and a good heuristic, the computer player should be pretty good.

## Hints

-   This is a challenging project. Start early.
-   Use diagnostic messages to print the status of the minimax and alpha-beta pruning algorithms.
- Use my output to help you debug.
- The code for the three main algorithms in Parts A, B, and C is so similar, that I suggest writing Part A, copying-and-pasting it to start writing Part B, getting B to work, then copying-and-pasting again to write Part C.

## FAQ

-   How do I implement the transposition table?
    -   I suggest using a map/dictionary/hashtable that maps game states (board configurations) to pairs of integers, one which represents the minimax value for that game state, and the other that represents the best move (column in which to drop the token) from that game state. (In this pseudocode, I call this the MinimaxInfo class). Using this, whenever minimax encounters a state it has seen before, it can use the cached value in the transposition table, rather than recalculating everything.
-   How do I represent the state of the game?
    -   Use my `Board` class, or write your own. This class will contain the current layout of the game board, and information about whose turn it is, how many moves have been made, etc. I also suggest having methods in the class for seeing which moves are available and then generating new boards for all the moves.
    -   I highly suggest making your board class immutable, in that when you generate the successor boards for each possible move, you should create a brand new board object for each new child state. Do not simply change the existing board to reflect a player making a move, because then you will have to implement a way to  _remove_  that token from the board as the minimax algorithm proceeds.
-   My program is slow. What can I do?
    -   Unfortunately, it is possibly an O(n^2) operation to figure out if a Connect Four board contains a win, because often we must examine all the tokens on the board. And because we are generating  _many_  boards that must be examined, we must make the board class as fast as possible. Here are some ideas:
    -   Cache the win/lose/draw state of each board in the class, once you have calculated it, in case you need to re-use it more than once.  (My starter code does this.)
    -   When you create new states, if you are using a list of lists or a tuple of tuples to represent a board in Python, use the  `deepcopy`  library to copy the Connect Four board into new states.  (This is recommended so that changes made to the new state don't modify the original variable.)
-   Python won’t let me put my board in a dictionary. Or, once I put it in the dictionary, I can’t find it again.
    -   In order to use your own objects as keys in a Python dictionary, you must write a  `__hash__()`  method and an  `__equals__()`  method.
    -   Alternatively, if you are trying to store a list as a dictionary key, Python will not let you do this (you get the “lists are unhashable” error.) Instead, you can turn your list of lists into a tuple of tuples and hash that instead. You can use the  `tuple()`  function to turn a list into a tuple. I suggest writing a  `tupleize()`  function that will apply this to your list of lists.


## At the end of the project
**Note that question 4 is different!**

-   As you are preparing to submit the project, please prepare a text file (`.txt`, pdf, or Word doc is fine) answering the following questions:
    1.  What bugs and conceptual difficulties did you encounter? How did you overcome them? What did you learn?
    2.  Describe whatever help (if any) that you received. Don’t include readings, lectures, and exercises, but do include any help from other sources, such as websites or people (including classmates and friends) and attribute them by name.
    3.  Describe any serious problems you encountered while writing the program.
    4.  **Explain your heuristic that you invented for Part C.**
    5.  List any other feedback you have. Feel free to provide any feedback on how much you learned from doing the assignment, and whether you enjoyed doing it.
-   Please also add a comment at the top of your program stating your name and a pledge that you have followed the honor code and collaboration policy for this project. This can be as simple as writing “**I have neither given nor received unauthorized aid on this program.**” You can find the collaboration policy on the syllabus.

## Grading

-   Your project will be graded on the correctness of your program, in particular:
    -   **whether your program's output matches mine for Parts A and B**. The output does not have to a word-for-word match, but the *numbers* should match, such as the number of states in the transposition tables, numbers of states pruned, etc.
    - **whether your program plays "correctly" in Parts A and B**. In particular, the computer should always win when it can, and if the user happens to make a mistake, the computer should capitalize on that mistake if it can.  (There is nothing special you need to do to make this happen; if you have implemented minimax correctly, it should happen automatically.)
    - **how good your program in Part C is**.  In particular, even with a mediocre heuristic, your program should beat the user consistently on the full game of Connect Four given a 6-move lookahead.
-   Your project will also be graded on the appropriateness and efficiency of the algorithms you choose, and on coding style.

## Submission instructions

To submit, upload all your source code files to canvas, including **your name and honor pledge**, and **ensure that your tests for all the required functions**.  Make sure to also submit your **answers to the post-project questions**

Before submitting, make sure that you've included all the requirements for this project!  You can double-check by searching this page (ctrl+f or command+f) for **'must'**; important details related to the assignment are also highlighted for your convenience.

## Challenges

The challenges for this assignment all involve making your heuristic better.  You are essentially given free-reign to do what you want, as long as you stay within the guidelines of how minimax with alpha-beta works.  In other words, your heuristic should be a function that considers a state of the game and returns an integer value.  The way you compute that integer is up to you. (If you're interested in doing the challenge, you should describe your heuristic and demonstrate its effectiveness above and beyond the base algorithm.)

### Some ideas to improve the Part C heuristic
- My baseline heuristic described in Part C considers 2-in a rows, 3-in a rows, and 4-in a rows.  You can modify the number of points awarded in each of these cases.
- My baseline heuristic doesn't check for gaps on either side when there's consecutive tokens in a row.  So a row of the board that looks like `OXXO` would award points for the two X's in a row, even though there's no place to add a third X on either side.  You can fix this.
- You can modify the order in which moves are considered.  Recall that alpha-beta can prune more of the search space (and therefore run faster) if it considers better moves first.
- Try coming up with other features besides just looking for consecutive tokens in a row.

