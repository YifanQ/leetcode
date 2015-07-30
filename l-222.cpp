/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        visitTree(root, cnt);
        return cnt;
    }
    void visitTree(TreeNode* n, int &cnt) {
        if(n != NULL) {  //cannot be written as (!n) ???
            ++cnt;
            visitTree(n->left, cnt);
            visitTree(n->right,cnt);
        }
        // return ;
    }
};
