/*

Given an `M × N` integer matrix, which is row-wise and column-wise sorted (with all strictly increasing elements in any row or column), report the coordinates of all occurrences of a given element in it in linear time.

Input:

matrix =
[
	[-4, -3, -1, 3, 5],
	[-3, -2, 2, 4, 6],
	[-1, 1, 3, 5, 8],
	[3, 4, 7, 8, 9]
]

target = 3

Output: {(0, 3), (2, 2), (3, 0)}

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	set<pair<int,int>> findElement(vector<vector<int>> const &mat, int target)
	{
		set<pair<int,int>> pairs;

		if(mat.size() == 0){
			
			return pairs;
		}
		
		int N = mat.size();
		int M = mat[0].size();
		
		int i = 0;
		int j = M-1;
		
		while(i < N && j >= 0){
			
			if(mat[i][j] < target){
				
				i++;
				
			}else if(mat[i][j] > target){
				
				j--;
			}else{
				
				pairs.insert({i, j});
				i++;
				j--;
			}
		}

		return pairs;
	}
};
