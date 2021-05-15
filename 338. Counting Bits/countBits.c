/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int * answer = (int*)malloc( (num + 1)* sizeof(int) );
    for(int i = 1; i < num + 1; i++){
        int ans_temp = 0;
        for( int j = 0; j < 32; j++ ){
            if( ((i >> j) & 1) )
                ans_temp++;
        }
        answer[i] = ans_temp;
    }
    answer[0] = 0;
    return answer;

}