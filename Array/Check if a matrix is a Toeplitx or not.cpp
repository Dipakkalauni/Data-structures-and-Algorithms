/*

Given an `M × N` integer matrix, check if it is a Toeplitz matrix or not. A Toeplitz matrix or diagonal-constant matrix is a matrix with each descending diagonal from left to right is constant.

Any `M × N` matrix `mat` is a Toeplitz matrix if mat(i, j) = mat(i+1, j+1) = mat(i+2, j+2), and so on… Here, mat(i, j) denotes the element mat[i][j] in the matrix.

Input:

[
	[3, 7, 0, 9, 8],
	[5, 3, 7, 0, 9],
	[6, 5, 3, 7, 0],
	[4, 6, 5, 3, 7]
]

Output: true

Input:

[
	[3, 7, 0, 9, 8],
	[5, 3, 7, 0, 9],
	[6, 5, 3, 7, 0],
	[4, 5, 5, 3, 7]
]

Output: false

*/

class Solution
{
public:
	bool checkToeplitz(vector<vector<int>> const &mat)
	{
		if(mat.size() == 0){ //base case
			
			return true;
		}
		
		int N = mat.size();
		int M = mat[0].size();
		
		for(int i = 0; i < N-1; i++){
			
			for(int j = 0; j < M-1; j++){
				//return false if any diagonal elements have different values
				if(mat[i][j] != mat[i+1][j+1]){
					
					return false;
				}
			}
		}
		
		return true;
	}
};