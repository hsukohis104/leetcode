bool isAnagram(char * s, char * t){
    int i = 0;
    int hash_table[26] = {0};
    while( s[i] != '\0' ){
        if( t[i] == '\0' )
            return false;
        hash_table[s[i]-97]++;
        hash_table[t[i]-97]--;
        i++;
    }
    for(int j = 0; j < 26; j++){
        if( hash_table[j] )
            return false;
    }
    if( (s[i] == '\0') && (t[i] == '\0' ))
       return true;
    return false;
}