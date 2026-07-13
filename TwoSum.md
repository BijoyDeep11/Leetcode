# Two Sum Problem Solution (C++)

## Problem Statement

Given an array of integers and a target value, find the two numbers whose sum is equal to the target. Return the indices of those two numbers.

---

## Approach

To solve this problem efficiently, I used the **C++ STL `unordered_map`**.

### Steps

1. Declare an `unordered_map` to store array elements along with their indices.
2. Traverse the array (`nums`) using a loop.
3. For each element, check whether its required complement (`target - nums[i]`) already exists in the map.
4. If the complement is found, return the indices of the current element and the complement.
5. Otherwise, insert the current element and its index into the `unordered_map`.
6. Continue the process until the required pair is found.

---

## Data Structure Used

* **`unordered_map`**

  * Stores each element as the key and its index as the value.
  * Provides an average time complexity of **O(1)** for lookup and insertion operations.

---

## Time Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

---

## Conclusion

By using an `unordered_map`, I reduced the time complexity from the brute-force approach of **O(n²)** to **O(n)**. This allowed me to efficiently solve the **Two Sum** problem and successfully complete my first LeetCode solution.
