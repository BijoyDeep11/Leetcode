# 128. Longest Consecutive Sequence

## Difficulty

Medium

## Pattern

Hash Set

## Repeated Operation

Find the starting point of each consecutive sequence and count how long the sequence continues.

## Data Structure Chosen

`unordered_set<int>`

## Why?

An `unordered_set` allows me to store all the elements of the array and perform average `O(1)` lookup operations.

The important observation is that I do not need to start counting from every element. I only start a sequence when the **previous element is absent** from the set.

For example:

```text
1, 2, 3, 4
```

For `1`, `0` is not present, so `1` is a starting point.

For `2`, `1` is already present, so I skip it because it is already part of an existing sequence.

This prevents unnecessary work and allows the problem to be solved in linear average time.

## Algorithm

1. Create an `unordered_set<int>` and insert every element from the input array.
2. Initialize a variable to store the length of the longest consecutive sequence.
3. Traverse through the elements of the set.
4. For each element, check whether its previous element (`num - 1`) exists in the set.
5. If the previous element exists, the current element is **not** the beginning of a sequence, so continue.
6. If the previous element does not exist, mark the current element as the starting point.
7. Initialize:

   ```cpp
   int current = num;
   int count = 1;
   ```
8. Use a `while` loop to check whether the next consecutive element (`current + 1`) exists in the set.
9. If it exists:

   * Increment `current`.
   * Increment `count`.
10. Update the maximum sequence length.
11. Continue until all possible starting points have been checked.
12. Return the maximum length.

## Complexity

* **Time:** `O(n)` average
* **Space:** `O(n)`

> **Note:** Although there is a nested `while` loop, the overall average time complexity remains `O(n)` because each element belongs to a consecutive sequence and is effectively processed a constant number of times across the sequence-expansion process.

## What I Learned

* An `unordered_set` is useful when I need fast existence checks without caring about ordering.
* The key observation in this problem is identifying the **starting point** of a consecutive sequence.
* An element is a starting point only when its previous element is absent:

  ```cpp
  if (st.find(num - 1) == st.end())
  ```
* Once a starting point is found, I can keep checking for `num + 1`, `num + 2`, and so on until the sequence ends.
* Simply sorting the array would also solve the problem, but using a hash set allows me to achieve **O(n) average time** instead of relying on sorting.
* This problem strengthened my understanding of how recognizing the right starting condition can prevent unnecessary repeated work in an algorithm.
