# 78. Subsets

## Difficulty

Medium

## Pattern

Recursion + Backtracking

## Repeated Operation

For every element, make two choices: **pick the element** or **do not pick the element**.

## Data Structure Chosen

* `vector<int>` for the current subset
* `vector<vector<int>>` for storing all subsets

## Why?

The problem requires generating **every possible subset**, including the empty subset. For every element, there are exactly two choices: either include it in the current subset or exclude it. This naturally forms a **binary recursion tree**, making recursion and backtracking a suitable approach.

## Algorithm

1. Create a result vector to store all possible subsets.
2. Create a temporary vector to store the current subset.
3. Start the recursive function from index `0`.
4. **Base Case:**

   * If the current index reaches the size of the original array, add the current subset to the result and return.
5. At every index, create two recursive branches:

   * **Pick:** Add the current element to the subset, recursively move to the next index, and then remove the element using backtracking.
   * **Not Pick:** Do not add the current element and recursively move to the next index.
6. Continue until every possible combination has been generated.
7. Return the result containing the complete power set.

## Complexity

* **Time:** `O(n × 2ⁿ)`
* **Space:** `O(n)` auxiliary space for the recursion stack and current subset, excluding the output.

> **Note:** There are `2ⁿ` possible subsets for an array of `n` elements. Each subset may take up to `O(n)` time to copy into the result.

## What I Learned

* Every element in a subset problem has two possibilities: **pick** or **not pick**.
* This naturally creates a **binary recursion tree** with `2ⁿ` possible outcomes.
* The base case is reached when the iterator reaches the size of the original array.
* **Backtracking** allows me to temporarily include an element, explore all possibilities with it, and then remove it before exploring the branch where it is not included.
* The empty subset is automatically generated when the recursion reaches the base case without picking any elements.
* This problem helped strengthen my understanding of the fundamental **pick/not-pick pattern**, which is one of the most important patterns in recursion and backtracking problems.
