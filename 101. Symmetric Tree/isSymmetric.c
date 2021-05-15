/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool recu(struct TreeNode* root, struct TreeNode* root2){
    if(root == NULL ){
        if( root2 == NULL )
            return true;
        return false;
    }
    else if( root2 == NULL ){
        if( root == NULL )
            return true;
        return false;
    }
    return (root->val == root2->val) && recu(root->left, root2->right) && recu(root->right, root2->left);
}

bool isSymmetric(struct TreeNode* root){
    if( root == NULL )
        return true;
    return recu( root->left, root->right);
}