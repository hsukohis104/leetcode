/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * ans;
struct TreeNode * temp;
int flag,flag2;
int post_order(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){
    if(root==NULL || flag)
        return 0;
    if(root == p){
        ans = p;
        return 1;
    } 
    if(root==q){
        ans = q;
        return 1;
    }
    int left = post_order(root->left, p, q);
    int right = post_order(root->right,  p, q);
    if( left & right){
        ans = root;
        flag = 1;
    }
    return (left | right);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    ans = NULL;
    flag = 0;
    post_order(root, p, q);
    return ans;
}