# 496. Next Greater Element I

## Difficulty

Easy

## Pattern

Monotonic Stack + Hash Map

## Repeated Operation

For each element, find the next greater element to its right using a **monotonic decreasing stack**.

## Data Structure Chosen

* `stack<int>`
* `unordered_map<int, int>`
* `vector<int>`

## Why?

* **`stack<int>`** is used as a **monotonic decreasing stack** to efficiently find the next greater element for every number.
* **`unordered_map<int, int>`** stores each element from `nums2` along with its next greater element, allowing constant-time lookups.
* **`vector<int>`** stores the final answer for all elements in `nums1`.

## Algorithm

1. Create an empty `stack<int>`, an `unordered_map<int, int>`, and a result vector.
2. Traverse the `nums2` array from **right to left**.
3. For each element:

   * While the stack is not empty and the top of the stack is **less than or equal to** the current element, pop the stack.
   * If the stack becomes empty, map the current element to `-1` because no greater element exists on its right.
   * Otherwise, map the current element to the top of the stack, which is its next greater element.
   * Push the current element onto the stack.
4. After preprocessing `nums2`, traverse the `nums1` array.
5. For each element in `nums1`, retrieve its next greater element directly from the hash map and add it to the result vector.
6. Return the result vector.

## Complexity

* **Time:** `O(n + m)`
* **Space:** `O(m)`

> **Note:**
>
> * `n` is the size of `nums1`.
> * `m` is the size of `nums2`.

## What I Learned

* A **monotonic decreasing stack** is a powerful technique for solving "next greater" and "next smaller" problems in linear time.
* Traversing the array from **right to left** ensures that the stack always contains the potential next greater elements.
* Combining a **stack** with a **hash map** allows preprocessing one array and answering queries for another array in constant time.
* This problem introduced me to the concept of **monotonic stacks**, which is a common pattern used in many advanced DSA problems involving nearest greater or smaller elements.
