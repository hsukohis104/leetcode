

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    bool flag = 0;
    int i;
    for( i = digitsSize - 1; i >= 0; i--){
        if( digits[i] == 9 ){
            flag = 1;
            digits[i] = 0;
        }
        else {
            digits[i]++;
            break;
        }
        
    }
    if( flag && i == -1){
        int * ans = (int*) malloc(sizeof(int)*(digitsSize+1));
        ans[0] = 1;
        for(i = 0; i < digitsSize; i++){
            ans[i+1] = 0;
        }
        *returnSize = digitsSize + 1;
        return ans;
    }
    *returnSize = digitsSize;
    return digits;
}