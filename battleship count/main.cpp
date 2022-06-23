#include <iostream>
#include <vector>

int countBattleships(std::vector<std::vector<char>>& board);

int main() {
    std::vector<char> vec1 = {'X','.','.','X'};
    std::vector<char> vec2 = {'.','.','.','X'};
    std::vector<char> vec3 = {'.','.','.','X'};
    std::vector<std::vector<char>> board = {vec1, vec2, vec3};

    std::cout << countBattleships(board) << std::endl;
    return 0;
}

int countBattleships(std::vector<std::vector<char>>& board) {
    int result = 0;
    int imax = board.size();
    int xmax = board[0].size();
    for (int i = 0; i < imax; i++) {
        for (int x = 0; x < xmax; x++) {
            if (board[i][x] == 'X' && ((i == 0 || board[i-1][x] != 'X') && (x == 0 || board[i][x-1] != 'X'))) {
                result++;
            }
            if (board[i][x] == 'X' && xmax-1 > x+1) x++;
        }
    }

    return result;
}