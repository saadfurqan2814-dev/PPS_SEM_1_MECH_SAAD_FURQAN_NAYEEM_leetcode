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