# 1299. Replace Elements with Greatest Element on Right Side

## Difficulty
Easy

## Pattern
Array Traversal + Suffix Maximum

## Repeated Operation
Traverse the array from right to left while maintaining the greatest element seen so far on the right.

## Data Structure Chosen
`vector<int>` for storing the result.

## Why?
For every element, I need to find the greatest element present on its right side.

Instead of checking every element to the right separately, which would take `O(n²)` time, I traverse the array **from right to left** and maintain a variable called `maxSoFar`.

This variable always stores the greatest element encountered so far on the right side.

## Algorithm
1. Create an empty result vector.
2. Initialize:
   ```cpp
   int maxSoFar = -1;
   ```
   `-1` represents the required value for the last element because there is no element to its right.
3. Traverse the array from the last index to the first.
4. For every element:
   - Store the current `maxSoFar` as the answer for the current position.
   - Compare the current element with `maxSoFar`.
   - If the current element is greater, update `maxSoFar`.
5. Continue moving toward the beginning of the array.
6. Since the result is generated from right to left, reverse the result vector at the end if a separate answer vector is being used.
7. Return the result.

## Example

For:

```text
nums = [17, 18, 5, 4, 6, 1]
```

The greatest element on the right for each position is:

```text
[18, 6, 6, 6, 1, -1]
```

The traversal works from right to left:

```text
maxSoFar = -1
```

Then:

```text
1 → answer = -1 → maxSoFar = 1
6 → answer = 1  → maxSoFar = 6
4 → answer = 6  → maxSoFar = 6
5 → answer = 6  → maxSoFar = 6
18 → answer = 6 → maxSoFar = 18
17 → answer = 18 → maxSoFar = 18
```

## Complexity
- **Time:** `O(n)`
- **Space:** `O(n)` for the result vector.

> **Note:** If the input array is modified directly instead of creating a separate result vector, the auxiliary space can be reduced to `O(1)`.

## What I Learned
- When a problem asks for information about elements on the **right side**, traversing from **right to left** can make the solution much simpler.
- `maxSoFar` acts as a **suffix maximum**, storing the greatest element encountered so far.
- Initializing `maxSoFar` to `-1` handles the final element because there is nothing to its right.
- The important order of operations is:
  1. Use the current `maxSoFar` as the answer.
  2. Then update `maxSoFar` using the current element.
- This prevents the current element from incorrectly becoming the greatest element on its own right side.
- This problem strengthened my understanding of **reverse traversal and suffix-based techniques** for array problems.