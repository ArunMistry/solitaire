# Solitaire

This is a simple game that I made using C. The goal of peg solitaire is to remove all pegs until only one is left at the center, by moving a peg over another to remove the peg jumped over.

I have used abstraction to separate code into different files, and added comments wherever necessary. Feel free to look at my code and leave any comments!

## Installation
To install with GCC, and to play the game:
```
>>   gcc game.c func.c -o game
>>   ./game
```

## Instructions
Input can either be a **`coordinate + direction`**, or a special input.

**Moving Pegs**: Enter a coordinate as shown on the terminal, followed by a direction.
>**Example: 15s, 36a, 44w, 52d**

**Special Inputs**: Enter **`u`** to undo once, **`r`** to restart the game, or **`q`** to quit the game.

## Solution
A sample set of solutions is provided in solutions.txt