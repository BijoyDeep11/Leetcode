# 205. Isomorphic Strings

## Difficulty

Easy

## Pattern

Hash Map (Bidirectional Mapping)

## Repeated Operation

Maintain a consistent one-to-one mapping between characters of the two strings.

## Data Structure Chosen

* `unordered_map<char, char>` for mapping characters from `s` to `t`
* `unordered_map<char, char>` for mapping characters from `t` to `s`

## Why?

A single mapping is not enough because the relationship between the two strings must be **one-to-one**.

For example, if:

```text
s = "egg"
t = "add"
```

then:

```text
e → a
g → d
```

But if two different characters in `s` were allowed to map to the same character in `t`, the strings would not be isomorphic.

Therefore, I used **two hash maps**:

* `sToT` to track the mapping from `s` → `t`
* `tToS` to track the mapping from `t` → `s`

## Algorithm

1. Check whether the lengths of `s` and `t` are different.

   * If they are different, return `false`.
2. Create two `unordered_map<char, char>`:

   ```cpp
   unordered_map<char, char> sToT;
   unordered_map<char, char> tToS;
   ```
3. Traverse both strings simultaneously using a single loop.
4. For every position `i`:

   * Check whether `s[i]` already has a mapping in `sToT`.
   * If it does and the mapped character is not `t[i]`, return `false`.
   * Check whether `t[i]` already has a mapping in `tToS`.
   * If it does and the mapped character is not `s[i]`, return `false`.
5. If both mappings are valid, add the mappings:

   ```cpp
   sToT[s[i]] = t[i];
   tToS[t[i]] = s[i];
   ```
6. Continue until all characters have been processed.
7. If no conflicting mapping is found, return `true`.

## Complexity

* **Time:** `O(n)` average
* **Space:** `O(k)`

> **Note:** `n` is the length of the strings, and `k` is the number of distinct characters.

## What I Learned

* Isomorphic strings require a **one-to-one character mapping**.
* Using only one hash map can allow multiple characters from one string to incorrectly map to the same character in the other string.
* Using two maps provides **bidirectional validation**:

  ```text
  s → t
  t → s
  ```
* If an existing mapping conflicts with the current character pair, the strings cannot be isomorphic and we can immediately return `false`.
* If a character has not been mapped yet, we can safely add the new mapping.
* Checking the existing mapping before inserting it is important because it prevents an invalid mapping from being overwritten.
* This problem strengthened my understanding of **hash maps, character mapping, and consistency checking**.
