// Question Link :- https://leetcode.com/problems/delete-node-in-a-bst/description/
// Delete Node in a BST


// T.C = O(N) + O(N) + O(N)
// S.C = O(N)
class Solution {
public:
    void inOrder(vector<int>&ans, TreeNode* root){
        if(root == NULL) {
            return;
        }
        inOrder(ans, root->left);
        ans.push_back(root->val);
        inOrder(ans, root->right);
    }

    TreeNode* makeBST(vector<int>& result, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(result[mid]);
        node->left = makeBST(result, l, mid-1);
        node->right = makeBST(result, mid+1, r);
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> ans;
        inOrder(ans, root);

        vector<int> result;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] != key) {
                result.push_back(ans[i]);
            }
        }
        return makeBST(result, 0, result.size()-1);

    }
};
