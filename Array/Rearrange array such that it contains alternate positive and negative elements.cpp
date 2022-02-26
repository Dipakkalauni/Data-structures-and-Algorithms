#include<bits/stdc++.h>
using namespace std;
/*

Given an integer array, rearrange it such that it contains positive and negative numbers at alternate positions. Assume that all values in the array are non-zero.

• In case the multiple rearrangement exists, the solution can return any one of them.

Input : [9, -3, 5, -2, -8, -6, 1, 3]
Output: [9, -3, 5, -2, 1, -8, 3, -6] or [5, -2, 9, -6, 1, -8, 3, -3] or any other valid combination..

• If the array contains more positive or negative elements, the solution should move them to the end of the array.

Input : [9, -3, 5, -2, -8, -6]
Output: [5, -2, 9, -6, -3, -8] or [-2, 5, -6, 9, -3, -8] or any other valid combination..

Input : [5, 4, 6, -1, 3]
Output: [5, -1, 4, 6, 3] or [-1, 5, 4, 6, 3] or any other valid combination..

*/

class Solution
{
public:
	void rearrange(vector<int> &nums)
	{
			  int n = nums.size();   //size of the array
		       int j = 0;            
		
		
		for(int i=0; i<n; i++){  //loop through the array
		 if(nums[i] < 0){          // if the element < 0, swap the element to the jth position
		 	swap(nums[i], nums[j]);
		 	j++;
		 }
		}
		
		int k = 0;  // point to the index where the positive numbers must
                  // be swaped in order to maintain the alternate order

        while(k < j && j < n){        //loop while the positive numbers are exhausted
            swap(nums[k], nums[j]);   // and swap the positive numbers to the kth index
            k += 2;                    //increase the kth index by 2
            j++;                       //increase the jth index by 1;
        }
		
	}
};


