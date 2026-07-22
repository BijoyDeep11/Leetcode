# 739. Daily Temperatures

## Difficulty

Medium

## Pattern

Monotonic Stack

## Repeated Operation

For each day, find the number of days until a warmer temperature appears.

## Data Structure Chosen

* `stack<int>`
* `vector<int>`

## Why?

* **`stack<int>`** is used as a **monotonic decreasing stack**, but instead of storing temperature values, it stores their **indices**.
* Storing indices allows us to calculate the number of days between the current day and the next warmer day by subtracting their indices.
* **`vector<int>`** is used to store the final answer for each day.

## Algorithm

1. Create an empty `stack<int>` to store the indices of temperatures.
2. Initialize a result vector of size `n` with all values as `0`.
3. Traverse the temperature array from **right to left**.
4. For each temperature:

   * While the stack is not empty and the temperature at the index on the top of the stack is **less than or equal to** the current temperature, pop the stack.
   * If the stack becomes empty, there is no warmer day ahead, so the answer for the current day remains `0`.
   * Otherwise, the next warmer day is at the index on the top of the stack. Store the difference `st.top() - i` in the answer vector.
   * Push the current index onto the stack.
5. After processing all the temperatures, return the result vector.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

> **Note:** `n` is the number of days (the length of the temperature array).

## What I Learned

* A **monotonic stack** can store **indices** instead of values whenever the distance or position between elements is required.
* Traversing the array from **right to left** ensures that the stack always contains candidate indices for the next warmer day.
* Using indices makes it easy to compute the answer as `st.top() - i`, representing the number of days until a warmer temperature occurs.
* This problem strengthened my understanding of the **monotonic stack** pattern and showed how the same concept can be adapted by storing indices instead of values.
