
void reverseString(char* s, int sSize){
    char temp;
    int size = sSize-1;
    for( int i = 0; i < sSize/2; i++ ){
        temp = s[i];
        s[i] = s[size];
        s[size--] = temp;
    }
}