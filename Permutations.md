# 46. Permutations

## Difficulty

Medium

## Pattern

Recursion + Backtracking

## Repeated Operation

Choose an unused element at every recursion level and build every possible ordering of the given array.

## Data Structure Chosen

* `unordered_set<int>` for tracking used elements
* `vector<int>` for the current permutation
* `vector<vector<int>>` for storing all permutations

## Why?

A permutation requires every element to appear exactly once, but the **order of the elements matters**. At every recursion level, I need to choose one element that has not already been used.

The `unordered_set` helps track which elements have already been selected, while recursion explores the different possible choices. Backtracking removes the selected element after returning from the recursive call so that it can be considered in another position.

## Algorithm

1. Create an empty result vector to store all permutations.
2. Create a temporary vector to store the current permutation.
3. Create an `unordered_set<int>` named `used` to track the elements already selected.
4. Start the recursive function with an empty current permutation.
5. **Base Case:**

   * If the size of the current permutation becomes equal to the size of the input array, add it to the result and return.
6. Loop through every element of the input array.
7. Check whether the current element already exists in the `used` set.

   * If it is already used, skip it using `continue`.
8. If the element has not been used:

   * Add it to the current permutation.
   * Insert it into the `used` set.
   * Recursively continue building the permutation.
9. After the recursive call:

   * Remove the element from the current permutation using `pop_back()`.
   * Remove the element from the `used` set.
10. Continue exploring the remaining choices until all possible permutations have been generated.
11. Return the result vector.

## Complexity

* **Time:** `O(n × n!)`
* **Space:** `O(n)` auxiliary space, excluding the output.

> **Note:** There are `n!` possible permutations for `n` distinct elements, and each permutation contains `n` elements, resulting in `O(n × n!)` time when accounting for storing the permutations.

## What I Learned

* Unlike subsets, where the order of elements does not matter, **permutations depend on the order** in which elements are selected.
* At every recursion level, I can choose any element that has not already been used.
* An `unordered_set` can be used to efficiently track whether an element has already been selected.
* **Backtracking** is essential: after exploring a choice, I must undo that choice using `pop_back()` and erase it from the `used` set.
* The base case is reached when the current permutation contains the same number of elements as the original array.
* This problem helped me understand a different form of recursion and backtracking where there is **no fixed pick/not-pick branch**. Instead, every unused element becomes a possible choice at each level.
* I also learned the fundamental difference between **combinations and permutations**: combinations care about which elements are selected, while permutations also care about their ordering.
