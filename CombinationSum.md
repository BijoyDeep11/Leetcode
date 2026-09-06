# 39. Combination Sum

## Difficulty

Medium

## Pattern

Recursion + Backtracking

## Repeated Operation

Explore all possible combinations whose elements add up to the given target, while allowing the same element to be chosen multiple times.

## Data Structure Chosen

* `vector<int>` for the current combination
* `vector<vector<int>>` for storing all valid combinations

## Why?

The problem requires exploring multiple possible combinations, making **recursion and backtracking** a natural choice. For every element, I have two choices: **pick** it or **not pick** it.

Since the problem allows an element to be used multiple times, the iterator is **not incremented when I pick an element**. When I choose not to pick it, I move to the next element.

## Algorithm

1. Create a result vector to store all valid combinations.
2. Create a temporary vector to store the current combination.
3. Start the recursive function with index `0` and current sum `0`.
4. Handle the base cases:

   * If the current sum becomes equal to the target, add the current combination to the result and return.
   * If the current sum becomes greater than the target, return because the current combination is no longer valid.
   * If the iterator reaches the end of the array, return because there are no more elements to consider.
5. Create two recursive branches:

   * **Pick:** Add the current element to the combination and recursively call the function **without incrementing the iterator**, because the same element can be selected again.
   * **Not Pick:** Remove the current element if necessary and recursively move to the next index.
6. Use backtracking to remove the selected element after exploring the pick branch.
7. Continue until all possible combinations have been explored.
8. Return the result containing all valid combinations.

## Complexity

* **Time:** Exponential, approximately `O(2ⁿ)` in the general recursion-tree sense, with the exact complexity depending on the target and candidate values.
* **Space:** `O(n)` auxiliary space for the recursion stack and current combination, excluding the output.

> **Note:** Because the same element can be selected multiple times, the recursion tree can be deeper than `n`. The exact complexity depends heavily on the values in `candidates` and the target.

## What I Learned

* The **pick/not-pick pattern** can be adapted depending on whether repetition is allowed.
* In this problem, when I **pick** an element, I do not increment the iterator because that element can be selected again.
* When I choose **not to pick**, I increment the iterator to consider the next candidate.
* Backtracking allows me to explore a combination, store it if it reaches the target, and then undo the previous choice before exploring another possibility.
* Multiple base cases are important in recursive problems to stop branches that can no longer produce a valid answer.
* This problem strengthened my understanding of how the **same recursion pattern can be modified based on the constraints of the problem**, especially whether elements can be reused.
