# Twenty-Six

A simple console program to play the classic dice game "Twenty-Six"

## Description

The game prints to the console. Program will request initial "bank amount" from user input and play a game of Twenty-Six. I used C++ to practice my proficiency in the language. The program demonstrates my understanding of basic OOP principles, particularly class implementation.

## Rules of Twenty-Six

Twenty-Six is a gambling game popular in the 1930s-50s.
The player chooses a number from 1 to 6 as his point number.  He then throws the ten dice 13 times.  His score is the number of times that his point number is thrown.
Payouts are determined by the score.

  **Score  :  Payout**

- 10 or less  : 10  
- 13          : 5  
- 26          : 4  
- 27          : 5  
- 28          : 6  
- 29          : 8  
- 30 or more  : 10  

Any other score loses.

source: http://www.dice-play.com/Games/TwentySix.htm

## Usage

Requires a linux terminal
Includes makefile that will create and executable called 'main'. Download all files and place in the same folder. Navigate to the folder with files in your linux terminal, and make executable

```bash
$ make
```

run main

```bash
$ ./main
```

