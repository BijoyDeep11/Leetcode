# 724. Find Pivot Index

## Difficulty
Easy

## Pattern
Prefix Sum

## Repeated Operation
Compare the sum of elements to the left of the current index with the sum of elements to the right.

## Data Structure Chosen
None

## Why?
The pivot index is an index where:

```text
sum of elements on the left = sum of elements on the right
```

Instead of calculating the left and right sums repeatedly for every index, I first calculate the **total sum** of the array.

Then, while traversing the array, I can calculate the right sum using:

```text
rightSum = totalSum - currentElement - leftSum
```

This allows me to find the pivot index efficiently without using an additional data structure.

## Algorithm
1. Calculate the total sum of all elements in the array.
2. Initialize:
   ```cpp
   int leftSum = 0;
   ```
3. Traverse the array from left to right.
4. For every index `i`, calculate the right sum:
   ```cpp
   int rightSum = totalSum - nums[i] - leftSum;
   ```
5. Compare `leftSum` and `rightSum`.
   - If they are equal, return the current index `i`.
6. If they are not equal, add the current element to `leftSum`:
   ```cpp
   leftSum += nums[i];
   ```
7. Continue until the entire array has been processed.
8. If no pivot index is found, return `-1`.

## Example

For:

```text
nums = [1, 7, 3, 6, 5, 6]
```

At index `3`:

```text
Left sum  = 1 + 7 + 3 = 11
Right sum = 5 + 6 = 11
```

Therefore:

```text
Pivot Index = 3
```

## Complexity
- **Time:** `O(n)`
- **Space:** `O(1)`

> **Note:** `n` is the size of the input array. The array is traversed twice: once to calculate the total sum and once to find the pivot index. Since both traversals are linear, the overall complexity remains `O(n)`.

## What I Learned
- A **prefix sum** approach can avoid repeatedly calculating sums for the left and right portions of an array.
- Once the total sum is known, the right sum can be calculated using:
  ```text
  rightSum = totalSum - currentElement - leftSum
  ```
- The current element must be excluded from both sides because the pivot element itself belongs to neither the left nor the right portion.
- Updating `leftSum` only after checking the current index is important because the current element should not be included in its own left sum.
- If no index satisfies the condition, returning `-1` indicates that no pivot index exists.
- This problem strengthened my understanding of how **prefix sums and total sums can work together to solve array problems in `O(n)` time and `O(1)` extra space**.