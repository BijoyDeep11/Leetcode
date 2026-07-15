# 682. Baseball Game

## Difficulty

Easy

## Pattern

Stack Simulation

## Repeated Operation

Process each operation while maintaining the most recent valid scores.

## Data Structure Chosen

`stack<int>`

## Why?

A stack is the ideal data structure because every operation depends on the **most recent valid score**. The **LIFO (Last In, First Out)** property allows efficient access, modification, and removal of the latest score.

## Algorithm

1. Create an empty `stack<int>` to store valid scores.
2. Traverse the `operations` array one by one.
3. For each operation:

   * If it is an **integer**, convert it to an integer and push it onto the stack.
   * If it is `"+"`, add the last two valid scores and push the result onto the stack.
   * If it is `"D"`, double the most recent valid score and push it onto the stack.
   * If it is `"C"`, remove the most recent valid score by popping the stack.
4. After processing all operations, traverse the stack and calculate the sum of all remaining scores.
5. Return the final sum as the total score.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

> **Note:** `n` is the number of operations.

## What I Learned

* A stack is useful whenever a problem revolves around the **most recently added element**.
* Some stack problems require temporarily removing elements (such as when calculating the `"+"` operation) and then restoring them to preserve the correct order.
* Different operations can be simulated efficiently by using stack operations like `push()`, `pop()`, and `top()`.
* After completing all operations, the remaining elements in the stack represent the valid scores, whose sum gives the final answer.
