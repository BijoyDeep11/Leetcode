# 974. Subarray Sums Divisible by K

## Difficulty

Medium

## Pattern

Prefix Sum + Hash Map + Remainder Counting

## Repeated Operation

Track the remainder of the running prefix sum when divided by `k` and count how many previous prefix sums have produced the same remainder.

## Data Structure Chosen

`unordered_map<int, int>`

## Why?

The key observation is that two prefix sums with the **same remainder modulo `k`** form a subarray whose sum is divisible by `k`.

Suppose two prefix sums are:

```text
prefix1 % k = r
prefix2 % k = r
```

Then:

```text
(prefix2 - prefix1) % k = 0
```

Therefore, the elements between those two prefix positions form a valid subarray whose sum is divisible by `k`.

I used an `unordered_map` to store:

```text
remainder → frequency
```

This allows me to quickly find how many previous prefix sums had the same remainder.

## Algorithm

1. Create an `unordered_map<int, int>` named `prefixCount` to store the frequency of each remainder.
2. Initialize:

   ```cpp
   prefixCount[0] = 1;
   ```

   This accounts for subarrays that start from index `0`.
3. Initialize:

   ```cpp
   int prefixSum = 0;
   int count = 0;
   ```
4. Traverse the array from left to right.
5. Add the current element to the running prefix sum:

   ```cpp
   prefixSum += nums[i];
   ```
6. Calculate the remainder:

   ```cpp
   int remainder = prefixSum % k;
   ```
7. Since the array can contain negative numbers, normalize the remainder if necessary:

   ```cpp
   if (remainder < 0)
       remainder += k;
   ```
8. Check whether this remainder has already appeared in the hash map.
9. If it exists, add its frequency to the answer:

   ```cpp
   count += prefixCount[remainder];
   ```
10. Increment the frequency of the current remainder:

```cpp
prefixCount[remainder]++;
```

11. Continue processing the entire array.
12. Return `count`.

## Complexity

* **Time:** `O(n)` average
* **Space:** `O(k)`

> **Note:** `n` is the size of the input array. There can be at most `k` different remainders (`0` to `k - 1`).

## What I Learned

* A subarray is divisible by `k` when the **prefix sums before and after the subarray have the same remainder modulo `k`**.
* The key mathematical relationship is:

  ```text
  prefix₂ % k = prefix₁ % k
  ```

  which means:

  ```text
  (prefix₂ - prefix₁) % k = 0
  ```
* The hash map stores the **frequency of each remainder**, rather than simply checking whether a remainder exists.
* If a remainder has appeared multiple times, each previous occurrence represents a different valid subarray ending at the current index.
* Initializing:

  ```cpp
  prefixCount[0] = 1;
  ```

  is important because it counts valid subarrays whose sum from the beginning of the array is already divisible by `k`.
* This problem strengthened my understanding of **prefix sums, modular arithmetic, and frequency-based hash maps**.
* It also showed me how a mathematical observation can turn a brute-force subarray problem into an efficient **`O(n)` average-time solution**.
