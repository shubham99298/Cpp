class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Sort the numbers in ascending order
        sort(nums.begin(), nums.end());
        //1 2 3
        // Use a set to store distinct numbers
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        // Convert the set into a vector to access elements by index
        vector<int> sortedDistinctNums(s.begin(), s.end());
        
        // If there are less than 3 distinct numbers, return the largest
        if (sortedDistinctNums.size() < 3) {
            return sortedDistinctNums.back(); // Return the maximum number
        } else {
            return sortedDistinctNums[sortedDistinctNums.size() - 3]; // Return the third maximum number
        }
    }
};
