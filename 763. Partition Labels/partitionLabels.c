/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* partitionLabels(char * S, int* returnSize){
    int char_label[26] = {0};
    int char_count[26] = {0};
    char * temp = S;
    int char_num = 0;
    
    while(*temp != '\0'){
        // char_label[(*temp)-97]++;
        char_count[(*temp)-97]++;
        temp++;
        char_num++;
    }
    int * temp_answer = (int*)malloc(sizeof(int)*char_num); 
    temp = S;
    int part_count = 0;
    int part_num = 0;
    while(*temp != '\0'){
        int index = (*temp)-97;
        char_count[index]--;
        char_label[index] = 1;
        int part_flag = 0;
        int check = 0;
        for( check = 0; check < 26; check++){
            if( char_label[check]){
                if( char_count[check] != 0 )
                    break;
            }
        }
        if( check == 26 )
            part_flag = 1;
        if( part_flag ){
            part_count++;
            for( int i = 0; i < 26; i++)
                char_label[index] = 0;
            temp_answer[part_num++] = part_count;
            part_count = 0;
        }
        else{
            part_count++;
        }
        temp++;
    }
    *returnSize = part_num;
    int * answer = (int*)malloc(sizeof(int)*part_num);
    for( int i = 0; i < part_num; i++ )
        answer[i] = temp_answer[i];
    return answer;
}