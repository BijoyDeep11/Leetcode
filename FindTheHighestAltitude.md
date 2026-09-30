# 1732. Find the Highest Altitude

## Difficulty

Easy

## Pattern

Prefix Sum / Running Sum

## Repeated Operation

Maintain a running sum of the altitude gains and keep track of the maximum altitude reached.

## Data Structure Chosen

None

## Why?

The input array does not directly contain the altitude at each point. Instead, it contains the **gain or loss in altitude between consecutive points**.

Therefore, I can reconstruct the altitude using a running sum without creating another array.

Since the biker starts at altitude `0`, the initial running sum is also `0`.

## Algorithm

1. Initialize:

   ```cpp
   int sum = 0;
   int maxAltitude = 0;
   ```
2. Traverse the `gain` array from left to right.
3. Add the current gain to the running sum:

   ```cpp
   sum += gain[i];
   ```
4. Compare the current altitude with the maximum altitude found so far.
5. If the current altitude is greater:

   ```cpp
   maxAltitude = sum;
   ```
6. Continue until the entire array has been processed.
7. Return `maxAltitude`.

## Example

For:

```text
gain = [-5, 1, 5, 0, -7]
```

The altitudes become:

```text
0 → -5 → -4 → 1 → 1 → -6
```

Therefore, the highest altitude reached is:

```text
1
```

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

> **Note:** `n` is the size of the `gain` array.

## What I Learned

* A **running sum** can reconstruct the original values when an array contains changes or differences rather than the actual values.
* The initial altitude is `0`, so the running sum also starts at `0`.
* I do not need to create a separate array to store every altitude because I only need the maximum value.
* Maintaining the maximum while traversing the array allows the problem to be solved in a single pass.
* This problem strengthened my understanding of the **prefix sum / running sum pattern** and showed how it can be used to track a changing value efficiently.
