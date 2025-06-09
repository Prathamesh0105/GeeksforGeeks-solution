/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool dfs(Node* root, int l, int r) {
        if (!root) return false;
        if (!root->left && !root->right && l == r) return true;
        return dfs(root->left, l, root->data - 1) || dfs(root->right, root->data + 1, r);
    }
    bool isDeadEnd(Node* root) {
        return dfs(root, 1, INT_MAX);
    }
};