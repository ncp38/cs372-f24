---
title: Project 4
parent: Projects
---

<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>


# Project 4: Naive Bayes Classification
{: .no_toc }

1. TOC
{:toc}

For this project, you will build a Naive Bayes classifier which will classify emails into one of two possible categories or classes: *spam* and *not-spam* (also known as *ham*). Your program will learn the difference (as best as it can) between the two classes by examining a collection of pre-classified example emails. Then, your program will see how well it can generalize what it has learned to new emails it has not seen before. 

The features your classifier will use are the presence or absence of every word in the training set of emails. Multiple occurrences of a word in an email should not affect your classifier --- only whether the word is present or not.

## What your program should do

The program operates in two phases. First, in the *training phase*, your program reads in two different text files containing training examples for the two classes. These two files together are called the *training set*. Your program will examine the emails in the training set and, for each class, tabulate information about the number of training examples and how many times each word in the vocabulary appears in the examples for that class. (The "vocabulary" is the set of all words that appear in the training set emails.)

Second, in the *testing phase*, your program will read in another two text files containing a new set of examples for each of the two classes. These two files together are called the *testing set*. Your program will run the classifier on each email in the testing set and classify it into one of the two classes by calculating the MAP hypothesis. Your code will report, for each email in the training set, the *log-probability* of the email belonging to each of the two classes, the predicted class, and whether or not the prediction was correct. At the end, your program will report the the number of examples in the testing set that were indeed classified correctly.

It is not realistic to think that your classifier will perform perfectly. After all, the only information your classifier will have to work with is which of the vocabulary words are present in an email. Even more sophisticated spam classifiers make mistakes, too! Therefore, do not be concerned if the program reports a classifier accuracy below 100%, that does not necessarily imply your program is doing something wrong.

## Input

Your program should begin by prompting for four filenames in this order: 
- training file for spam
- training file for ham
- testing file for spam
- testing file for ham

Each of the four files is organized like this:

```
<SUBJECT>
a single line with the subject of email 1 (might be blank)
</SUBJECT>
<BODY>
line 1 of the body
line 2 of the body
more lines.... possibly blank
</BODY>
<SUBJECT>
a single line with the subject of email 2 (might be blank)
</SUBJECT>
<BODY>
line 1 of the body
line 2 of the body
more lines.... possibly blank
</BODY>
```

## Log probabilities

Due to the limits of how floating-numbers are stored on computers, you should use [log-probabilities](naive-bayes-log-probs.pdf) in your calculations.

## Output

For each email in the testing set (consisting of two files, the spam testing file and the ham testing file), print the following information:

- The word TEST in all caps.
- The message number within the file (first message is #1)
- The number of features (words from the vocabulary) that were true in this message
- The log-probabilities calculated for spam and ham (use natural log), rounded to three decimal places. These log-probabilities should not be normalized, so they will not sum to 1.
- The word "spam" or the word "ham" depending on how your classifier predicts this message
- The word "right" or the word "wrong" depending on if your prediction matches the true classification of this message

You **must** format the line like this:

```
TEST 144 66/78082 features true -344.684 -331.764 ham right
```

I'm asking for this specific format because I will use the "diff" utility to compare your output against the correct output, so the format has to match exactly.

At the very end of your output, report the total number of emails in the testing set that were classified correctly.

You can have other things in the output for debugging, such as diagnostic information about priors or likelihoods or anything you want that helps you debug your project, 
as long as the specific output lines above are there (TEST lines and the number of emails classified correctly.)

## Sample output

Your output must contain the TEST lines and the final number of emails correctly classified.  Anything else is optional.

### Small data set

- [ [train-spam-small.txt](train-spam-small.txt) ]
- [ [train-ham-small.txt](train-ham-small.txt) ]
- [ [test-spam-small.txt](test-spam-small.txt) ]
- [ [test-ham-small.txt](test-ham-small.txt) ]

[ [output with extra debugging ](output-small.txt) ] [ [output with only required info ](output-small-testonly.txt) ]

Useful statistics: vocab size = 3, priors = 0.6 and 0.4, 2 out of 2 test set emails classified correctly.

### Full data set

(Note that the training set sizes are 10 and 17 megabytes in size.)

- [ [train-spam.txt](train-spam.txt) ]
- [ [train-ham.txt](train-ham.txt) ]
- [ [test-spam.txt](test-spam.txt) ]
- [ [test-ham.txt](test-ham.txt) ]

[ [output with extra debugging ](output-big.txt) ] [ [output with only required info ](output-big-testonly.txt) ]

Useful statistics: vocab size = 78082, priors = 0.7866966480154788 and 0.21330335198452124, 1179 out of 1551 test set emails classified correctly.

## Guidelines

- For the basic project, ignore any distinction between words in the body and words in the subject. 
- Tokenize the input by splitting on spaces or newlines, convert all words to lowercase, and you should be good to go. Be sure the number of features (vocabulary size) matches my output.

## FAQ

- Q: If the vocabulary is built only from the training set, what happens when I see a word in the testing set that isn't in the vocabulary?  
  A: You ignore the word. Since features are only constructed during the training phase, when you see a new word during the testing phase, there's no way to figure out an appropriate probability for it, so you just ignore it.
- Q: What do I need to smooth?  
  A: Smooth the probabilities for each feature (word) given a hypothesis, but do not smooth the priors.

## Walkthrough on sample data

- First, remember that all the calculations always have the same number of components (for a run of the program), and they don't depend on the number of words in the test email. In other words, for the small example, you will always have four terms being multiplied (because there's one for the prior, and three features, one each for `phil`/`viagra`/`the`).

