/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
        
 * };
 */
int * temp;
int count;
void in_order(struct TreeNode* root){
    if(root == NULL)
        return;
    in_order(root->left);
    temp[count++] = root->val;
    in_order(root->right);
}
int minDiffInBST(struct TreeNode* root){
    temp = (int*)malloc(sizeof(int)*100);
    count = 0;
    int min = 1000;
    in_order(root);
    for(int i = 1; i < count; i++){
       if( temp[i] - temp[i-1] < min)
           min = temp[i] - temp[i-1];
    }
    return min;  
}