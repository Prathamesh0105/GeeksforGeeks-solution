class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        auto computeSum = [&](int d) {
            int total = 0;
            for (int num : arr) {
                total += (num + d - 1) / d;
            }
            return total;
        };

        int low = 1, high = *max_element(arr.begin(), arr.end());
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currSum = computeSum(mid);

            if (currSum <= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
