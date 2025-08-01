// Question Link :- https://leetcode.com/problems/binary-tree-inorder-traversal/
// Iterative Inorder Traversal

// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true) {
            if(node != NULL) {
                st.push(node);
                node = node-> left;
            }
            else {
                if(st.empty() == true) {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node-> val);
                node=node-> right;
            }
        }
        return inorder;
    }
};