# 347. Top K Frequent Elements

## Difficulty

Medium

## Pattern

Hash Map + Sorting

## Repeated Operation

Count the frequency of each element, sort the elements based on their frequencies, and return the top `k` frequent elements.

## Data Structure Chosen

* `unordered_map<int, int>`
* `vector<pair<int, int>>`
* `vector<int>`

## Why?

* **`unordered_map`** is used to efficiently count the frequency of every element in the array.
* **`vector<pair<int, int>>`** stores the `(element, frequency)` pairs so they can be sorted according to frequency.
* **`vector<int>`** is used to store the final answer containing only the top `k` frequent elements.

## Algorithm

1. Create an `unordered_map<int, int>` to store the frequency of each element.
2. Traverse the input array and increment the frequency of every number in the map.
3. Convert the map into a `vector<pair<int, int>>`, where each pair contains an element and its frequency.
4. Sort the vector in descending order of frequency using a custom comparator function.
5. Create an empty `vector<int>` for the result.
6. Traverse only the first `k` elements of the sorted vector and push their keys (not the frequencies) into the result vector.
7. Return the result vector.

## Complexity

* **Time:** `O(n + m log m)`
* **Space:** `O(m)`

> **Note:**
>
> * `n` is the size of the input array.
> * `m` is the number of distinct elements in the array.

## What I Learned

* Combining a **hash map** with **sorting** is an effective way to solve frequency-based problems.
* A custom comparator function allows sorting based on the frequency instead of the element's value.
* Converting an `unordered_map` into a vector makes it possible to use STL sorting algorithms.
* While this approach is efficient, I learned that there is an even better solution using a **priority queue (heap)**. A **min-heap** or **max-heap** can avoid sorting the entire collection, leading to improved time complexity for this problem.
* Since I had not learned heaps when solving this question, I implemented the sorting-based approach first. I plan to revisit this problem after learning **priority queues**, **min-heaps**, and **max-heaps** to implement the more optimized solution.
