#include <iostream>
#include <vector>
#include <queue>

int furthestBuilding(std::vector<int>& heights, int bricks, int ladders);

int main() {
    std::vector<int> heights = {4,2,7,6,9,14,12};
    std::cout << furthestBuilding(heights, 5, 1) << std::endl;
    return 0;
}

int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
    std::priority_queue<int> queue;

    int totalBricks = 0;
    int totalLadders = 0;
    for (int i = 0; i < heights.size()-1; i++) {
        if (heights[i] >= heights[i+1]) continue;

        int result = heights[i+1] - heights[i];
        totalBricks += result;
        queue.push(result);

        if (totalBricks > bricks && ladders != totalLadders) {
            totalBricks -= queue.top();
            queue.pop();
            totalLadders++;
        }

        if (totalBricks > bricks && ladders == totalLadders) {
            return i;
        }
    }

    return heights.size()-1;
}