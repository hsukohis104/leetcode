int findDuplicate(int* nums, int numsSize){
    int * hashmap = (int*)malloc( numsSize*sizeof(int) );
    for(int i = 0; i < numsSize; i++)
        hashmap[i]=0;
    for(int i = 0; i < numsSize; i++){
        if(hashmap[nums[i]] != 0)
            return nums[i];
        else
            hashmap[nums[i]] = 1;
    }
    return 0;
}