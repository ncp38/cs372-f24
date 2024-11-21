---
title: Project 5
parent: Projects
---

<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>


# Project 5: Working with Neural Nets
{: .no_toc }

1. TOC
{:toc}

In this project, you will build a neural network and use it to accurately identify handwritten numbers! In computer science, this has actually been quite a challenging problem, and it's only within the last 30 years that we've been able to reliably identify handwritten letters.  In modern times, this task is very reliable and is mostly handled using neural networks.

Your project will be based on previously created code (see next section) to implement a neural network.  You will work with the MINST database in order to have enough data to train and test your neural net.  All of this will be discussed in greater detail in the walkthrough.

Once your code is up and running, you will analyze the effectiveness of the neural net and spend some time experimenting with the initialization parameters, which include number of epochs, mini-batch size, and eta (η).  You'll discuss what you did and the results in a larger questions document, the content of which will be part of your grade evaluation.

Note that this project is a 50-point project, as well.

## What you must do

First, **read Chapter 1** of  [<ins>Neural Networks and Deep Learning</ins>](http://neuralnetworksanddeeplearning.com/chap1.html).  This chapter will provide a walkthrough of some basic neural net concepts (that we'll also be going over in class) as well as discussing the motivation and reasoning behind our neural network program.

Next, **use one of the code repositories to implement your neural network**. You may use the code provided at this github if you prefer to use Python ([Python neural net code](https://github.com/mnielsen/neural-networks-and-deep-learning/blob/master/src/mnist_average_darkness.py), linked in the chapter above).  This code requires the numpy library, readily available online.

If you'd prefer to use Java for this project, you can use [Java Neural Net Code](https://www.makariev.com/blog/java-neural-network-tutorial-classifying-MNIST-handwritten-digits/), though I still require following along in Chapter 1 of the book, as it has a more thorough overview of what we're doing with this code.  This code also requires the JBang library, readily available online.

Finally, **verify that your code is working** by training a neural network and running a test on it.  Once you have done this, **experiment with different variable configurations** to see what changes in the output.  I encourage taking some notes as you progress through this so that you remember the results of different runs are.  Take some time in this phase of the process to look over the code and evaluate what it's doing.  You can even tweak the code to see what happens if different parts of it are changed.  Use the information you've gained from this stage to write the questions document; your analysis and experimentation will be important for your grade. 

## Recommendations

- This is a shorter project, but make sure that you budget time to adjust the neural net settings and evaluate the results.
- With modern computing, neural nets can be trained and tested relatively quickly, but may still take a fair bit of time to run, depending on the machine.
- *Optional:* If you're interested in taking this project a step further, you could try testing your network on photos of your own handwritten numbers.  Note that this may take some work to create enough photos for a reasonable test set and may also be challenging to get those photos into a workable format.

## At the end of the project

-   As you are preparing to submit the project, please prepare a text file (`.txt`, pdf, or Word doc is fine) answering the following questions:
    1.  What bugs and conceptual difficulties did you encounter? How did you overcome them? What did you learn?
    2.  Describe whatever help (if any) that you received. Don’t include readings, lectures, and exercises, but do include any help from other sources, such as websites or people (including classmates and friends) and attribute them by name.  
    3.  Describe any serious problems you encountered while working on this project.
    4.  Mention any challenges that you did.
    5.  List any other feedback you have. Feel free to provide any feedback on how much you learned from doing the assignment, and whether you enjoyed doing it.
	6.  Discuss your work with the neural network.  What variables have you adjusted, and what changes did that cause?  
	7.  What were your findings from this project and from your experimentation?  Have you come to any conclusions about neural networks?
	8.  After this project, do you have a better understanding of neural networks?  Do you feel that you could use them again in another context?
-   Please also add a comment at the top of your files stating your **name and a pledge that you have followed the honor code** and collaboration policy for this project. This can be as simple as writing “**I have neither given nor received unauthorized aid on this program.**”  For this project, you must also include **a citation for your code's source**. You can find the collaboration policy on the syllabus.

## Grading

- You will be graded on the correctness/use of your program and your experimentation and analysis of neural networks.

## Submission instructions

To submit, upload all your source code files to canvas.  Since this project is based on code from an outside source, you need to include **your name, the honor code, and a citation for where you got your code** in a comment at the top of each program file.  This citation can be in the form of a link with a short description.  Make sure to also submit your **answers to the post-project questions!**  (Note that the post-project questions are longer this time.)

Before submitting, make sure that you've included all the requirements for this project!  You can double-check by searching this page (ctrl+f or command+f) for **'must'**; important details related to the assignment are also highlighted for your convenience.

## Challenges

For this project, feel free to take your network beyond the basic network discussed in Chapter 1, either by adding functionality, implementing some of the improvements discussed in later chapters, or in some other way.
