

int strStr(char * haystack, char * needle){
    int i = 0;
    if(needle[i] == '\0')
        return 0;
    int needle_size = 0, haystack_size = 0;
    for(int i = 0; needle[i] != '\0'; i++)
        needle_size++;
    for(int i = 0; haystack[i] != '\0'; i++)
        haystack_size++;
    if( needle_size > haystack_size )
        return -1;
    while(haystack[i] != '\0' && ((i + needle_size - 1) <= haystack_size ) ){
        int j = 0;
        int temp = i;
        int skip_distance = 0;
        int flag = 0;
        if( haystack[i] == needle[j] && haystack[i + needle_size - 1] == needle[needle_size-1] ){
            while(needle[j] != '\0'){
                if( haystack[temp] != needle[j] ){
                    break;
                }
                if( needle[0] == haystack[temp] && j != 0 && !flag){
                    flag = 1;
                    skip_distance = j;
                }
                temp++;
                j++;
            }
            if( needle[j] == '\0' )
                return i;
        }
        if(flag)
            i += skip_distance;
        else
            i++;
    }
    return -1;
}