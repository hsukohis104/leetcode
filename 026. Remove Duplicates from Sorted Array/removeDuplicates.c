

int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0)
        return numsSize;
    int new_index = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[new_index-1] != nums[i])
            nums[new_index++] = nums[i];  
    }
    return new_index;
}