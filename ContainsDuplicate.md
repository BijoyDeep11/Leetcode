# Contains Duplicate Solution (C++)

## Problem Statement

Given an integer array `nums`, determine whether the array contains any duplicate element.

* Return `true` if any value appears at least twice in the array.
* Return `false` if every element is distinct.

---

## Approach

To solve this problem efficiently, I used the **C++ STL `unordered_set`**.

### Steps

1. Declare an `unordered_set` to store the elements that have already been seen.
2. Traverse the array `nums` using a loop.
3. For each element, check whether it already exists in the `unordered_set`.
4. If the element is found, it means a duplicate exists, so return `true`.
5. Otherwise, insert the current element into the set.
6. If the loop completes without finding any duplicate, return `false`.

---

## Data Structure Used

* **`unordered_set`**

  * Stores only unique elements.
  * Provides an average **O(1)** time complexity for both insertion and lookup operations.
  * Since the problem only requires checking the existence of elements and does not require maintaining any order, `unordered_set` is a better choice than `set`.

---

## Why `unordered_set` Instead of `set`?

| `unordered_set`                       | `set`                              |
| ------------------------------------- | ---------------------------------- |
| Average lookup: **O(1)**              | Lookup: **O(log n)**               |
| Average insertion: **O(1)**           | Insertion: **O(log n)**            |
| Does not maintain sorted order        | Maintains elements in sorted order |
| Best suited for fast existence checks | Used when sorted order is required |

Since this problem only requires checking whether an element has already been seen, `unordered_set` provides a more efficient solution.

---

## Time Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

---

## Conclusion

By using an `unordered_set`, I efficiently checked for duplicate elements in a single traversal of the array. This reduced the time complexity from the brute-force approach of **O(n²)** to **O(n)**, making it an optimal solution for the **Contains Duplicate** problem and marking the second problem in my LeetCode journey.
