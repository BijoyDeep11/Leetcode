# 125. Valid Palindrome

## Difficulty

Easy

## Pattern

String Processing

## Repeated Operation

Filter the valid characters, convert them to lowercase, and compare the processed string with its reverse.

## Data Structure Chosen

`string`

## Why?

A new string is used to store only the **alphanumeric characters** from the original input after converting them to lowercase. This simplifies the comparison by ignoring spaces, punctuation, and letter casing.

## Algorithm

1. Create an empty string to store the processed characters.
2. Traverse the given string character by character.
3. For each character:

   * Check if it is an alphanumeric character using `isalnum()`.
   * If it is, convert it to lowercase using `tolower()`.
   * Append the lowercase character to the new string.
4. Create another string as a copy of the processed string.
5. Reverse the copied string using the `reverse()` function from the `<algorithm>` library.
6. Compare the processed string with the reversed string.
7. If both strings are equal, return `true`; otherwise, return `false`.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

> **Note:** `n` is the length of the input string.

## What I Learned

* String preprocessing can simplify many problems by removing unnecessary characters before applying the main logic.
* The `isalnum()` function is useful for checking whether a character is an alphabet or a digit.
* The `tolower()` function helps perform case-insensitive comparisons.
* The `reverse()` function from the `<algorithm>` library provides an easy way to reverse a string.
* This problem strengthened my understanding of string manipulation and standard library functions in C++.
