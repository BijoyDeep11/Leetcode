# 202. Happy Number

## Difficulty

Easy

## Pattern

Hash Set + Cycle Detection

## Repeated Operation

Repeatedly replace the number with the sum of the squares of its digits until it becomes `1` or enters a cycle.

## Data Structure Chosen

`unordered_set<int>`

## Why?

An `unordered_set` is used to keep track of the numbers that have already been encountered. If the same number appears again, it indicates that the process has entered a cycle and will never reach `1`.

## Algorithm

1. Create an empty `unordered_set<int>` to store the numbers that have already been seen.
2. Repeat the following steps:

   * If the current number is `1`, return `true` because it is a happy number.
   * If the current number already exists in the set, return `false` because a cycle has been detected.
   * Insert the current number into the set.
   * Calculate the sum of the squares of its digits:

     * Extract the last digit using the modulo operator (`% 10`).
     * Square the digit and add it to a running sum.
     * Remove the last digit by dividing the number by `10`.
   * Replace the current number with the calculated sum.
3. Continue the process until either `1` is reached or a repeated number is found.

## Complexity

* **Time:** `O(log n)` per iteration (digit processing), with a bounded number of iterations before reaching `1` or a cycle.
* **Space:** `O(log n)` for storing previously seen numbers.

> **Note:** In practice, the sequence quickly converges to either `1` or a small repeating cycle, making the algorithm very efficient.

## What I Learned

* An `unordered_set` is an excellent choice for detecting cycles because it provides average **O(1)** lookup and insertion.
* Some iterative problems naturally form cycles, and storing previously visited states is an effective way to detect them.
* Modulo (`%`) and division (`/`) operations can be used to process each digit of a number without converting it to a string.
* This problem introduced me to the concept of **cycle detection using a hash set**, a technique that appears in many graph and mathematical problems.
* Recognizing repeated states is often the key to preventing infinite loops in algorithms.
