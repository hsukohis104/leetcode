

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b)
{   
   if( *(int*)a > *(int*)b )
        return 1;
    return 0;
}
int * intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    
    int i = 0, j = 0;
    int * ans;
    int ans_size = 0;
    int temp_ans[10000] = {0};
    if( nums2Size == 0 || nums1Size == 0 ){
        *returnSize = 0;
        return ans;
    }
    while(i < nums1Size){
        if(nums1[i]==nums2[j]){
            temp_ans[ans_size++] = nums1[i];
            i++;
            j++;
        }
        else if( nums1[i] < nums2[j] )
            i++;
        else if( nums1[i] > nums2[j] )
            j++;
        if( i == nums1Size|| j == nums2Size )
            break;
    }
    *returnSize = ans_size;
    ans= (int*)malloc(sizeof(int)*ans_size);
    for(int i = 0; i < ans_size; i++)
       ans[i] = temp_ans[i]; 
    return ans;
}