/*

Find the maximum amount of water that can be trapped within a given set of bars where each bar’s width is 1 unit.

Input : [7, 0, 4, 2, 5, 0, 6, 4, 0, 5]
Output: 25
Explanation: The maximum amount of water that can be trapped is 25.

Pictorial representation: https://techiedelight.com/practice/images/TrappingRainWater.png


Input : [10, 8, 6, 5, 4, 2]
Output: 0

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int trapWater(vector<int> const &bars)
	{
	  int n = bars.size();  // Stores the size of the array
	  
	  if(n <= 1){         // if array has less than or equal to 1 elements, return 0;
	  	return 0;
	  }
	  
	  int water = 0;  // Stores the to maximum amount of water that can be trapped
	  
	 int left = 0;          // points to the left end of the array
	 int right = n - 1;      // points to the right end of the array
	 
	 int maxLeft = bars[left];  // max height at the left side of the array
	 int maxRight = bars[right];  // max height at the right side of the array
	 
	  while(left < right){ //loop through the array while left < right
	  	
	  	if(bars[left] <= bars[right]){   // if element at left index <= right index
	  		
	  		left++;                       // increase the left index and update the maxLeft
	  		                             // by comparing maxLeft with element pointed by current maxLeft
	  		maxLeft = max(maxLeft,  bars[left]);  
	  		water +=  maxLeft - bars[left];  //add difference between maxLeft and element pointed by left into water
	  	}else{
	  		
	  		right--;                        // same is true for the else condition
	  		
	  		maxRight = max(maxRight, bars[right]);
	  		water += maxRight - bars[right];
	  	}

	  }
	  
	  return water;
	  
	}
};