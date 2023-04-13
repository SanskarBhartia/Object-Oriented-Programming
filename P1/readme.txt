Program for Wordle program
Author: Sanskar Bhartia

ABOUT:

The code is designed to go through the Solution.txt file to find all possible 5 letter words. The program goes through each letter in the alphabet and then sees which is correct. It then guesses the word according to the rules given.


-----------------------------------------------------------------------------------------------------
COMPILING:

-GNU debugger
-Atom compiler
-Terminal on Mac

--------------------------------------------------------------------------------------------------------
Run the Code:


The code can be compiled with the provided makefile using the standard `make`
command. To run the code simply download and unzip the tar files via terminal (tar zcvf )or any online website.
Run the makefile on the linux/Mac system by typing into the terminal: 

Run the makefile by typing onto terminal: make
Then type:

./word to run the program





-----------------------------------------------------------------------------------------------------
Sample Output:
Reading cache...  [OK]
Main Menu
=========
NEW: start a new game.
LOAD <num>: load a specific game
HELP: More information
EXIT: End game
The game number must be in range of 1-2315
Input: LOAD 1
Running game #1
word	unused alphabet
====	===============
Guess 0: aahed	#o___	_bc__fg_ijklmnopqrstuvwxyz
Guess 2: aalii	#o___	_bc__fg__jk_mnopqrstuvwxyz
Guess 4: aargh	#o___	_bc__f___jk_mnopq_stuvwxyz
Guess 6: aarti	#o___	_bc__f___jk_mnopq_s_uvwxyz
Guess 8: abaca	####_	_____f___jk_mnopq_s_uvwxyz
Guess 10: abaci	####_	_____f___jk_mnopq_s_uvwxyz
Guess 12: aback	
The word was aback	You win