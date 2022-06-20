#include <vector>
#include <iostream>

void rotate(std::vector<std::vector<int>>& matrix);
void print(std::vector<std::vector<int>>& matrix);

int main() {
    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    print(matrix);
}

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n/2; i++) {
        for (int x = 0; x < n-1-2*i; x++) {
            int tempValue = matrix[0+i+x][n-i-1];
            matrix[0+i+x][n-i-1] = matrix[0+i][0+i+x];
            matrix[0+i][0+i+x] = matrix[n-i-1-x][0+i];
            matrix[n-i-1-x][0+i] = matrix[n-i-1][n-i-1-x];
            matrix[n-i-1][n-i-1-x] = tempValue;
        }
    }
}

void print(std::vector<std::vector<int>>& matrix) {
    std::cout << "[";
    for (int i = 0; i < matrix.size(); i++) {
        std::cout << "[";
        for (int x = 0; x < matrix.size(); x++) {
            std::cout << matrix[i][x];
            if (x != matrix.size()-1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
    }
    std::cout << "]";
}