- For the small training set, we have the following:
  - 5 total emails: 3 spam, 2 ham.
  - Of the 3 spam emails, 3 have `viagra`, 1 has `phil`, 3 have `the`.
  - Of the 2 ham emails, 0 have `viagra`, 2 have `phil`, 2 have `the`.
- For testing: For the first email in the test set, `viagra` and `phil` are present, but not `the`. So there are three features, two "positive" (`viagra`/`phil`) and one negative (`the`). So the math goes like this:
- For SPAM:
  - \$$ P(\text{spam}) = 3/5 $$
  - \$$ P(\text{viagra} \mid \text{spam}) = 3/3 \to \text{smooth} \to 4/5 $$
  - \$$ P(\text{phil} \mid \text{spam}) = 1/3 \to \text{smooth} \to 2/5 $$
  - \$$ P({\sim}\text{the} \mid \text{spam}) = 1 - P(\text{the} \mid \text{spam}) = 1 - 3/3 = 0/3 \to \text{smooth} \to 1/5 $$
- Normally, we would multiply these probabilities next:
  - \$$ 3/5 \cdot 4/5 \cdot 2/5 \cdot 1/5 = .0384 $$
- But because the product of many probabilities will quickly become very small, we 
  will do the math with log probabilities instead:
  - \$$\ln(3/5) + \ln(4/5) + \ln(2/5) + \ln(1/5) = -3.260 \text{ (rounded)}$$
- For HAM:
  - \$$P(\text{ham}) = 2/5 $$
  - \$$P(\text{viagra} \mid \text{ham}) = 0/2 \to \text{smooth} \to 1/4$$
  - \$$P(\text{phil}\mid \text{ham}) = 2/2 \to \text{smooth} \to 3/4$$
  - \$$P({\sim}\text{the}\mid \text{ham}) = 1 - P(\text{the}\mid \text{ham}) = 1 - 2/2 = 0/2 \to \text{smooth} \to 1/4$$
- Multiply everything (or rather, take the log of each probability and add):
  - \$$\ln(2/5) + \ln(1/4) + \ln(3/4) + \ln(1/4) = -3.977 \text{ (rounded)}$$
- To classify this email, compare -3.260 against -3.977, and take the larger one. That's -3.260, which is the SPAM number. So this email is classified as spam, which is the correct classification (marked as "right" in the output). 

## At the end of the project

-   As you are preparing to submit the project, please prepare a text file (`.txt`, pdf, or Word doc is fine) answering the following questions:
    1.  What bugs and conceptual difficulties did you encounter? How did you overcome them? What did you learn?
    2.  Describe whatever help (if any) that you received. Don’t include readings, lectures, and exercises, but do include any help from other sources, such as websites or people (including classmates and friends) and attribute them by name.
    3.  Describe any serious problems you encountered while writing the program.
    4.  Mention any challenges that you did.
    5.  List any other feedback you have. Feel free to provide any feedback on how much you learned from doing the assignment, and whether you enjoyed doing it.
-   Please also add a comment at the top of your program stating your name and a pledge that you have followed the honor code and collaboration policy for this project. This can be as simple as writing “**I have neither given nor received unauthorized aid on this program.**” You can find the collaboration policy on the syllabus.

## Grading

- You will be graded on correctness of your program, including the formatting (this makes it easier to grade).
- Your project will also be graded on the appropriateness and efficiency of the algorithms you choose, and on coding style.

## Submission instructions

Through Canvas, upload all your source code files and your file with the answers to the questions above.

## Challenges

Before you attempt the challenge, get the main program working first, and make sure your output matches mine! 
  Then save a copy of your original program before you start modifying it, because I'll still want to run the original 
    version before I start grading the extra credit version.

- Add additional features to the model or change the existing features as you see fit to try to improve the accuracy of the classification. 
  You should still use the Naive Bayes setup, so don't muck around with the math, but you can add new features for e.g., length of the email,
   words present/absent in subject vs body, word count instead of just presence/absence, etc.
