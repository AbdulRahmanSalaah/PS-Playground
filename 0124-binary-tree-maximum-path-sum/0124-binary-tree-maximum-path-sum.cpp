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
    int maxPathSum(TreeNode* root) {
        int sum = root->val;
        dfs(root, sum);
        return sum;
    }

    int dfs(TreeNode* root, int& sum) {
        if (!root)
            return 0;

        // compute the path from the one of the children to the other
        // seems to try spliting but its not bec we return the
        // max(lmax,rmax)+val
        int lmax = dfs(root->left, sum);
        int rmax = dfs(root->right, sum);
        lmax = max(lmax, 0);
        rmax = max(rmax, 0);
        sum = max(sum, root->val + lmax + rmax);

        return root->val + max(lmax, rmax);
    }
};