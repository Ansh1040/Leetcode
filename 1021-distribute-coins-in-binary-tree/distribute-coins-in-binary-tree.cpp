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
private:
    int traverse (TreeNode* root, int& ans) {
        if(root==NULL) return 0;
        int coins = root->val + traverse (root->left, ans) + traverse (root->right, ans);
        coins--;
        ans += abs(coins);
        return coins;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        traverse (root, ans);
        return ans;
    }
};