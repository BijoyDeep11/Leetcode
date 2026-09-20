# 438. Find All Anagrams in a String

## Difficulty

Medium

## Pattern

Sliding Window + Hash Map

## Repeated Operation

Maintain a fixed-size sliding window and check whether the character frequencies in the window match the frequencies of the target string.

## Data Structure Chosen

* `unordered_map<char, int>` for the frequency of characters in the target string
* `unordered_map<char, int>` for the frequency of characters in the current window
* `vector<int>` for storing the starting indices of all valid anagrams

## Why?

The problem requires finding all substrings of `s` that are anagrams of `p`.

Since an anagram has the **same characters with the same frequencies**, a hash map is useful for maintaining character frequencies.

I used a **sliding window** because every possible anagram must have exactly the same length as `p`. Instead of creating and checking every substring from scratch, I maintain a window of size `p.length()` and move it through the string.

## Algorithm

1. Create an `unordered_map<char, int>` to store the frequency of every character in `p`.
2. Create another `unordered_map<char, int>` to maintain the frequency of characters in the current window of `s`.
3. Initialize two pointers:

   ```cpp
   int left = 0;
   int right = 0;
   ```
4. Move the `right` pointer through the string `s`.
5. Add the current character to the window frequency map.
6. If the window size becomes greater than the length of `p`:

   * Remove the character at the `left` pointer from the window.
   * Move `left` forward by one.
7. Once the window size becomes exactly equal to `p.length()`, compare the window's frequency map with the frequency map of `p`.
8. If both maps are equal, the current window is an anagram of `p`, so add `left` to the answer vector.
9. Continue moving the sliding window until the entire string has been processed.
10. Return the answer vector containing the starting indices of all anagrams.

## Complexity

* **Time:** `O(n)` average
* **Space:** `O(k)`

> **Note:** `n` is the length of `s`, and `k` is the number of distinct characters being tracked.

## What I Learned

* A **sliding window** is useful when searching for fixed-size substrings or subarrays.
* Since every anagram of `p` must have exactly `p.length()` characters, maintaining a fixed-size window makes the problem much more efficient.
* Two frequency maps can be used to compare the target string with the current window.
* Instead of creating a new substring every time, the window can be updated by:

  * Adding the new character from the right.
  * Removing the old character from the left.
* C++ allows `unordered_map` objects to be compared directly, which makes checking whether the current window has the same character frequencies as `p` straightforward.
* This problem helped me connect two important DSA concepts: **hash maps for frequency counting** and **sliding windows for efficient substring processing**.
