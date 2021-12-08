#include<bits/stdc++.h>
using namespace std;
/*

Given an unsorted integer array, find a pair with the given sum in it.

• Each input can have multiple solutions. The output should match with either one of them.

Input : nums[] = [8, 7, 2, 5, 3, 1], target = 10
Output: (8, 2) or (7, 3)

• The solution can return pair in any order. If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [5, 2, 6, 8, 1, 9], target = 12
Output: (-1, -1)

*/

class Solution
{
public:
	pair<int,int> findPair(vector<int> const &nums, int target)
	{
		// Declare the pair to store the answer
		  pair<int, int> ans;
		  
		  //Declare the unordered_set to check whether a element exists whose sum with the  current element gives             // the target number
		   
		   unordered_set<int> sum_checker;
		  
		  // Loop through the given array to find the required sum
		  
		  for(int i=0; i<nums.size(); i++){
		  	
		  	// check whether the target-nums[i] exists in the unordered_set or not
		  	  // if yes then (nums[i], target-nums[i]) is the ans 
		  	  // if no then insert nums[i] in the unordered_set.
		  	  
		  	  if(sum_checker.find(target-nums[i])==sum_checker.end()){
		  	  	  sum_checker.insert(nums[i]);
		  	  }else{
		  	  	  ans.first = target-nums[i];
		  	  	  ans.second = nums[i];
		  	  	  
		  	  	  return ans;
		  	  }
		  	    
		  }
		  
		  // if no required pair is found
		   return {-1, -1};
		
	}
};



// Driver code

int main(){
    // create a object of the above class
     Solution sol;
    
    // input the size of the vector and the target sum
      int n, target;
      cin  >> n >> target;
   
     vector<int> nums(n);

  // Input the vector elements
      for(int i=0; i<n; i++){
           cin >> nums[i];
      }
  
    // call the findPair method of the solution class ;
     pair<int, int> ans = sol.findPair(nums, target);

   // Print the returned value
     cout << ans.first << " " << ans.second << endl;

}

