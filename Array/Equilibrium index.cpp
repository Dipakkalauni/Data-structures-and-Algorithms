/*

Given an integer array, return all equilibrium index in it. For an array `A[0..n-1]`, index `i` is an equilibrium index if the sum of elements of subarray `A[0…i-1]` is equal to the sum of elements of subarray `A[i+1…n-1]`.

Input : [0, -3, 5, -4, -2, 3, 1, 0]
Output: {0, 3, 7}
Explanation: For each index `i` in the output, A[0] + A[1] + … + A[i-1] = A[i+1] + A[i+2] + … + A[n-1]

Input : [-7, 3, 7, -3, 1]
Output: {4}
Explanation: `n-1` is an equilibrium index if A[0] + A[1] + … + A[n-2] sums to 0.

Input : [1, 2, -4, 2]
Output: {0}
Explanation: 0 is an equilibrium index if A[1] + A[2] + … + A[n-1] sums to 0.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	unordered_set<int> findEquilibriumIndex(vector<int> const &nums)
	{
		unordered_set<int> indices;
		
        int n = nums.size();  // size of the vector nums
         
        int total = 0;     // stores total sum of the elements
        
        for(int i=0; i<n; i++){  // loop through the array to find the total sum
        	total += nums[i];
        }
        
            int right = 0;      // stores the sum of right subarray
            
        for(int i=n-1; i>=0; i--){  //loop through the array from right to left
        	
        	// At current index 'i' if the right sum of right subarray nums[i+1] to nums[n-1]
        	// is equal to the sum of left subarray nums[0] to nums[i-1]
        	// We can calculate the left subarry sum by total - (nums[i] + right)
        	if(right == total - (nums[i] + right)){ 
        		 indices.insert(i);
        	}
        	
        	right += nums[i];
        }
        
         return indices;
	}
};
