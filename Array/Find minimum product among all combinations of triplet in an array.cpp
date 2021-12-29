/*

Given an integer array, find the minimum product among all combinations of triplets in the array.

Input : [4, -1, 3, 5, 9]
Output: -45
Explanation: The minimum product triplet is (-1, 5, 9)

Input : [1, 4, 10, -2, 4]
Output: -80
Explanation: The minimum product triplet is (10, 4, -2)

Input : [3, 4, 1, 2, 5]
Output: 6
Explanation: The minimum product triplet is (3, 1, 2)

Input : [1, 2]
Output: 0
Explanation: Invalid input

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		int n = nums.size();     //stores the size of the array
		
		if(n <= 2){             //if size of the array <= 2, return 0
			return 0;
		}
		
		sort(nums.begin(), nums.end());  //sort the array in increasing order
		
		if(nums[0] >= 0){     //if first element of the array is a non-negative integer, return product
			                  // of first three element
			return nums[0]*nums[1]*nums[2]; 
			
		}else {   // else find the product of first element and last two element
			      //and also find the product of three three triplet, 
			      //compare the value and return  the least one.
			 int product_1 = nums[0]*nums[1]*nums[2];
			 int product_2 = nums[0]*nums[n-1]*nums[n-2];
			 
			 if(product_1 > product_2){
			 	
			 	return product_2;
			 	
			 }else{
			 	
			 	return product_1;
			 	
			 }
		}
	}
};