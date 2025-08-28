/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int preorderPos = 0;
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l > r)
            return NULL;

        int rootval = preorder[preorderPos++];
        TreeNode* root = new TreeNode(rootval);

        int idx = mp[rootval];

        root->left = dfs(preorder, l, idx - 1);
        root->right = dfs(preorder, idx + 1, r);

        return root;
    }
};