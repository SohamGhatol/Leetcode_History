class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> result;
        //Sorting the data for two pointers and skipping the duplicates
        sort(nums.begin(),nums.end());

        //Select the first element
        for(int i=0;i<n;i++){
            //Skip duplicates
            if(i>0 && nums[i]==nums[i-1]) continue;
            //Select second element
            for(int j=i+1;j<n;j++){
                //Skip duplicate second element
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                // Search for the remaining two elements
                int left=j+1,right=n-1;
                while(left<right){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[left];
                    sum+=nums[right];
                    if(sum==target){
                        //Got the vallid quadrant
                        vector<int> quad={nums[i],nums[j],nums[left],nums[right]};
                        result.push_back(quad);
                         // Move both pointers after finding a match
                        left++;
                        right--;

                         // Skip duplicate third elements
                        while(left<right && nums[left]==nums[left-1] ) left++;
                        // SKip duplicate fourth elements
                        while( left<right && nums[right]==nums[right+1] ) right--;
                    }
                    else if(sum<target){
                        //Sum if tooo Small
                         left++;    
                    }else if(sum>target){
                        //Sum is too large
                        right--;
                    }
                }
            }
        }
        return result;
    }
};