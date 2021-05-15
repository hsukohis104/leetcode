/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int * answer = (int*)malloc(numsSize*(sizeof(int)));
    *returnSize = numsSize;
    *answer = 1;
    for (int i=1; i<numsSize; i++)
        answer[i] = answer[i-1] * nums[i-1];
    int last_element = nums[numsSize-1];
    for( int i = numsSize-2; i>= 0; i-- ){
        answer[i] = last_element * answer[i];
        last_element *= nums[i]; 
    }
    return answer;
}