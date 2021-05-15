void moveZeroes(int* nums, int numsSize){
    int non_zero_count = 0;
    for(int i = 0; i < numsSize; i++){
       if(nums[i]!= 0){
           nums[non_zero_count++] = nums[i];
       }
    }
    for(int i = numsSize-1; i >= non_zero_count; i-- )
        nums[i] = 0;
    
}