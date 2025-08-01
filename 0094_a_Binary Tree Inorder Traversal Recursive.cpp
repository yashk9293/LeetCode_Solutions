// Question Link :- https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// Binary Tree Inorder Traversal


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// T.C = O(N)
// S.C = O(N)
void Inorder(TreeNode* root, vector<int>& ans){
    if(root == NULL){
        return ;
    }
    Inorder(root->left, ans);
    ans.push_back(root->val);
    Inorder(root->right, ans);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Inorder(root, ans);
        return ans;
    }
};