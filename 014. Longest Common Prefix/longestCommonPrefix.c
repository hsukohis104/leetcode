

char * longestCommonPrefix(char ** strs, int strsSize){
    char * ans;
    char temp = ' ';
    int char_pos = 0;
    int prefix_size = 0;
    if( !strsSize ){
        ans = (char*)malloc(sizeof(char));
        ans[0] = '\0';
        return ans;
    }
    while(temp != '\0'){
        temp = strs[0][char_pos];
        int flag = 0;
        for(int i = 0; i < strsSize; i++){
            if( temp != strs[i][char_pos] ){
                flag = 1;
                break;
            }
                
        }
        char_pos++;
        if(flag)
            break;
    }
    ans = (char*)malloc(sizeof(char) * char_pos);
    for(int i = 0; i < char_pos; i++){
        ans[i] = strs[0][i];
    }
    ans[char_pos-1] = '\0';
    return ans;
}