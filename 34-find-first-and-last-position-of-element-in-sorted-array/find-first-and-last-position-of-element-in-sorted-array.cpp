class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int left =0,right=nums.size()-1,first=-1,last=-1;
        
        //Find the FIrst occurance
        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target){
                first=mid;// Saving the first possible position
                right=mid-1;// Search further left
            }
            else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

       //If the target doesnt exist then return [-1,--1]
       if(first==-1){
        return {-1,-1};
       }

       //Find the Last Occurances
       left=first;
       right=nums.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target){
                last=mid;// Saving the last possible position
                left=mid+1;// Search further right
            }
            else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

       return {first,last};
    }
};