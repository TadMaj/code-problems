# Most Frequent Subtree Sum
Given a binary tree compute the most frequent subtree sum. If there are multiple answers return all of them in a vector.

# Examples
>Input: root = [5,2,-3] \
>Output: [2,-3,4]

> Input: root = [5,2,-5] \
> Output: [2]

# Solution
This solution is pretty straightforward. I recursively scale the binary tree and push all the sums on the map. Once all the sums are calculated I can find the largest one.