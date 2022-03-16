/*

Given an `N × N` integer matrix, rotate the matrix by 180 degrees in a clockwise direction. The transformation should be done in-place in quadratic time.

Input:

[
	[1,  2,  3,  4],
	[5,  6,  7,  8],
	[9,  10, 11, 12],
	[13, 14, 15, 16]
]

Output:

[
	[16, 15, 14, 13],
	[12, 11, 10, 9],
	[8,  7,  6,  5],
	[4,  3,  2,  1]
]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void rotateMatrix(vector<vector<int>> &mat)
	{
		
		if(mat.size() == 0){
			return;
		}
		
		int N = mat.size();
	
		
		for(int i=0; i<N/2; i++){
			
			for(int j=0; j<N; j++){
				
				swap(mat[i][j], mat[N-i-1][N-j-1]);
			}
		}
		
		if(N % 2 != 0){
			
			for(int i=0; i<N/2; i++){
				
				swap(mat[N/2][i], mat[N/2][N-i-1]);
			}
		}
	}
};
