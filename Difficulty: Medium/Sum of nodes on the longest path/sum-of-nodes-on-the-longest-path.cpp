/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void dfs(Node* node, int currLen, int currSum, int &maxLen, int &maxSum) {
        if (!node) return;
        
        currLen++;
        currSum += node->data;
        
        if (!node->left && !node->right) {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxSum = currSum;
            } else if (currLen == maxLen && currSum > maxSum) {
                maxSum = currSum;
            }
            return;
        }
        
        dfs(node->left, currLen, currSum, maxLen, maxSum);
        dfs(node->right, currLen, currSum, maxLen, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = 0, maxSum = 0;
        dfs(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};
