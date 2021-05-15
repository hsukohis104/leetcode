

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int count = 0;
int ** ans;
void rec( int * nums, int * use_nums, int use_num_size, int max){
    if(use_num_size == max){
        for(int i = 0; i < max; i++)
            ans[count][i] = use_nums[i];
        count++;
        return;
    }
    for(int i = 0; i < max; i++){
        int flag = 1;
        for(int j = 0; j < use_num_size; j++){
            if( use_nums[j] == nums[i] ){
                flag = 0;
                break;
            }
        }
        if( flag ) {
            use_nums[use_num_size] = nums[i];
            rec( nums, use_nums, use_num_size + 1, max);
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size = 1;
    for( int i = 1; i <= numsSize; i++)
        size *= i;
    *returnSize = size;
    returnColumnSizes[0] = (int*) malloc(sizeof(int)*(*returnSize));
    ans = (char**)malloc(sizeof(char*)*(*returnSize));
    for(int i = 0; i < (*returnSize); i++){
        ans[i] = (int*)malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }
    int * use_nums = (int*)malloc(sizeof(int)*numsSize);
    count = 0;
    rec( nums, use_nums, 0, numsSize);
    return ans;
}