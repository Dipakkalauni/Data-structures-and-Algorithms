/*

Given an `M × N` integer matrix, find the common elements present in all rows of the matrix. The solution should traverse the matrix once and return the common elements.

Input:
[
	[7, 1, 3, 5, 3, 6],
	[2, 3, 6, 1, 1, 6],
	[6, 1, 7, 2, 1, 4],
	[6, 6, 7, 1, 3, 3],
	[5, 5, 6, 1, 5, 4],
	[3, 5, 6, 2, 7, 1],
	[4, 1, 4, 3, 6, 4],
	[4, 6, 1, 7, 4, 3]
]

Output: {1, 6}

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	unordered_set<int> findCommonElements(vector<vector<int>> const &mat)
	{
	    unordered_set<int> ans;
	    
	    if(mat.size()==0){
	    	return ans;
	    }
	    
	    int N = mat.size();
	    int M = mat[0].size();
	    
	    unordered_map<int, int> map;
	    
	    for(int i = 0; i < M; i++){
	    	map.insert({mat[0][i], 1});
	    }
	    
	     for(int i=1; i<N; i++){
	     	
	     	for(int j=0; j<M; j++){
	     		
	     	  if(map.find(mat[i][j]) != map.end() && map[mat[i][j]] == i){
	     	  	  
	     	  	  map[mat[i][j]] = i+1;
	     	  }
	     	}
	     }
	     
	     
	     for(auto it : map){
	     	
	     	if(it.second == N){
	     		ans.insert(it.first);
	     	}
	     }
	     
	     return ans;
	}
};
