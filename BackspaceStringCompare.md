# 844. Backspace String Compare

## Difficulty

Easy

## Pattern

Stack Simulation

## Repeated Operation

Process each string by applying backspace (`#`) operations and compare the final results.

## Data Structure Chosen

`stack<char>`

## Why?

A stack is the best choice because every backspace character (`#`) removes the **most recently added character**. The **LIFO (Last In, First Out)** property of a stack naturally models the behavior of a backspace key.

## Algorithm

1. Create two `stack<char>` variables, one for each string.
2. Traverse the first string:

   * If the current character is not `#`, push it onto the stack.
   * If the current character is `#` and the stack is not empty, pop the top character.
3. Repeat the same process for the second string.
4. After processing both strings, compare the two stacks.
5. If both stacks contain the same characters in the same order, return `true`; otherwise, return `false`.

## Complexity

* **Time:** `O(n + m)`
* **Space:** `O(n + m)`

> **Note:** `n` and `m` are the lengths of the two input strings.

## What I Learned

* A stack is an excellent choice for simulating editor-like operations such as the backspace key.
* Before performing a `pop()` operation, it is important to check whether the stack is empty to avoid runtime errors.
* Problems that require repeatedly removing the most recently added element often become straightforward when solved with a stack.
* Processing both strings independently and then comparing their final contents is a clean and efficient approach to solving this problem.
