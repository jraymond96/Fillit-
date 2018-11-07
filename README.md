# fillit2k17

My first project realised in group, jordan auplat (github.com/jauplat) and me jeremi raymond.

## DESCRIPTION

Fillit is programe who sort in the smallest possible square many Tetrominos given in parametre. ($> fillit tetro.txt)

## Tetrominos Description

# A Tetrimino is a classic piece of Tetris composed of 4 blocks
# Each block of a Tetromino must touch at least one other block on any of his 4 sides. (up, down, left and right)

Example of tetro.txt :

. . . #

. . . #

. . . #

. . . #

\n

. # . .

. # # #

. . . .

. . . .

## OBJECTIFS AND GOAL OF THIS PROJECT

# Learn how read in file with fonction open and read
# creat algorithme who said if "tetro.txt" are valide or not : 

. . . #

. # . .

. # . .

. . . .

is invalid tetromino so executable can't resolve and exit properly with an error massage. (lot other error exists)

# The most hardest part : backtracking algoritm.

Backtrack algorithm is very powerfull if we needed to resolve a problematic like sudoku or other. The simplest discription of our algo is, we started with the littlest map possible (4 * 4 if juste one tetromino, else depend of numbers of tetromino) and we test to place all the tetros at all the places possible of the map for all tetros existing
