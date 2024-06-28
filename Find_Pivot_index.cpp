class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total=0;

        for(auto it:nums){
            total=total+it; //28
        }
        int Leftsum=0;

        for(int i=0; i<nums.size(); i++){
           total=total-nums[i]; // 27 

           if(Leftsum==total){
            return i;   
           }
           Leftsum=Leftsum+nums[i];  //1 8 11 17 22 28
        }
        return -1;
    }
};