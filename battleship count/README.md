# Battleship Count
Given a board m*k size count the amount of battleships that are on the board.

Battleships are only straight, and they cannot be adjacent to each other.

# Examples

>Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]] \
>Output: 2

>Input: board = [["."]] \
>Output: 0
 
# Explanation
The solution is to check for only the left most corner of every battleship. Once you encounter it or a part of any other battleship you can skip one rotation of the loop since they cannot be adjacent.