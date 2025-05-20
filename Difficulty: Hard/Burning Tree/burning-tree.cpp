//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void markParents(Node* root, std::unordered_map<Node*, Node*>& parentMap, Node*& targetNode, int target) {
        std::queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == target) {
                targetNode = curr;
            }
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int minTime(Node* root, int target) {
        std::unordered_map<Node*, Node*> parentMap;
        Node* targetNode = nullptr;
        
        markParents(root, parentMap, targetNode, target);
        
        std::unordered_set<Node*> visited;
        std::queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;
            
            for (int i = 0; i < size; ++i) {
                Node* curr = q.front();
                q.pop();

                if (curr->left && !visited.count(curr->left)) {
                    burned = true;
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    burned = true;
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if (parentMap.count(curr) && !visited.count(parentMap[curr])) {
                    burned = true;
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
            if (burned) time++;
        }
        
        return time;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends