/*

Given an `M × N` binary matrix, fill it with alternating rectangles of 1’s and 0’s.

Input: 10 × 8 matrix
Output:

[
	[1, 1, 1, 1, 1, 1, 1, 1],
	[1, 0, 0, 0, 0, 0, 0, 1],
	[1, 0, 1, 1, 1, 1, 0, 1],
	[1, 0, 1, 0, 0, 1, 0, 1],
	[1, 0, 1, 0, 0, 1, 0, 1],
	[1, 0, 1, 0, 0, 1, 0, 1],
	[1, 0, 1, 0, 0, 1, 0, 1],
	[1, 0, 1, 1, 1, 1, 0, 1],
	[1, 0, 0, 0, 0, 0, 0, 1],
	[1, 1, 1, 1, 1, 1, 1, 1]
]


Input: 3 × 5 matrix
Output:

[
	[1, 1, 1, 1, 1],
	[1, 0, 0, 0, 1],
	[1, 1, 1, 1, 1]
]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void fillMatrix(vector<vector<int>> &mat)
	{
		if(mat.size() == 0){
			
			return;
		}
		
		int N = mat.size();
		int M = mat[0].size();
		
		int left = 0;
		int right = M-1;
		
		int top = 0;
		int bottom = N-1;
		
		bool flag = 1;
		
		while(1){
			
			if(left > right){
				break;
			}
			
			for(int i=left; i<=right; i++){
				 mat[top][i] = flag;
			}
			
			top++;
			
			if(top > bottom){
				return;
			}
			
			for(int i=top; i <= bottom; i++){
				
				mat[i][right] = flag;
			}
			right--;
			
			if(left > right){
				return;
			}
			
			for(int i = right; i>=left; i--){
				mat[bottom][i] = flag;
			}
			bottom--;
			
			if(top > bottom){
				return;
			}
			
			for(int i=bottom; i>=top; i--){
				mat[i][left] = flag;
			}
			
			left++;
			
			flag = !flag;
			
		}
	}
};
