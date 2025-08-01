// Question Link :- https://leetcode.com/problems/rotate-array/description/
// Rotate Array

// Approach - 1
// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);   // here imp to give the size, else it will give error
        for(int i=0; i<n; i++) {
            temp[(i+k) % n] = nums[i];
        }
        nums=temp;     // or  for(int i=0; i<nums.size(); i++) nums[i] = temp[i];
    }     
};



// Approach - 2
// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> back;
        int n = nums.size();
        k = k%n;
        for (int i=0; i<k; i++){
            back.push_back(nums[n-k+i]);  // inserting last element of nums in back vector
        }
        for (int i=0; i<n-k; i++){
            back.push_back(nums[i]);      // inserting starting numbers of nums in back vector
        }
        nums = back;
    }
};



// Approach - 3 
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
// we can do also by  pointer for reversing





// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]