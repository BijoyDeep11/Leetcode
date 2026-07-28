# 9. Palindrome Number

## Difficulty

Easy

## Pattern

Mathematics

## Repeated Operation

Reverse half of the digits of the number and compare them with the remaining half.

## Data Structure Chosen

None

## Why?

This problem can be solved purely using mathematical operations. Although a string-based solution is straightforward, the optimized approach avoids extra space by reversing only half of the number.

## Algorithm

### Approach 1: Using Strings

1. Convert the integer into a string.
2. Create the reverse of the string.
3. Compare the original string with the reversed string.
4. If both are equal, return `true`; otherwise, return `false`.

### Approach 2: Using Mathematics (Optimized)

1. If the number is negative, return `false` because negative numbers cannot be palindromes.
2. If the number ends with `0` but is not `0` itself, return `false` because a palindrome cannot start with `0`.
3. Initialize a variable `reversed = 0`.
4. Reverse only **half of the digits** using the formula:

   ```cpp
   reversed = reversed * 10 + (x % 10);
   x /= 10;
   ```
5. Continue the process while `x > reversed`.
6. After the loop:

   * If the number has an **even** number of digits, compare `x == reversed`.
   * If the number has an **odd** number of digits, compare `x == reversed / 10`.
7. Return the comparison result.

## Complexity

### String Approach

* **Time:** `O(n)`
* **Space:** `O(n)`

### Mathematical Approach

* **Time:** `O(log₁₀ n)`
* **Space:** `O(1)`

## What I Learned

* Some problems that appear to require strings can be solved more efficiently using mathematical operations.
* Reversing **only half** of the number prevents integer overflow and avoids unnecessary computation.
* Handling edge cases is crucial:

  * Negative numbers are never palindromes.
  * Numbers ending in `0` (except `0` itself) cannot be palindromes.
* The condition `while (x > reversed)` ensures that only half of the digits are reversed.
* For an **even** number of digits, compare `x == reversed`.
* For an **odd** number of digits, ignore the middle digit by comparing `x == reversed / 10`.
* This problem strengthened my understanding of integer manipulation using modulo (`%`) and division (`/`) operations without relying on additional data structures.
