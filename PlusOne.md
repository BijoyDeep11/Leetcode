# 66. Plus One

## Difficulty

Easy

## Pattern

Array Traversal

## Repeated Operation

Traverse the array from right to left while handling carry propagation.

## Data Structure Chosen

None

## Why?

This problem can be solved by modifying the given array in place. No additional data structure is required because the carry can be propagated directly while traversing the array from the last digit.

## Algorithm

1. Traverse the array from the last index to the first.
2. For each digit:

   * If the current digit is **less than 9**, increment it by `1` and return the array immediately because no further carry is generated.
   * If the current digit is **9**, change it to `0` and continue moving to the previous digit, propagating the carry.
3. If the loop finishes, it means every digit was `9`.
4. Insert `1` at the beginning of the array to account for the final carry.
5. Return the updated array.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)` *(excluding the output array modification)*

> **Note:** `n` is the number of digits in the input array.

## What I Learned

* Not every array problem requires an extra data structure. Sometimes the input array itself can be modified efficiently.
* Carry propagation is a common concept in problems involving arithmetic on arrays.
* Returning early when a digit is less than `9` avoids unnecessary traversal and makes the solution more efficient.
* An edge case occurs when all digits are `9` (for example, `99` or `999`). In this case, every digit becomes `0`, and a new leading `1` must be inserted to produce the correct result.
* This problem strengthened my understanding of simulating elementary arithmetic operations using arrays.
