# 17. Letter Combinations of a Phone Number

## Difficulty

Medium

## Pattern

Recursion + Backtracking

## Repeated Operation

For each digit, try every letter mapped to that digit and recursively build all possible letter combinations.

## Data Structure Chosen

* `unordered_map<char, string>` for digit-to-letter mapping
* `string` for the current combination
* `vector<string>` for storing all valid combinations

## Why?

Each digit from `2` to `9` is associated with multiple letters on a traditional phone keypad. To generate every possible combination, I need to explore every possible letter for each digit.

**Recursion** allows me to move through the digits one by one, while **backtracking** allows me to remove the previously selected letter and try the next possibility.

## Algorithm

1. Create a mapping between each digit and its corresponding letters:

   ```text
   2 → abc
   3 → def
   4 → ghi
   5 → jkl
   6 → mno
   7 → pqrs
   8 → tuv
   9 → wxyz
   ```
2. If the input string is empty, return an empty result.
3. Create a temporary string to store the current combination.
4. Start the recursive function from index `0`.
5. **Base Case:**

   * If the current index reaches the end of the input string, add the current combination to the result vector and return.
6. Get the letters corresponding to the current digit from the mapping.
7. Loop through every letter mapped to the current digit.
8. For each letter:

   * Add it to the current combination.
   * Recursively process the next digit.
   * Remove the selected letter using backtracking.
9. Continue until every possible combination has been generated.
10. Return the result vector.

## Complexity

* **Time:** `O(4ⁿ × n)`
* **Space:** `O(n)` auxiliary space, excluding the output.

> **Note:** `n` is the number of digits in the input. Each digit can map to at most 4 letters, so there can be up to `4ⁿ` combinations. The additional `n` factor accounts for constructing each combination.

## What I Learned

* Phone keypad problems are a natural application of **recursion and backtracking** because every digit creates multiple possible choices.
* A mapping is useful for storing the relationship between each digit and its corresponding letters.
* At every recursive level, I choose one letter from the current digit and then move to the next digit.
* **Backtracking** is performed by removing the selected letter after the recursive call so that the next possible letter can be explored.
* Unlike the traditional **pick/not-pick** pattern, this problem has **multiple choices at each recursion level**, one for every letter associated with the current digit.
* The base case occurs when all input digits have been processed, at which point the current combination represents one complete answer.
* This problem helped me understand that backtracking is not limited to two choices. It can be used whenever we need to explore **multiple choices at every level of a decision tree**.
