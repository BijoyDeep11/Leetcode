# 77. Combinations

## Difficulty

Medium

## Pattern

Recursion + Backtracking

## Repeated Operation

Choose `k` unique elements from the numbers `1` to `n` without considering the order of selection.

## Data Structure Chosen

* `vector<int>` for the current combination
* `vector<vector<int>>` for storing all valid combinations

## Why?

The problem requires generating all possible combinations of exactly `k` numbers selected from `1` to `n`. Recursion allows me to explore each possible choice, while backtracking lets me remove a selected number and try the next possibility.

Since combinations do not depend on ordering, I always move forward through the numbers instead of considering previously selected numbers again.

## Algorithm

1. Create a result vector to store all combinations.
2. Create a temporary vector to store the current combination.
3. Start the recursive function from `i = 1`.
4. **Base Case:**

   * If the size of the current combination becomes equal to `k`, add it to the result and return.
5. Run a loop from the current index `i` to `n`.
6. For every number:

   * Add the number to the current combination.
   * Recursively call the function with the next number (`i + 1`).
   * Remove the selected number using `pop_back()` to backtrack.
7. Continue exploring until all possible combinations of size `k` have been generated.
8. Return the result vector.

## Complexity

* **Time:** `O(C(n, k) × k)`
* **Space:** `O(k)` auxiliary space, excluding the output.

> **Note:** There are `C(n, k)` possible combinations, and each combination contains `k` elements.

## What I Learned

* **Combinations** differ from permutations because the order of selected elements does not matter.
* By always moving the iterator forward, I ensure that the same combination is not generated in different orders.
* The base case is reached when the current combination contains exactly `k` elements.
* **Backtracking** allows me to select an element, explore all possibilities with it, and then remove it before trying the next element.
* The core pattern is:

  ```text
  Choose → Recurse → Undo
  ```
* This problem strengthened my understanding of how recursion and backtracking can be used to generate combinations without producing duplicate orderings.
