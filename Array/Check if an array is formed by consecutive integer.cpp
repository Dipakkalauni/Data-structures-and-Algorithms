/*

Given an integer array, check if only consecutive integers form the array.

Input : [-1, 5, 4, 2, 0, 3, 1]
Output: true
Explanation: The array contains consecutive integers from -1 to 5.

Input : [4, 2, 4, 3, 1]
Output: false
Explanation: The array does not contain consecutive integers as element 4 is repeated.

Input : [2, 5, 3, 1]
Output: false
Explanation: The array does not contain consecutive integers as element 4 is missing.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  
	bool isConsecutive(vector<int> const &nums)
	{
		int n = nums.size();                //Stores the size of the array
		unordered_set<int> set;            //used to check if an array contains the distinct interger
		
		if(n <= 1){                   //if size of the array <= 1, return true;
			return true;
		}
		
		int maxi = INT_MIN;          //stores the maximum element in the array
		int mini = INT_MAX;          //stores the minimum element in the array
		
		for(int i=0; i<n; i++){      //traverse the array
			
			if(nums[i] < mini){       //check for the minimum element
				mini = nums[i];
			}
			
			if(nums[i] > maxi){      //check for the maximum element
				maxi = nums[i];
			}
			
			if(set.find(nums[i]) == set.end()){    //check if the current element is distinct or not
				                                   //if not, return false
				set.insert(nums[i]);
			}else{
				
				return false;
			}
		}
		
		if(maxi - mini == n-1){  //if max_element - min_element == n-1, return true, else false
		
			return true;
			
		}else{
			
			return false;
		}
	}
};