

int findPeakElement(int* nums, int numsSize){
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < nums[i-1])
            return i-1;
    }
    return numsSize-1;
}