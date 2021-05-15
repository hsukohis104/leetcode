

bool isPalindrome(char * s){
    int str_length = 0;
    for(int i = 0; s[i]!='\0'; i++){
        if( (s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 48 && s[i] <= 57) )
            str_length++;
    }
    char * s2 = (char*)malloc((str_length+1)*sizeof(char));
    int j = 0;
    for(int i = 0; s[i]!='\0'; i++){
        if( (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)){
            s2[j++] = s[i];
        }
        else if(s[i] >= 65 && s[i] <= 90){
            s2[j++] = s[i] + 32;
        }
    }
    s2[j] = '\0';
    int tail = str_length-1;
    for(int i = 0; i < str_length/2; i++){
        if( s2[i] != s2[tail--] )
            return false;
    }
    return true;
}