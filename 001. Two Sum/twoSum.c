/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * ans = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if( nums[i] + nums[j] == target ){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return NULL;
}