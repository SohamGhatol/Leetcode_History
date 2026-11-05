class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index,vector<int>&nums,vector<int>& ds) {

        //Every current combination is a valid subset
        ans.push_back(ds);

        //Try choosing each remaining element
        for(int i=index;i<nums.size();i++){
            ds.push_back(nums[i]); // Include current element
            solve(i+1,nums,ds); // Explore remaining elements
            ds.pop_back(); // Backtrack: remove current element
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        solve(0,nums,ds);
        return ans;
    }
};

