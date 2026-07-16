# 49. Group Anagrams

## Difficulty

Medium

## Pattern

Hash Map + Sorting

## Repeated Operation

Generate a canonical key by sorting each string and group all strings with the same sorted representation.

## Data Structure Chosen

`unordered_map<string, vector<string>>`

## Why?

An `unordered_map` is ideal for grouping strings based on a common key. By sorting each string, I can generate a **canonical key**. All strings that are anagrams produce the same sorted key, allowing them to be grouped together efficiently.

## Algorithm

1. Create an `unordered_map<string, vector<string>>`.
2. Traverse each string in the input array.
3. Create a copy of the current string.
4. Sort the copied string to generate its canonical key.
5. Use the sorted string as the key in the map and add the original string to the corresponding vector.
6. After processing all the strings, traverse the map and collect each vector of grouped anagrams into the final answer.
7. Return the resulting vector of grouped anagrams.

## Complexity

* **Time:** `O(n × k log k)`
* **Space:** `O(n × k)`

> **Note:** `n` is the number of strings, and `k` is the average length of each string.

## What I Learned

* Sorting a string is an effective way to generate a unique canonical representation for all of its anagrams.
* An `unordered_map` can efficiently group multiple values that share the same key.
* A hash map combined with a canonical key is a powerful technique for solving grouping problems.
* This was my **first Medium-level LeetCode problem**, and it introduced me to combining multiple concepts such as hashing, sorting, and vectors in a single solution.
