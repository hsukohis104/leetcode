

int firstUniqChar(char * s){
    int hash[26] = {0};
    int ans_index = 0;
    int i = 0;
    while(s[i]!='\0'){
        hash[s[i]-97]++;
        i++;
    }
    i = 0;
    while(s[i]!='\0'){
        if(hash[s[i]-97] == 1)
            return i;
        i++;
    }
    return -1;
}