/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// int c ;
struct TreeNode * create_node(int val){
    struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->val = val;
    return new_node;
}
struct TreeNode * create_hbt(int* nums, int left, int right){
    
    if(left > right  )
        return NULL;
    int mid = (left + right) / 2;
    struct TreeNode * current = create_node(nums[mid]);
    current->left = create_hbt( nums, left, mid-1);
    current->right = create_hbt( nums, mid+1, right);
    return current;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    
    return create_hbt(nums, 0, numsSize-1);
}