int missingNumber(int* nums, int numsSize){
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans+= nums[i];
    }
    ans =  ((( 1 + numsSize) * numsSize) / 2) - ans;
    return ans;
}