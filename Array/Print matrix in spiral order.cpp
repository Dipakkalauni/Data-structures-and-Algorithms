/*

Given an `M × N` integer matrix, return its elements in spiral order.

Input:

[
	[ 1   2   3   4  5],
	[16  17  18  19  6],
	[15  24  25  20  7],
	[14  23  22  21  8],
	[13  12  11  10  9]
]

Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]

*/

#include<bits.c++.h>
using namespace std;

class Solution
{
public:
	vector<int> spiralTraversal(vector<vector<int>> const &mat)
	{
		 vector<int> ans; //used to store the elements of a matrix in spiral order
		
		 if(mat.size() == 0){ //base case
		 	return ans;
		 }
		 
	    int left = 0;  
	    int right = mat[0].size()-1;
	    
	    int top = 0;
	    int bottom = mat.size()-1;
	    
	  
	   
	    
	    while(1){
	    	
	    if(left > right){
	    	break;
	    }
	    
	    //print top row
	    for(int i=left; i<=right; i++){
	    	ans.push_back(mat[top][i]);
	    }
	    top++;
	    
	    
	      if(top > bottom){
	      	break;
	      }
	      
	      //print right column
	    for(int i=top; i<=bottom; i++){
	    	ans.push_back(mat[i][right]);
	      }
	    right--;
	    
	    if(right < left){
	     	break;
	     }

	     //print bottom row
	    for(int i=right; i>=left; i--){
	    	ans.push_back(mat[bottom][i]);
	    }
	    bottom--;
	    
	    if(top > bottom){
	      	break;
	     }

	     //print left column
	    for(int i=bottom; i>=top; i--){
	    	ans.push_back(mat[i][left]);
	    }
	    
	    left++;
	    
	   }

	
	return ans;
	}
};
