# 20. Valid Parentheses

## Difficulty

Easy

## Pattern

Stack

## Repeated Operation

Match every closing bracket with its corresponding opening bracket.

## Data Structure Chosen

`stack<char>`

## Why?

A stack follows the **Last In, First Out (LIFO)** principle, which is ideal for matching brackets. The most recently opened bracket must be the first one to be closed, making a stack the perfect data structure for this problem.

## Algorithm

1. Create an empty `stack<char>` named `st`.
2. Traverse the given string character by character.
3. If the current character is an opening bracket (`(`, `{`, `[`), push it onto the stack.
4. If the current character is a closing bracket:

   * Check if the stack is empty. If it is, return `false`.
   * Otherwise, compare the top element of the stack with the corresponding opening bracket.
   * If they match, pop the top element from the stack.
   * If they do not match, return `false`.
5. After traversing the entire string, check whether the stack is empty.
6. If the stack is empty, return `true`; otherwise, return `false`.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

> **Note:** `n` is the length of the input string.

## What I Learned

* A stack is the most suitable data structure for problems involving balanced symbols or nested structures.
* The **LIFO (Last In, First Out)** property naturally matches the requirement that the most recently opened bracket must be closed first.
* Before accessing the top of a stack, it is important to check whether the stack is empty to avoid runtime errors.
* A valid parentheses string is one in which every opening bracket has a matching closing bracket, the brackets are closed in the correct order, and no unmatched brackets remain after processing the entire string.
