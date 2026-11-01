
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0; //Position to place the next valid element

        //Traverse the entire array
        for(int i=0;i<nums.size(); i++){
            //Keep only elements that are not equal to val
            if(nums[i]!=val){
                nums[k]=nums[i]; //Place valid element
                k++;               //Move to next position
            }
        }

        //Number of elements remaining after removal
        return k;
    }
};
