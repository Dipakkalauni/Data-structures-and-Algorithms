#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array, check if it contains a contiguous subarray having zero-sum.

Input : [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
Output: true
Explanation: The subarrays with zero-sum are

[3, 4, -7]
[4, -7, 3]
[-7, 3, 1, 3]
[3, 1, -4]
[3, 1, 3, 1, -4, -2, -2]
[3, 4, -7, 3, 1, 3, 1, -4, -2, -2]

Input : [4, -7, 1, 2, -1]
Output: false
Explanation: The subarray with zero-sum doesn't exist.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool hasZeroSumSubarray(vector<int> const &nums)
	{

		// Declare the unordered set to store the current sum
		unordered_set<int> s;
         // initialize it with zero to handle the cases when current sum is zero
		 s.insert(0);
		 
         // Declare the sum variable to calculate the current_sum;
		 int sum = 0;
        
        // Loop through the array
		for(int i=0; i<nums.size(); i++){
         // calculate the current sum at each iteration
			sum += nums[i];

         // if the sum is not present in the unordered_set
         // insert into the set.
         // else return true
			if(s.find(sum)==s.end()){
				s.insert(sum);
			}else{
				return true;
			}
		}

	   // if nothing is returned, return false;
		return false;
	}
};


// Driver code

int main(){
    // create the object of the solution class
      Solution sol;

      // input the vector and its size;
       int n;
       cin >> n;

         vector<int> nums;

       for(int i=0; i<n; i++){
          cin >> nums[i];
       }
     
     // print the returned value
       cout << sol.hasZeroSumSubarray(nums) << endl;
}