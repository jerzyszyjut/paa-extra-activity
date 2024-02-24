# TCONNUM - Simple Numbers Conversion
Every integer number n is represented in positional number system of base r by a sequence of digits 0 ≤ di < r, so the value is equal to:

n = d0  + r * d1 + r^2 * d2 + r^3 * d3 + ...

Your task is to convert a given number in r-base represantation into s-base representation, for example: decimal 231 into binary 11100111. Assume that r ≤ 36 and the digits are 0,1,2,3,4,5,6,7,8,9, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z.

## Input

N [the number of series ≤ 1000]
n r s [n ≤ 10^1000, r,s ≤ 36]

## Output

n [s-base representation of number n]

Text grouped in [ ] does not appear in the input and output file.

## Example

```
Input:
3
231 10 2
ABC 15 10
XYZ 36 2

Output:
11100111
2427
1010101111111011
```

## Test cases

There are five categories of the input data:

    Test case 1: (1 pt), r = 2 and s = 10, or conversely, n≤ 10^9, N = 100,

    Test case 2: (1 pt), 2 ≤ r,s ≤ 10, n≤10^9, N = 1000,

    Test case 3: (1 pt), 2 ≤ r,s ≤ 36, n≤ 10^9, N = 1000,

    Test case 4: (3 pts), 2 ≤ r,s ≤ 10, n≤ 10^1000, N = 1000,

    Test case 5: (4 pts), 2 ≤ r,s ≤ 36, n≤ 10^1000, N = 1000.
