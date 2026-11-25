# Reshape the Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

In MATLAB, there is a handy function called `reshape` which can reshape an `m x n` matrix into a new one with a different size `r x c` keeping its original data.

You are given an `m x n` matrix `mat` and two integers `r` and `c` representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the `reshape` operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Original
C
 **Example 1:** 

```
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

```

 **Example 2:** 

```
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

```

 

 **Constraints:** 

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 100
- -1000 <= mat[i][j] <= 1000
- 1 <= r, c <= 300

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.9 MB (beats 35.18%)  
**Submitted:** 2026-11-25T13:55:35.576Z  

```c
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];

    // Check if reshape is possible; if not, copy/return original matrix
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(m * sizeof(int));
        int** originalCopy = (int**)malloc(m * sizeof(int*));

        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
            originalCopy[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                originalCopy[i][j] = mat[i][j];
            }
        }
        return originalCopy;
    }

    // Allocate memory for the reshaped r x c matrix
    *returnSize = r;
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    int** reshaped = (int**)malloc(r * sizeof(int*));

    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        reshaped[i] = (int*)malloc(c * sizeof(int));
    }

    // Map each element using a flat index from 0 to (m * n - 1)
    int total = m * n;
    for (int idx = 0; idx < total; idx++) {
        int oldRow = idx / n;
        int oldCol = idx % n;
        int newRow = idx / c;
        int newCol = idx % c;
        reshaped[newRow][newCol] = mat[oldRow][oldCol];
    }

    return reshaped;
}
```

---

[View on LeetCode](https://leetcode.com/problems/reshape-the-matrix/)