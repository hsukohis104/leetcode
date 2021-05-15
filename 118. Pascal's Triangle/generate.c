

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int ** PascalTriangle = (int**) malloc(sizeof(int*)*numRows);
    returnColumnSizes[0] = (int*)malloc(sizeof(int)*numRows);
    for(int j = 1; j <= numRows; j++){
        (*returnColumnSizes)[j-1] = j;
         PascalTriangle[j-1] = (int*) malloc(sizeof(int)*j);
        PascalTriangle[j-1][0] = 1;
        PascalTriangle[j-1][j-1] = 1;
        for(int i = 1; i < j-1; i++){
            PascalTriangle[j-1][i] = 0;
        }
    }
    for(int j = 0; j < numRows; j++){
        for(int i = 0; i < j + 1; i++){
            if( PascalTriangle[j][i] == 0 ) 
                PascalTriangle[j][i]  = PascalTriangle[j-1][i-1]  + PascalTriangle[j-1][i];
        }
    }
    *returnSize = numRows;
    return PascalTriangle;
}