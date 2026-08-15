# 1545. Find Kth Bit in Nth Binary String

## Difficulty

Medium

## Pattern

Recursion

## Repeated Operation

Use the recursive structure of the binary string to locate the `k`th bit without generating the entire string.

## Data Structure Chosen

None

## Why?

The binary string grows exponentially with each iteration, so generating the complete string would be inefficient. Instead, recursion allows us to determine which part of the string contains the `k`th bit and work only with the required position.

## Algorithm

The binary string is generated using the following pattern:

```text
S₁ = "0"
Sₙ = Sₙ₋₁ + "1" + reverse(invert(Sₙ₋₁))
```

For each string `Sₙ`:

* The **middle bit is always `1`**.
* The left half is the previous string `Sₙ₋₁`.
* The right half is the reverse and inverted version of `Sₙ₋₁`.

### Steps

1. **Base Case**

   * If `n == 1`, return `0`.

2. Calculate the length of the current binary string:

   ```text
   length = 2ⁿ - 1
   ```

3. Find the middle position:

   ```text
   middle = length / 2 + 1
   ```

4. If `k == middle`, return `1` because the middle bit is always `1`.

5. If `k < middle`, the required bit lies in the left half, which is exactly `Sₙ₋₁`. Recursively search for the `k`th bit.

6. If `k > middle`, the required bit lies in the right half.

   * Convert `k` into its corresponding position in the previous string:

   ```text
   k = length - k + 1
   ```

   * Recursively find the corresponding bit.
   * Since the right half is **inverted**, invert the returned bit.

7. Continue recursively until reaching the base case or the middle position.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)` due to the recursion stack.

> **Note:** The complete binary string is never constructed, allowing the solution to avoid the exponential space and time cost of generating the entire string.

## What I Learned

* Recursive problems can often be solved by understanding the **structure of the generated data** rather than actually generating it.
* The middle element provides an important **base case** because it is always `1`.
* When the required position lies in the right half, the transformation `length - k + 1` maps it back to the corresponding position in the previous string.
* Because the right half is inverted, the recursively obtained bit must also be inverted.
* This problem strengthened my understanding of **recursion, symmetry, index transformation, and divide-and-conquer thinking**.
* Most importantly, I learned that when a recursive structure grows exponentially, we should look for a way to navigate the structure instead of building the entire thing.
