/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = pow(2,numsSize);
    int ** result = (int**)malloc(sizeof(int*)*(*returnSize));
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*(*returnSize) );
    unsigned int temp = *returnSize;
    for(int i = 0; i < *returnSize; i++){
        int subset_size = 0;
        for(int j = 0; j < numsSize; j++){
            if((1u<<j) & i )
                subset_size++;
        }
        result[i] = (int*)malloc(sizeof(int)* subset_size);
        (*returnColumnSizes)[i] = subset_size;
        int count = 0;
        for(int j = 0; j < numsSize; j++){
            if((1u<<j) & i ){
                result[i][count++] = nums[j];
            }
        }
    }
    return result;
}