#include <iostream>
#include <cstdio>

using namespace std;

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
        if(root == NULL) return 0;

        int h0 = getH0(root); // 0, 1, 2 ...
        int h1 = getH1(root);

        if(h1 == h0) {
            printf("== %d\n", h0);
            return (1<<(h0+1)) - 1;
        }
        if(h1 == h0 - 1) {
            //number of leaves is [1, 2^h0]
            //corresponding binary is [0, 2^h0-1] = [0*h0, 1*h0]
            int l = 0;
            int r = (1<<h0) - 1;
            int mid; //l = h0, r = h1
            while(l < r-1) {
                mid = (l+r)/2;
                if(testDepth(root, mid, h0)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            printf("l = %d, r = %d\n", l,r);
            return (1<<(h1+1)) - 1 + (l+1);
        }
    }
    bool testDepth(TreeNode* root, int mid, int h0) {
        int testBit = 1<<(h0-1);
        while(testBit > 1) {
            if((mid & testBit) == 0)
                root = root->left;
            else
                root = root->right;
            testBit>>=1;
        }
        if((mid & testBit) == 0)
            return root->left != NULL;
        else
            return root->right != NULL;
    }

    int getH0(TreeNode* root) {
        int h0 = 0;
        while(root->left != NULL) {
            ++h0;
            root = root->left;
        }
        return h0;
    }
    int getH1(TreeNode* root) {
        int h1 = 0;
        while(root->right != NULL) {
            ++h1;
            root = root->right;
        }
        return h1;
    }
};
