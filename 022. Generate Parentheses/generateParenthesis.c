

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** ans;
int answer_num;
void rec_Parentheses(int left, int right){   
    if( left > right )
        return;
    if( left == 0 && right == 0 ){
        answer_num++;
        return;
    }
    if( left > 0 )
        rec_Parentheses(left-1, right);
    
    if(right > 0)
        rec_Parentheses(left, right-1);
}
int count;
void store_Parentheses(int left, int right, char * str, int char_count, int answer_num){
    if( left > right || count == answer_num )
        return;
    if( left == 0 && right == 0 ){
        str[char_count] = '\0'; 
        int i;
        for( i = 0; i < char_count; i++){
            ans[count][i] = str[i];
        }
        ans[count][i] = '\0';
        count++;
        return;
    }
    if( left > 0 ){
        str[char_count] = '(';
        store_Parentheses(left-1, right, str, char_count + 1, answer_num);
    }
    
    if(right > 0){
        str[char_count] = ')';
        store_Parentheses(left, right-1, str, char_count + 1, answer_num);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    ans = NULL;
    answer_num = 0;
    rec_Parentheses(n, n);
    *returnSize = answer_num;
    ans = (char**)malloc(sizeof(char*)*answer_num);
    for(int i = 0; i < answer_num; i++)
        ans[i] = (char*)malloc(sizeof(char)*(n*2+1));
    count = 0;
    char * temp = (char*)malloc(sizeof(char)*(n*2+1));
    store_Parentheses(n, n, temp, 0, answer_num);
    return ans;
}