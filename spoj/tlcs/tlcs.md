# TLCS - Longest Common Subsequence
For a given two words x = x1x2...xn and y = y1y2...ym find the longest common subsequence, i.e. z = z1z2...zk such that every two consecutive elements of z are equal to some two elements of x: xa, xb, and y: yc, yd where a < b and c < d. Assume, that elements of words are letters 'a' - 'z' and m,n <= 1000.
## Input

N [the number of series <= 1000]

n **x**

m **y**

...

## Output

case 1 Y [or N when no answer to this case]

d [the length of the lcs]

zj p q [position of zj in x and in y, respectively]

...

Text grouped in [ ] does not appear in the input and output file.

## Example
```
Input:
3
5 ddacc
3 cac
7 cbbccbc
4 aaca
4 cbeb
5 fdceb

Output:
case 1 Y
2
a 3 2
c 4 3
case 2 N
case 3 Y
3
c 1 3
e 3 4
b 4 5

Score
2
```
