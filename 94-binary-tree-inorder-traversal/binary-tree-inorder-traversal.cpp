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
class Solution {
public:
    vector<int> ans;

    void inorder(TreeNode* root) {

        // Base case: No node exists
        if (root == NULL) return;

        // Step 1: Visit left subtree
        inorder(root->left);

        // Step 2: Visit current node
        ans.push_back(root->val);

        // Step 3: Visit right subtree
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        inorder(root);

        return ans;  
    }
};