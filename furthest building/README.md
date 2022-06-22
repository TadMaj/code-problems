# Furthest Building
Given a set of building heights and an amount of bricks and ladders find how far you can travel.

You can travel through buildings that are lower or as high as the current building. When encountering building that are higher you need to either use a ladder or bricks to climb up.

# Example
>Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1 \
>Output: 4

> Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2 \
> Output: 7

> Input: heights = [14,3,19,3], bricks = 17, ladders = 0 \
> Output: 3

# Explanation
The code works by ordering all the passed buildings by size. Since the optimal solution is always to use a ladder on the highest building. The buildings to use a ladder on can be easily decided by ordering the already passed buildings and using a ladder retrospectively. 