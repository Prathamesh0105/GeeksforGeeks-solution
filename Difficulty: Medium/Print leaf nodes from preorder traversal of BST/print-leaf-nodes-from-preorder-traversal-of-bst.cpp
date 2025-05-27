class Solution {
public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaves;
        int idx = 0;
        helper(preorder, idx, INT_MIN, INT_MAX, leaves);
        return leaves;
    }

private:
    void helper(const vector<int>& preorder, int& idx, int minVal, int maxVal, vector<int>& leaves) {
        if (idx >= preorder.size()) return;

        int val = preorder[idx];
        if (val < minVal || val > maxVal) return;

        idx++;
        int currIdx = idx;

        helper(preorder, idx, minVal, val - 1, leaves);
        helper(preorder, idx, val + 1, maxVal, leaves);

        if (idx == currIdx) {
            leaves.push_back(val);
        }
    }
};
