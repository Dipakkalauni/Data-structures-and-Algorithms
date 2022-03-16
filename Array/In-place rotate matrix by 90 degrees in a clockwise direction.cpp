/*

Given an `N × N` integer matrix, rotate the matrix by 90 degrees in a clockwise direction. The transformation should be done in-place and in quadratic time.

Input:

[
	[1,  2,  3,  4],
	[5,  6,  7,  8],
	[9,  10, 11, 12],
	[13, 14, 15, 16],
]

Output:

[
	[13, 9,  5, 1],
	[14, 10, 6, 2],
	[15, 11, 7, 3],
	[16, 12, 8, 4]
]

*/

class Solution
{
public:
	void rotateMatrix(vector<vector<int>> &mat)
	{
		int N = mat.size(); //size of N*N matrix
		
		if(N == 0){  //base case
			return;
		}
		
		//transpose a matrix
		for(int i=0; i<N; i++){
			
			for(int j=0; j<i; j++){
				
				swap(mat[i][j], mat[j][i]);
			}
		}
		
		//swap the columns
		for(int i=0; i < N/2; i++){
			
			for(int j=0; j<N; j++){
				
				swap(mat[j][i], mat[j][N-i-1]);
			}
		}
	}
};