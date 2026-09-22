# 454. 4Sum II

## Difficulty

Medium

## Pattern

Hash Map + Pair Sum

## Repeated Operation

Store all possible sums of the first two arrays and look for their complementary sums in the remaining two arrays.

## Data Structure Chosen

`unordered_map<int, int>`

## Why?

A brute-force solution would try every possible combination of elements from all four arrays, resulting in `O(n⁴)` time.

To optimize this, I divide the problem into two pairs:

* `nums1 + nums2`
* `nums3 + nums4`

If:

```text
a + b + c + d = 0
```

then:

```text
a + b = -(c + d)
```

So I store the frequency of every possible sum from the first two arrays in an `unordered_map`. Then, while processing the last two arrays, I check whether the **complementary sum** exists in the map.

## Algorithm

1. Create an `unordered_map<int, int>` named `pairCount`.
2. Traverse `nums1` and `nums2` using two nested loops.
3. Calculate every possible pair sum:

   ```cpp
   int sum = nums1[i] + nums2[j];
   ```
4. Store its frequency in the hash map:

   ```cpp
   pairCount[sum]++;
   ```
5. Traverse `nums3` and `nums4` using two nested loops.
6. Calculate their pair sum:

   ```cpp
   int sum = nums3[i] + nums4[j];
   ```
7. Find the complementary value required to make the total sum zero:

   ```cpp
   int need = -sum;
   ```
8. Check whether `need` exists in `pairCount`.
9. If it exists, add its frequency to the answer:

   ```cpp
   count += pairCount[need];
   ```
10. Return the final count.

## Complexity

* **Time:** `O(n²)` average
* **Space:** `O(n²)`

> **Note:** `n` is the length of each input array. We generate `n²` pair sums for the first two arrays and perform `n²` lookups for the remaining two arrays.

## What I Learned

* A brute-force `O(n⁴)` solution can often be optimized by **splitting the problem into smaller groups**.
* The key transformation is:

  ```text
  A + B + C + D = 0
  ```

  becomes:

  ```text
  A + B = -(C + D)
  ```
* An `unordered_map` can store the **frequency of pair sums**, allowing duplicate combinations to be counted correctly.
* The frequency is important because the same pair sum can be produced by multiple different pairs of elements.
* This technique is commonly known as **meet-in-the-middle**, where a large search space is divided into smaller parts and matched efficiently.
* This problem strengthened my understanding of how **hash maps can reduce the complexity of multi-array combination problems from `O(n⁴)` to `O(n²)`**.
