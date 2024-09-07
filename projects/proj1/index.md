---
title: Project 1
parent: Projects
---

<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>


# AI Project 1: GPS Navigation
{: .no_toc }

1. TOC
{:toc}

In this project, you will write a program that uses the A\* algorithm to find the fastest route between two locations in Memphis.  Your program will print out the route as a list of GPS-style navigation directions.

**Optional starter code**: [priority queue classes (cpp/python/java)](pqueue-distrib.zip) | [proj0 solutions (python/java)](proj0-distrib.zip)  Note that these project 0 solutions will only become available after everyone turns in project 0/the last day to turn it in.

## What your program should do
 - Your program should read the `memphis-medium.txt` map and process it using the ideas from Project 0, though nothing needs to be printed.  
 - Your program should **ask the user for the starting and ending location IDs** of the desired route.  Your program should also ask **whether the user wants to print debugging information**; this is explained below.
 - Your program should **use the A\* algorithm** to compute the fastest driving route between the two locations.  As in Project 0, your program should use the speed limit for each road to determine the time it takes to travel that particular road segment. You may assume speed changes are instantaneous, and you don’t have to take traffic or stop lights (or other things which one would slow down for) into account.  
 - Your program should print the fastest route found as a sequence of location IDs and street names (see below for details).  In addition, the output should include:
	- **The total number of nodes visited** in the search tree.
	- **The total time** the route takes to drive, in seconds.
 - In part B, your program will also take into account the agent's ability to speed
  (ignore the speed limit in a certain way).

### Debugging output
To help you debug your program, and to help in grading, your program should also print some extra information while the A\* search is running.  However, because this information can become rather long, you will only print it if requested.

