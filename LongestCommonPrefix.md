# 14. Longest Common Prefix

## Difficulty

Easy

## Pattern

String Traversal

## Repeated Operation

Compare the characters of the first string with the corresponding characters of every other string until a mismatch is found.

## Data Structure Chosen

None

## Why?

This problem can be solved by directly comparing characters across all the strings. No additional data structure is required because the comparison is performed in place.

## Algorithm

1. Handle the edge cases:

   * If the list of strings is empty, return an empty string.
   * If the list contains only one string, return that string.
2. Use the first string as the reference.
3. Traverse each character of the first string.
4. For every character, compare it with the character at the same index in all the remaining strings.
5. If:

   * Any string ends before the current index, or
   * The characters do not match,

   return the prefix formed so far.
6. If all characters of the first string match in every string, return the entire first string as the longest common prefix.

## Complexity

* **Time:** `O(n × m)`
* **Space:** `O(1)`

> **Note:**
>
> * `n` is the number of strings.
> * `m` is the length of the shortest string.

## What I Learned

* The first string can be used as a reference for comparing prefixes with all other strings.
* As soon as a mismatch is found, the search can stop because no longer common prefix is possible.
* Handling edge cases at the beginning simplifies the implementation:

  * Empty list → return an empty string.
  * Single string → return the string itself.
  * A string shorter than the current comparison index limits the maximum possible prefix length.
* This problem strengthened my understanding of character-by-character string traversal and early termination techniques for improving efficiency.
