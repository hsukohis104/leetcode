/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * create_node(int val){
    struct TreeNode * temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->left = NULL;
    temp->right = NULL;
    temp->val = val;
    return temp;
}
int pre_index = 0;
struct TreeNode* construct_tree(int* preorder, int* inorder, int Size, 
                                 int left_index, int right_index){
    if(left_index >= right_index || pre_index >= Size)
        return NULL;
    int i;
    for(i = left_index; i < right_index; i++){
        if(inorder[i] == preorder[pre_index])
            break;
    }
    if(i == right_index)
        return NULL;
    struct TreeNode * current = create_node(inorder[i]);
    pre_index++;
    current->left = construct_tree(preorder, inorder, Size, left_index, i);
    current->right = construct_tree(preorder, inorder, Size, i, right_index);
    return current;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    pre_index = 0;
    return construct_tree(preorder, inorder, preorderSize, 0, preorderSize);
}