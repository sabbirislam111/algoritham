#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrack(nums, result, start + 1);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> generate_permutations(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, result, 0);
    return result;
}

int main() {
    vector<int> nums = {1, 2,3};
    vector<vector<int>> permutations = generate_permutations(nums);
    for (vector<int>& permutation : permutations) {
        for (int& num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
