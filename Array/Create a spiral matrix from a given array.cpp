/*

Given an integer array containing `N × N` elements, construct an `N × N` matrix from it in spiral order.

Input: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]

Output:

[
	[ 1   2   3   4  5],
	[16  17  18  19  6],
	[15  24  25  20  7],
	[14  23  22  21  8],
	[13  12  11  10  9]
]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> createSpiralMatrix(vector<int> const &nums)
	{
	  int n = nums.size();  //stores the size of the array
	  
	  int m = sqrt(n);  //find the square root of n, so we can create m*m matrix
	  
	  vector<vector<int>> mat;  //declare a 2d matrix
	  
	  if(n == 0){    //if array is empty return empty mat
	  	return mat;
	  }
	  
	  mat.resize(m, vector<int>(m)); //resize the 2d matrix as m*m matrix
	  
	   int left = 0;
	   int right = m-1;
	   
	   int top = 0;
	   int bottom = m-1;
	   
	   int i = 0;  //points to the index of array from beginning to the end
	   
	   while(1){
	   	  
	   	  if(left > right){
	   	  	break;
	   	  }
	   	  //print the top row
	   	  for(int j = left; j<=right; j++){
	   	  	 mat[top][j] = nums[i];
	   	  	 i++;
	   	  }
	   	  top++;
	   	  
	   	  if(top > bottom){
	   	  	break;
	   	  }
	   	  // print the right column
	   	  for(int j=top; j<=bottom; j++){
	   	  	mat[j][right] = nums[i];
	   	  	i++;
	   	  }
	   	  right--;
	   	  
	   	  if(left > right){
	   	  	break;
	   	  }
	   	  //print the bottom row
	   	  for(int j=right; j>=left; j--){
	   	  	mat[bottom][j] = nums[i];
	   	  	i++;
	   	  }
	   	  bottom--;
	   	  
	   	  if(top > bottom){
	   	  	break;
	   	  }
	   	  //print the left column
	   	  for(int j=bottom; j>=top; j--){
	   	  	mat[j][left] = nums[i];
	   	  	i++;
	   	  }
	   	  left++;
	   	  
	   }
	   
	   return mat;
	}
};
