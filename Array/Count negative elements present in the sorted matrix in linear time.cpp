/*

Given an `M × N` row-wise and column-wise sorted integer matrix, find the total number of negative numbers in it in linear time.

Input:

[
	[-7, -3, -1, 3, 5],
	[-3, -2,  2, 4, 6],
	[-1,  1,  3, 5, 8],
	[ 3,  4,  7, 8, 9]
]

Output: 6

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int negativeCount(vector<vector<int>>  &mat)
	{
		//base case
		if(mat.size() == 0){
			return 0;
		}
		
		int M = mat.size();
		int N = mat[0].size();
		
	
		// (i, j) point to the cell in the matrix
		// and at start it points to top rightmost cell of the matrix i.e. (0, M-1)
		int i = 0;
		int j = N-1;
		
		int count = 0; //used to store the count of negative number 
		
		while(i <= M-1 &&  j >= 0){ //traverse till the condition is true
			
			if(mat[i][j] < 0){ // if the current element is negative
				               //increment the count and i
				count += j+1;
				i++;
				
			}else{  // else decrease j
				
				j--;
			}
		}
		
		return count;
	}
};
