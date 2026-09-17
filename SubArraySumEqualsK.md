# 560. Subarray Sum Equals K

## Difficulty

Medium

## Pattern

Prefix Sum + Hash Map

## Repeated Operation

Maintain a running prefix sum and use a hash map to count how many previous prefix sums can form a subarray with sum equal to `k`.

## Data Structure Chosen

`unordered_map<int, int>`

## Why?

A brute-force approach would check every possible subarray and calculate its sum, which can take `O(n²)` time.

To optimize this, I used a **prefix sum** along with an `unordered_map`.

The hash map stores:

```text
prefix sum → frequency of that prefix sum
```

This allows me to determine in average `O(1)` time whether a previous prefix sum exists that can form a subarray with sum `k`.

## Key Concept: Prefix Sum

The prefix sum is the continuous running sum of the elements processed so far.

If the current prefix sum is `sum`, then for a subarray to have sum `k`, we need a previous prefix sum equal to:

```text
need = sum - k
```

If this `need` has appeared before, every occurrence of that prefix sum represents a valid subarray ending at the current position.

## Why Initialize `prefixCount[0] = 1`?

This is an important part of the solution.

```cpp
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;
```

A prefix sum of `0` is considered to have occurred once before processing the array.

This handles subarrays that start from **index `0`**.

For example, if the current prefix sum itself is equal to `k`:

```text
sum = k
need = sum - k
     = 0
```

Because `prefixCount[0]` is already `1`, the subarray starting from index `0` is correctly counted.

## Algorithm

1. Create an `unordered_map<int, int>` named `prefixCount`.
2. Initialize:

   ```cpp
   prefixCount[0] = 1;
   ```
3. Initialize:

   ```cpp
   int sum = 0;
   int count = 0;
   ```
4. Traverse the array from left to right.
5. Add the current element to the running prefix sum:

   ```cpp
   sum += nums[i];
   ```
6. Calculate the required previous prefix sum:

   ```cpp
   int need = sum - k;
   ```
7. Check whether `need` exists in the hash map.
8. If it exists, add its frequency to `count`:

   ```cpp
   count += prefixCount[need];
   ```
9. Store the current prefix sum in the hash map:

   ```cpp
   prefixCount[sum]++;
   ```
10. Continue until the entire array has been processed.
11. Return `count`.

## Complexity

* **Time:** `O(n)` average
* **Space:** `O(n)`

> **Note:** `n` is the size of the input array. The `unordered_map` provides average `O(1)` lookup and insertion.

## What I Learned

* A brute-force subarray approach can be optimized significantly using **prefix sums**.
* The key relationship is:

  ```text
  current prefix sum - previous prefix sum = subarray sum
  ```
* Therefore, when:

  ```text
  previous prefix sum = current prefix sum - k
  ```

  the elements between those two prefix positions form a subarray whose sum is `k`.
* `prefixCount[0] = 1` is essential because it allows us to count valid subarrays that begin at index `0`.
* We store the **frequency** of each prefix sum rather than simply whether it exists. This is important because the same prefix sum can occur multiple times, and each occurrence can represent a different valid subarray.
* The statement:

  ```cpp
  count += prefixCount[need];
  ```

  means that every previous occurrence of `need` creates one additional subarray ending at the current index.
* This problem taught me how a **prefix sum + hash map** can transform an `O(n²)` brute-force approach into an average **O(n)** solution.
