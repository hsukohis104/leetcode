/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // struct new_TreeNode {
 //      int val;
 //      int right_node_num;
 //      struct TreeNode *left;
 //      struct TreeNode *right;
 // };
int count = 0;
int ans = 0;
void inorder(struct TreeNode* root, int k){
    if(root == NULL || count >= k )
        return;
    inorder(root->left, k);
    if(count < k){
        ans = root->val;
        count++;
    }
    inorder(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k){
    ans = 0;
    count = 0;
    inorder(root, k);
    return ans;
}