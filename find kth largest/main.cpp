#include <iostream>
#include <vector>
#include <queue>

int findKthLargest(std::vector<int>& nums, int k);

int main() {
    std::vector<int> nums = {3,2,1,5,6,4};
    std::cout << findKthLargest(nums,2);
    return 0;
}

int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> queue;

        for (int i = 0; i < nums.size(); i++) {
            queue.push(nums[i]);
        }

        for (int i = 0; i < k-1; i++) {
            queue.pop();
        }

        return queue.top();
    }