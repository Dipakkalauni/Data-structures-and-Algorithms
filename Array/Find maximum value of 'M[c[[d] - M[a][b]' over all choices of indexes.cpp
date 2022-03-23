/*

Given a square matrix of integers, find the maximum value of `M[c][d] - M[a][b]` over every choice of indexes such that `c > a` and `d > b` in a single traversal of the matrix.

Input:

[
	[ 1,  2, -1, -4, -20],
	[-8, -3,  4,  2,  1],
	[ 3,  8,  6,  1,  3],
	[-4, -1,  1,  7, -6],
	[ 0, -4, 10, -5,  1]
]

Output: 18

Explanation: The maximum value is 18 as M[4][2] – M[1][0] has maximum difference.

Assume: matrix size > 1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMaxDiff(vector<vector<int>> &mat)
	{
		if(mat.size() == 0){  //base case
			return 0;
		}
		
		int n = mat.size();  //get size of the matrix
		
		//aux[i][j] store the maximum of elements in matrix from i,j to n-1,n-1
		 int aux[n][n];
		
		aux[n-1][n-1] = mat[n-1][n-1];//last element of aux == last element of mat
		
		 int maxi = mat[n-1][n-1]; //initialize the max
		 
		 for(int i = n-2; i >= 0; i--){  //process the last row
		 	
		 	if(mat[n-1][i] > maxi){
		 		
		 	  maxi = mat[n-1][i];
		 	}
		 	
		 	aux[n-1][i] = maxi;
		 }
		 
		 maxi = mat[n-1][n-1];
		 
		 for(int i = n-2; i >= 0; i--){ //process the last column
		 	
		 	if(mat[i][n-1] > maxi){
		 		
		 		maxi = mat[i][n-1];
		 	}
		 	
		 	aux[i][n-1] = maxi;
		 }
		 
		 maxi = INT_MIN;  //initialize max
		 
		 //preprocess the rest of the matrix from bottom
		 for(int i = n-2; i >= 0; i--){
		 	
		 	for(int j = n-2; j >= 0; j--){
		 		
		 		if(aux[i+1][j+1] - mat[i][j] > maxi){
		 			
		 			maxi = aux[i+1][j+1] - mat[i][j];
		 		}
		 		
		 		aux[i][j] = max(mat[i][j], max(aux[i][j+1], aux[i+1][j]));
		 		
		 	}
		 }
		 
		 return maxi;
	}
};
