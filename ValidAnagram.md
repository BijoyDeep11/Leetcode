# 242. Valid Anagram

## Difficulty

Easy

## Pattern

Hash Map (Frequency Counting)

## Repeated Operation

Count the frequency of each character.

## Data Structure Chosen

`unordered_map<char, int>`

## Why?

An `unordered_map` allows me to store the frequency of each character. An `unordered_set` only stores unique elements and cannot keep track of how many times a character appears, making it unsuitable for this problem.

## Algorithm

1. Check if the lengths of the two strings are different. If they are, return `false` because they cannot be anagrams.
2. Create an `unordered_map<char, int>` named `mp`.
3. Traverse string `s` and increment the frequency of each character in the map.
4. Traverse string `t` and decrement the frequency of each character in the same map.
5. Iterate through the map and check the frequency of every character.
6. If every frequency is `0`, return `true`; otherwise, return `false`.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(k)`

> **Note:** `n` is the length of the strings, and `k` is the number of distinct characters.

## What I Learned

* An `unordered_set` cannot store frequencies, so it cannot be used for frequency-counting problems.
* A single `unordered_map` is enough to solve this problem by incrementing the frequencies for one string and decrementing them for the other.
* Checking whether all frequencies become `0` is an efficient way to verify if two strings are valid anagrams.
* Using one hash map makes the solution simple, clean, and efficient.
