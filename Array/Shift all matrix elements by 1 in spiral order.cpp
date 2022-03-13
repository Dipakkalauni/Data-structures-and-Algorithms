/*

Given an `M × N` integer matrix, shift all its elements by `1` in spiral order.

Input:

[
	[ 1,  2,  3,  4, 5],
	[16, 17, 18, 19, 6],
	[15, 24, 25, 20, 7],
	[14, 23, 22, 21, 8],
	[13, 12, 11, 10, 9]
]

Output:

[
	[25,  1,  2,  3, 4],
	[15, 16, 17, 18, 5],
	[14, 23, 24, 19, 6],
	[13, 22, 21, 20, 7],
	[12, 11, 10,  9, 8]
]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void shiftMatrix(vector<vector<int>> &mat)
	{
		
	   if(mat.size() == 0){
	   	  return;
	   }
		
	   int left = 0;
	   int right = mat[0].size()-1;
	   
	   int top = 0;
	   int bottom = mat.size()-1;
	   
	  int prev_val = mat[0][0];
	  
	 
	   while(1){
	   	  
	   	  if(left > right){
	   	  	break;
	   	  }
	   	  //print the top row
	   	  
	   	  for(int j = left; j<=right; j++){
	   	  	
	   	  	swap( mat[top][j], prev_val);
	   	  }
	   	  top++;
	   	  
	   	  if(top > bottom){
	   	  	break;
	   	  }
	   	  // print the right column
	   	  for(int j=top; j<=bottom; j++){
	   	  	
	   	  swap(mat[j][right], prev_val);
	   	  	
	   	  }
	   	  right--;
	   	  
	   	  if(left > right){
	   	  	break;
	   	  }
	   	  //print the bottom row
	   	  for(int j=right; j>=left; j--){
	   	  
	   	  	swap(mat[bottom][j], prev_val);
	   	  	
	   	  }
	   	  bottom--;
	   	  
	   	  if(top > bottom){
	   	  	break;
	   	  }
	   	  //print the left column
	   	  for(int j=bottom; j>=top; j--){
	   	  
	   	  	swap(mat[j][left], prev_val);
	   	  
	   	  }
	   	  left++;
	   	  
	   }
	   
	   mat[0][0] = prev_val;
	   
	   
	}
};