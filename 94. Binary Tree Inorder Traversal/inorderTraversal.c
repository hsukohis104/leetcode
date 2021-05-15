/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int a_size = 0;
int * answer;
int i = 0;
void calsize(struct TreeNode* current){
    if( current == NULL )
        return;
    calsize(current->left);
    a_size++;
    calsize(current->right);
}
void inorder(struct TreeNode* current){
    if( current == NULL )
        return;
    inorder(current->left);
    answer[i++] = current->val;
    inorder(current->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    a_size = 0;
    i = 0;
    if( root == NULL ){
        *returnSize = 0;
        return NULL;
    }
    if( root->left == NULL && root->right == NULL ){
        *returnSize = 1;
        answer = (int*)malloc(sizeof(int)*1);
        answer[0] = root->val;
        return answer;
    }
    calsize(root);
    *returnSize = a_size;
    answer = (int*)malloc(sizeof(int)*a_size);
    inorder(root);
    return answer;
}