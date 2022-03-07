/*

Given a non-empty integer array, find the minimum and maximum element in the array by making minimum comparisons, and return the (min, max) element pair.

Input: [5, 7, 2, 4, 9, 6]
Output: (2, 9)

Explanation:

The minimum array element is 2
The maximum array element is 9

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	pair<int,int> findMinAndMax(vector<int> const &nums)
	{
		int n = nums.size();         //size of the array
		
		bool odd = false;            // flag to indicate if n is odd or even
		
		pair<int, int> p;            // stores the minimum and maximum element
		
		if(n%2 != 0){               // if n is odd, decrease n by 1, and set odd to true
			n--;
			odd = true;
		}
		
		int mini = INT_MAX;        //stores the minimum and maximum element of whole array
		int maxi = INT_MIN;
		
		for(int i=0; i<n; i+=2){   //traverse the array
			
			int maximum, minimum;
			
			if(nums[i] > nums[i+1]){  //calculate min and max element between ith and i+1th element
				minimum = nums[i+1];
				maximum = nums[i];
			}else{
				minimum = nums[i];
				maximum = nums[i+1];
			}
			
			mini = min(mini, minimum);  //update global mini and maxi
			maxi = max(maxi, maximum);
			
		}
		 
		if(odd){             // if odd is true, compare mini and maxi with last element in the array
			maxi = max(maxi, nums[n]);
			mini = min(mini, nums[n]);
		}
		
		p.first = mini;       //insert mini and maxi in pair and return pair
		p.second = maxi;
		
		return p;
	}
};
