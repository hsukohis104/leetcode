

char * convertToTitle(int n){
    char* answer;
    int temp = 0;
    int temp2 = 0;
    int temp_n = n;
    int loop_count = 0;
    char temp_c[10];
    while( temp_n != 0 ){
        temp_n--;
        temp2 =  temp_n % 26;
        temp_n = temp_n / 26;
        temp_c[loop_count++] = temp2 + 65;
    }
    answer = (char*)malloc(sizeof(char)*((loop_count+1)));
    int j = 0;
    printf("%c", temp_c[0]);
    printf("loop_count: %d", loop_count);
    for( int i = loop_count -1; i >= 0; i-- ){
        answer[j++] = temp_c[i];
    }
    answer[j] = '\0';
    return answer;
}