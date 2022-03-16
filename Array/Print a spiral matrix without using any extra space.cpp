/*

Given a positive number `N`, return an `N × N` spiral matrix containing numbers from 1 to `N × N` in a counterclockwise direction.

Input: N = 5

Output:
[
	[25, 24, 23, 22, 21],
	[10, 9,  8,  7,  20],
	[11, 2,  1,  6,  19],
	[12, 3,  4,  5,  18],
	[13, 14, 15, 16, 17]
]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> spiralTraversal(int N)
	{
		vector<vector<int>> mat(N, vector<int>(N)); //declare a 'N*N' vector
	
		int total = N*N;      //number to be filled int mat spirally
		
		int left = 0;
		int right = N-1;
		
		int top = 0;
		int bottom = N-1;
		
		while(1){
			if(left > right){
				break;
			}
			
			for(int i=left; i<=right; i++){
				mat[top][i] = total;
				total--;
			}
			top++;
			
			if(top > bottom){
				break;
			}
			
			for(int i=top; i<=bottom; i++){
				mat[i][right] = total;
				total--;
			}
			right--;
			
			if(left > right){
				break;
			}
			
			for(int i=right; i>=left; i--){
				mat[bottom][i] = total;
				total--;
			}
			bottom--;
			
			if(top > bottom){
				break;
			}
			
			for(int i=bottom; i>=top; i--){
				
				mat[i][left] = total;
				total--;
			}
			
			left++;
			
		}
		
		return mat;
	}
};
