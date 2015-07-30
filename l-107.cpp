#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > result;
        if(root == NULL) return result;

        dfs(result, root, 0);
        std::reverse(result.begin(), result.end());
        return result;
    }
    void dfs(vector< vector<int> > &level, TreeNode* root, int dep) {
        if(dep >= level.size()) {
            vector<int> tmp;
            level.push_back(tmp);
        }
        level[dep].push_back(root->val);
        if(root->left ) dfs(level, root->left , dep+1);
        if(root->right) dfs(level, root->right, dep+1);
    }
};

int main() {

    return 0;
}
