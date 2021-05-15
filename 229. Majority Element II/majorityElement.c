

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int * answer;
    int n1 = nums[0], n2 = 0;
    int count = 1, count2 = 0;
    for(int i = 1; i < numsSize; i++){
        if( n1 == nums[i] )
            count++;
        else if( n2 == nums[i] )
            count2++;
        else{
            if( count == 0 ){
                n1 = nums[i];
                count=1;
            }
            else if( count2 == 0 ){
                n2 = nums[i];
                count2=1;
            }
            else{
                count--;
                count2--;
            }
        }
    }
    int check_c = 0, check_c2 = 0;
    int lim = numsSize / 3;
    for( int i = 0; i < numsSize; i++ ){
        if( n1 == nums[i] )
            check_c++;
        else if( n2 == nums[i] )
            check_c2++;
    }
    if(lim == 0){
        if( n1 == 0 && n2 == 0 )
            *returnSize = 0;
        else if( n1 != 0 && n2 == 0){
            answer = (int*)malloc(sizeof(int));
            answer[0] = n1;
            *returnSize = 1;
        }
        else{
            answer = (int*)malloc(2*sizeof(int));
            answer[0] = n1;
            answer[1] = n2;
            *returnSize = 2;
        }
    }
    else if( (check_c > lim && check_c2 > lim)){
        answer = (int*)malloc(2*sizeof(int));
        answer[0] = n1;
        answer[1] = n2;
        *returnSize = 2;
    }
    else if(check_c > lim){
        answer = (int*)malloc(sizeof(int));
        answer[0] = n1;
        *returnSize = 1;
    }
    else if( check_c2 > lim ){
        answer = (int*)malloc(sizeof(int));
        answer[0] = n2;
        *returnSize = 1;
    }
    else
        *returnSize = 0;
    
    return answer;
}