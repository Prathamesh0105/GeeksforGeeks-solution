/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  bool isSym(Node* a, Node* b){
    if(!a||!b) return a==b;
    if(a->data!=b->data) return false;
    return isSym(a->left,b->right)&&isSym(a->right,b->left);
  }
 public:
    bool isSymmetric(Node* r){
        return !r||isSym(r->left,r->right);
    }
};