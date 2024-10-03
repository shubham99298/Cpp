class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i=0;
        int j=numbers.size()-1;
        vector<int>Indexes;

        while(i<j){
         
         if(numbers[i]+numbers[j]>target){
            j--;
         }
         else if(numbers[i]+numbers[j]==target){
            Indexes.push_back(i+1);
            Indexes.push_back(j+1);
            break;
         }
         else{
            i++;
         }
        }
        return Indexes;
    }
};