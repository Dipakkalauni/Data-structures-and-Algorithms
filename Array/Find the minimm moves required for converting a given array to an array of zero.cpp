#include<bits/stdc++.h>
using namespace std;

/*

Find the minimum number of moves required for converting an array of zeroes to a given array of non-negative integers using only increment and double operations. The increment operation increases the value of an array element by 1 and the double operation doubles the value of each array element.

Input: [8, 9, 8]
Output: 7

Explanation: The optimal sequence to convert an array [0, 0, 0] to [8, 9, 8] requires 3 increment operations, followed by 3 double operations, and a single increment operation:

[0, 0, 0] —> [1, 0, 0] —> [1, 1, 0] —> [1, 1, 1] —> [2, 2, 2] —> [4, 4, 4] —> [8, 8, 8] —> [8, 9, 8]

*/

class Solution
{
public:
	int findMinMoves(vector<int> &nums)
	{
		// Here we will follow the exact opposite procedure, we'll take the vector and 
		// convert it into vector having all elements zero, 
		// for that we'll use two operations, decrement by 1 and divde by 2
        // decrement of a element by 1 increases the no of moves by 1	
        // while the division of all the elements of an array by 2, also increases
        // the no of moves by 2 
        
		int no_moves = 0;     //stores the number of moves required
		int n = nums.size();   //stores the size of an array
	    
	 while(true){       // run the loop until it does not return the no_moves
	 	
		for(int i=0; i<n; i++){  //loop through the array 
			
			if(nums[i] % 2 != 0){  // if the current element is odd, decrement it,
			                      // and increase the no_moves by 1
				nums[i]--;
				no_moves++;
			}
		}
		
		bool flag = false;;  //used to know if array contains the non-zero number
		bool odd = true;     //used to know if array contains any odd number
		
		while(odd){         // run the loop while odd is true
			
		for(int i=0; i<n; i++){   //loop through the array
			
			if(nums[i] != 0){    // if current element is not zero, set flag = true
				flag = true;    // and replace the current element by its half
				nums[i] /= 2;
			}
			
			if(nums[i] % 2 != 0){  // if the new element in current index is odd,
				odd = false;        // set odd to flase
			}  
		}
		
		if(flag == true){      // if flag == true i.e. there is non zero number in array, increase no_moves
			no_moves++;
		}else{                 // else if all elements are zero, return no_moves
			return no_moves;
			
		}
		
		}
		
	 }
	}
};