class Solution {
public:
// low:  position for the next 0
// mid:  current element being checked
// high: position for the next 2

    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;

        while(mid<=high){
            // Shift 0 to beigining
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                //1 has its correct position
                mid++;

            }else{
                //Shift to the end;
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        
    }
};