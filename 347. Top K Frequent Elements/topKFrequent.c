

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct element{
    int num;
    int count;
}arr_element;
typedef struct bucket_element{
    int num[1000];
    int num_count;
}bucket_element_arr;
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    arr_element * list_arr = (arr_element*)malloc(sizeof(arr_element)*numsSize);
    int list_count = 0;
    int max_count = 0;
    for( int i = 0; i < numsSize; i++ ){
        int flag = 1;
        for( int j = 0; j < list_count; j++ ){
            if( list_arr[j].num == nums[i] ){
                flag = 0;
                list_arr[j].count++;
                if( max_count < list_arr[j].count)
                    max_count = list_arr[j].count;
                break;
            }
        }
        if( flag ){
            list_arr[list_count].num = nums[i];
            if( max_count < 1)
                max_count = 1;
            list_arr[list_count++].count = 1;
        }
    }
    bucket_element_arr * bucket = (bucket_element_arr*)malloc(sizeof(bucket_element_arr)*max_count);
    for( int i = 0; i < max_count; i++ )
        bucket[i].num_count = 0;
    for( int i = 0; i < list_count; i++ )
        bucket[list_arr[i].count-1].num[bucket[list_arr[i].count-1].num_count++] = list_arr[i].num; 
    int * answer = (int*)malloc(sizeof(int)*k);
    int index = max_count-1;
    int i = 0;
    while(i < k){
        if(bucket[index--].num_count != 0){
            
            for( int j = 0; j < bucket[index+1].num_count; j++ ){
                answer[i++] = bucket[index+1].num[j];
            }
        }      
    }
    *returnSize = k;
    return answer;
}