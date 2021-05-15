

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    int cal_hash[26] = {0};
    int length = 0;
    int diff = 0;
    for(int i = 0; p[i] != '\0'; i++){
        int pos = p[i]-'a';
        if(cal_hash[pos] == 0)
            diff++;
        cal_hash[pos]++;
        length++;
    }
    *returnSize = 0;
    int count_diff = 0;
    int temp[11000];
    for(int i = 0; s[i] != '\0'; i++){
        int flag = 0;
        if(i == 0){
            for(int j = 0; j < length; j++){
                if(s[j+i]=='\0'){
                    count_diff = 0;
                    flag = 1;
                    break;
                }
                int pos = s[j+i]-'a';
                cal_hash[pos]--;
                if(cal_hash[pos] == 0)
                    count_diff++;
            }
        }
        else{
            int pos = s[i]-'a';
            int pre_pos = s[i-length]-'a';
            cal_hash[pos]--;
            if(cal_hash[pos] == 0)
                count_diff++;
            if(cal_hash[pre_pos] == 0)
                count_diff--;
            cal_hash[pre_pos]++;
        }
        if(count_diff == diff){
            if( i == 0 )
                temp[*returnSize] = 0;
            else
                temp[*returnSize] = i - length + 1;
            (*returnSize)++;
        }
        if( i == 0 )
            i = length - 1;
        if(flag)
            break;
    }
    int * ans = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i = 0; i < (*returnSize); i++)
        ans[i] = temp[i];
    return ans;
}