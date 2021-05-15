int majorityElement(int* nums, int numsSize){
    int answer = nums[0];
    int count = 1;
    for(int i = 1; i < numsSize; i++){
        if( answer == nums[i] )
            count++;
        else
            count--;
        if( count == 0 ){
            answer = nums[i];
            count = 1;
        }
    }
    return answer;
}