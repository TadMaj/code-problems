# Find Kth largest
Given an array return the kth largest variable.

# Examples
>Input: nums = [3,2,1,5,6,4], k = 2 \
>Output: 5

> Input: nums = [3,2,3,1,2,4,5,5,6], k = 4 \
> Output: 4

# Explanation
This implementation is really simple. All of the nums get pushed into a priority queue which just gets popped k-1 times and then the top value gets returned.