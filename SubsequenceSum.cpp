#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool solve(int idx, int sum, vector<int>& nums, int k) {
    if (sum == k)
        return true;

    if (idx == nums.size())
        return false;

    // take current element
    if (solve(idx + 1, sum + nums[idx], nums, k))
        return true;

    // not take current element
    if (solve(idx + 1, sum, nums, k))
        return true;

    return false;
}

bool isSubsequenceSumK(vector<int>& nums, int k) {
    return solve(0, 0, nums, k);
}
};

int main() {
    vector<int>arr = {1, 2, 3, 5, 4};
    int k = 100;
    Solution sol;
    if(sol.isSubsequenceSumK(arr, k)) {
        cout << "True";
    } else {
        cout << "False";
    }
}
