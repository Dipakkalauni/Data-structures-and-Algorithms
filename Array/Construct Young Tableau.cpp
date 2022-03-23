/*

Given an integer array containing n elements, construct an `N × N` Young tableau from it where N is ceil of square root of n. i.e., N = ceil(sqrt(n)).

An `N × N` Young tableau is an `N × N` matrix such that the entries of each row are sorted from left to right and the entries of each column are sorted from top to bottom. Some entries of a Young tableau may be infinity, which indicates an empty entry.

Input: [12, 10, 20, 22, 25, 30, 34, 11, 44, 27, 16, 40, 35, 15, 18, 45]

Output: [
	[10, 11, 12, 15],
	[16, 18, 20, 22],
	[25, 27, 30, 34],
	[35, 40, 44, 45]
]

OR [
	[10, 12, 15, 16],
	[11, 18, 20, 25],
	[22, 27, 30, 35],
	[34, 40, 44, 45]
]

OR, any other valid `N × N` Young tableau.


Input: [12, 10, 20, 22, 25, 30, 34, 11, 27, 16]

Output: [
	[10,  11,  12,  16],
	[20,  22,  25,  27],
	[30,  34,  inf, inf],
	[inf, inf, inf, inf]
]

Here, inf = INT_MAX

OR, any other valid `N × N` Young tableau.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insert(vector<vector<int>> &mat, int i, int j){
    	
    	if(i == 0 && j == 0){  //base case
    		return;
    	}
    	
    	//for the first row
    	if(i == 0){
    		
    		if(mat[i][j] < mat[i][j-1]){
    			swap(mat[i][j], mat[i][j-1]);
    			insert(mat, i, j-1);
    		}
    		return;
    	}
    	
    	//for the first column
    	if(j == 0){
    		
    		if(mat[i][j] < mat[i-1][j]){
    			swap(mat[i][j], mat[i-1][j]);
    			insert(mat, i-1, j);
    		}
    		return;
    	}
    	
    	if(mat[i][j] < mat[i-1][j]){  //go up
    		swap(mat[i][j], mat[i-1][j]);
    		insert(mat, i-1, j);
    	}
    	
    	if(mat[i][j] < mat[i][j-1]){  // go left
    		swap(mat[i][j], mat[i][j-1]);
    		insert(mat, i, j-1);
    	}
    }
    
    
	vector<vector<int>> constructYoungTableau(vector<int> const &keys)
	{
		int N = ceil(sqrt(keys.size()));
		
		vector<vector<int>> mat(N, vector<int>(N, INT_MAX));
		
		int n = keys.size();
		
		for(int i=0; i<n; i++){
			
			mat[N-1][N-1] = keys[i];
			insert(mat, N-1, N-1);
		}
		
		return mat;
	
	}
};