If asked to print debugging information, your program must print:
- **Information about every node removed** from the frontier, as it is removed (we call this *visiting* a node).  You should print the node's state (a location ID), the node's parent's state (also a location ID), and the _f(n)_, _g(n)_, and _h(n)_ values for the node.
- **Information about every child node that is generated** as part of the expansion of a node.  For each child node, you should print whether it is added to the frontier or not, along with the same five pieces of information as when a node is visited (state ID, parent's state ID, _f(n)_, _g(n)_, and _h(n)_).

## General guidelines
- You may implement this project in Java, Python, or C++. Talk to me if you want to use another language. 
- All the basic guidelines from Project 0 about suggested data structures apply to Project 1 as well.  You may choose to base this project off of your own code for Project 0, or you may start with [my Project 0 code](proj0-distrib.zip), available in Python or Java.

## Part A: The A\* algorithm
- This part of the project is worth 85% of your grade.  In other words, if you complete the A\* algorithm, but do nothing in part B, your maximum grade is 85/100.
- Use the A\* pseudocode in the book or from class lecture.  See [Pseudocode and implementation hints](astar-impl-hints.pdf) for additional help. While you may find online sources helpful in understanding the algorithm, you may encounter slight variations in different people’s versions of the algorithm that will make it difficult for me to test your code and help you debug it if necessary.
- You must keep track of the number of nodes "visited," which means the number of nodes popped off of the frontier.
- *g(n)* for a node *n* (a.k.a. the path-cost) is the total travel time, in seconds, from the initial state to the state of node *n*.
- *h(n)* is the heuristic function.  Remember that it is supposed to be an estimate of the  total travel time remaining, from the state of node *n* to the goal state. There are lots of ways to estimate this, but in order for A\* to be optimal, we must use a function that does not overestimate the true time to the goal.  Therefore, we will use the *straight-line travel time from  _n_  to the goal state, assuming you could drive from node  _n_  to the goal at 65 miles per hour.* We can use 65mph because that’s the maximum speed limit of any Memphis road, so this  _h(n)_  will never overestimate the true travel time.
- Data structure suggestions:
	- You can use a class for the states (like a `Location` class), but you can also just use the location ID (a string or some kind of number, depending on language). You probably want to make a `Node` class, but it's possible to get away without one if you use maps to store the parent references, along with the f/g/h values for the nodes.  I found it easiest to make a `Node` class that holds a state, a parent pointer, and the f/g/h values.
	- *Frontier:* I have written [priority queue classes](pqueue-distrib.zip) in Python, C++, and Java, which you may use if you want.  I think they are easier to use than the ones built-in to those languages, but you may use whatever kind of priority queue structure you want.
	- *Reached*: Standard maps should work fine here.  You can use a map from states to `Node`s or since you really just need the *f(n)* value for a node, you can use a map from states to `double`s and just store the `f(n)` value directly in the map. 
- When A\* finishes, you end up with the final `Node` object that corresponds to a goal state.  You can then follow the chain of parent pointers back to the initial state to get the sequence of locations/roads that you need.

## Part B: Letting the agent speed
- This part of the project is worth the final 15% of your grade.
- In this part, you will reimplement A\* to solve a slightly different problem (though
if you've written Part A following good style, not much will change in Part B).
- Here, we will assume that the agent is allowed to speed occasionally while driving
through Memphis.  In particular, your program will prompt the user for the number of
times the agent is allowed to speed (an integer >= 0).  When an agent chooses to speed,
they will drive a single road segment at *twice* the speed limit, rather than the posted
speed limit.  Or, equivalently, in terms of time, they will travel a road segment 
in *half* of the time that it would normally take them.  (Note that this is not particularly realistic [although maybe in Memphis it is...], but we will use it here
because it makes adjusting the heuristic straightforward.)
- This will require making a number of changes and additions to your code:
  - You will need to keep track of the number of times remaining the agent will speed.
  Since this is changing, this becomes part of the *state*.  So a state is now two
  pieces of information: a location and an integer representing the number of times
  left that speeding can happen.
  - Similarly, the concept of an action must also change.  Before, an action was just
  taking a particular road, but now the agent has the option to speed, so an action
  now must include both a road and whether or not the agent speeds on the road.  Basically,
  if an agent is at a state with a "times left to speed" greater than 0, it has *twice*
  as many actions as in Part A: every connecting road may be driven on at the true 
  speed limit, or twice as fast.
  - And finally, successor states will be generated slightly differently, as the
  "times left to speed" part of a state must be decreased by 1 for a successor state
  generated by a speeding action.
  - The heuristic function also must change to take into account speeding.  In particular,
  since an admissible and consistent heuristic must never overestimate the true cost
  to the goal, the old heuristic is no longer admissible (because true driving times
  are now smaller due to allowing speeding).  So you must invent a new heuristic that
  will not overestimate.  This is not intended to be very hard to do, however.
- When printing the final output for Part B, you should indicate which roads are being
sped on, and which are driven normally.



## Testing
You should test your program thoroughly.  I recommend using the debugging output to make sure you are examining nodes in the same order that my solution is. It is possible there may be slight variations in f/g/h values due to round-off errors differing between Python/C++/Java.  However, these variations should be *very* small.

Note that for Part B, when using a "speeding count allowed" of zero, the output
should be identical to Part A.

### Location IDs

To test your program, I have collected the  [IDs](where-are-things.txt)  for some Memphis landmarks, commonly-visited places, and some intersections near Rhodes.

### Example runs (Part A)
Here are four sample runs.  Assuming the debugging flag is turned off, the first three all run in less than one second on my computer, and the last one takes less than five seconds.

-   Rhodes College to Barksdale & Snowden (2471207719 to 203785186) [with debugging](output1-debug.txt), [without debugging](output1.txt)
-   University & Tutwiler to McLean & Snowden (203874746 to 203744893) [with debugging](output2-debug.txt), [without debugging](output2.txt)
-   Overton Square to U of Memphis (203777568 to 203948127) [with debugging](output3-debug.txt), [without debugging](output3.txt)
-   Graceland to Shelby Farms Park (480814962 to 1352161029) [with debugging](output4-debug.txt), [without debugging](output4.txt)

### Example runs (Part B)

-   Rhodes College to Barksdale & Snowden (2471207719 to 203785186) [speeding=1, with debugging](output1-b-debug.txt)
-   University & Tutwiler to McLean & Snowden (203874746 to 203744893) [speeding=1, with debugging](output2-b1-debug.txt), [speeding=2, with debugging](output2-b2-debug.txt)


## At the end of the project

-   As you are preparing to submit the project, please prepare a text file (`.txt`, pdf, or Word doc is fine) answering the following questions:
    1.  What bugs and conceptual difficulties did you encounter? How did you overcome them? What did you learn?
    2.  Describe whatever help (if any) that you received. Don’t include readings, lectures, and exercises, but do include any help from other sources, such as websites or people (including classmates and friends) and attribute them by name.
    3.  Describe any serious problems you encountered while writing the program.
    4.  **What did you use for your Part B heuristic?**
    5.  List any other feedback you have. Feel free to provide any feedback on how much you learned from doing the assignment, and whether you enjoyed doing it.
-   Please also add a comment at the top of your program stating your name and a pledge that you have followed the honor code and collaboration policy for this project. This can be as simple as writing “**I have neither given nor received unauthorized aid on this program.**” You can find the collaboration policy on the syllabus.

## Grading
- Your project will be graded on the correctness of your program, in particular:
  - whether your program produces the correct best route and correct best travel time in seconds,
  - whether the sequence and number of nodes visited and expanded is correct,
  - whether the GPS turn-by-turn navigation directions, including number of miles and seconds, is correct.
Small variations in f/g/h values due to round-off errors are OK; and this may cause small variations in the sequence of nodes visited/expanded as well.
It might also induce variations in the optimal route found, but it shouldn't cause the best travel time to change much.
- Your project will also be graded on the appropriateness and efficiency of the algorithms you choose, and on coding style.

## Submission instructions

Through Canvas, upload all your source code files and your file with the answers to the questions above.

