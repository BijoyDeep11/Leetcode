# 258. Add Digits

## Difficulty

Easy

## Pattern

Mathematics (Digital Root)

## Repeated Operation

Repeatedly add the digits of a number until only a single digit remains.

## Data Structure Chosen

None

## Why?

This problem can be solved entirely using mathematical operations. While a brute-force solution repeatedly extracts and sums digits, the optimized solution uses the **Digital Root** property to compute the answer in constant time without any loops.

## Algorithm

### Approach 1: Brute Force

1. While the number has more than one digit (`num >= 10`):

   * Initialize `sum = 0`.
   * Extract the last digit using the modulo operator (`num % 10`).
   * Add the extracted digit to `sum`.
   * Remove the last digit by dividing the number by `10`.
   * Repeat until all digits have been added.
2. Replace `num` with `sum`.
3. Continue the process until `num` becomes a single-digit number.
4. Return `num`.

### Approach 2: Digital Root (Optimized)

1. If `num == 0`, return `0`.
2. If `num % 9 == 0`, return `9`.
3. Otherwise, return `num % 9`.

## Complexity

### Brute Force

* **Time:** `O(log n)`
* **Space:** `O(1)`

### Digital Root

* **Time:** `O(1)`
* **Space:** `O(1)`

## What I Learned

* A straightforward solution is to repeatedly sum the digits until a single digit remains.
* The modulo (`%`) and division (`/`) operators are useful for extracting and removing digits from an integer.
* The **Digital Root** concept provides a mathematical shortcut that eliminates the need for loops.
* Special edge cases are important:

  * If the number is `0`, the answer is `0`.
  * If the number is a multiple of `9` (except `0`), the answer is `9`.
  * Otherwise, the answer is simply `num % 9`.
* This problem showed me how recognizing a mathematical pattern can reduce the time complexity from repeated iteration to **constant time**.
