/*

Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.

Input : [0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void sortArray(vector<int> &nums)
	{
		// Set 1  as the pivot element
		int pivot = 1;
		
		
		int low = 0;
		
		int mid = 0;
		
		int high = nums.size()-1;
		
		while(mid <= high){
			
			if(nums[mid] < pivot){
				
			  swap(nums[low], nums[mid]);
			  
				low++;
				mid++;
				
			}else if(nums[mid] > pivot){
				
				swap(nums[high], nums[mid]);
				
				high--;
				
			}else{
				
				mid++;
				
			}
		}
	}
};
