/*

Given an integer array, count the total number of triplets, which leads to an inversion. If (i < j < k) and (nums[i] > nums[j] > nums[k]), then the triplet (i, j, k) has formed an inversion in array `nums`.

Input : [1, 9, 6, 4, 5]
Output: 2
Explanation: There are two inversions of size three in the array: (9, 6, 4) and (9, 6, 5).

Input : [9, 4, 3, 5, 1]
Output: 5
Explanation: There are five inversions of size three in the array: (9, 4, 3), (9, 4, 1), (9, 3, 1), (4, 3, 1), and (9, 5, 1).

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findInversionCount(vector<int> const &nums)
	{
		int n = nums.size();   //stores the size of the array
		
		int count = 0;          //stores the count of inversions
		
		for(int i=1; i<n-1; i++){  //loop through the array, considering the current element as middle element
			
			int greater = 0;     // stores count of element greater than current element 
			                     // in the left hand side of the array
			                     
			for(int j = 0; j < i; j++){   
				
				if(nums[j] > nums[i]){
					greater++;
				}
			}
			
			int smaller = 0;        // stores the count of element smaller than current element
			                        // in the right hand side of the array
			for(int j=i+1; j<n; j++){
				
				if(nums[j] < nums[i]){
					
					smaller++;
				}
			}
			
			count += (greater * smaller);  //add the product of greater and smaller to the count
		} 
		
		return count;        // return count
	}
};