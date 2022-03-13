/*

Given an `M × N` integer matrix, return all its diagonal elements having a positive slope.

Input:

[
	[1, 2, 3, 4, 5],
	[2, 3, 4, 5, 6],
	[3, 4, 5, 6, 7],
	[4, 5, 6, 7, 8],
	[5, 6, 7, 8, 9]
]

Output:

[
	[1]
	[2, 2],
	[3, 3, 3],
	[4, 4, 4, 4],
	[5, 5, 5, 5, 5],
	[6, 6, 6, 6],
	[7, 7, 7],
	[8, 8],
	[9]
]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	 void diagonalTraversal(vector<vector<int>>  &mat)
	{
		int n = mat.size();
		int m = mat[0].size();
		
		vector<vector<int>> diagonal;
		
		if( mat.size() == 0){
			return ;
		}
		
		for(int i=0; i<mat.size(); i++){
			
		    vector<int> ans;
		      
		for(int r=i, j=0; r>=0 && j<mat[0].size(); r--, j++){
				ans.push_back(mat[r][j]);
				
			}
			
			diagonal.push_back(ans);
		}
		
		for(int i=1; i<mat[0].size(); i++){
			
		
			vector<int> ans;
			
			for(int r = i, j = mat.size()-1; j>=0 && r <= mat[0].size() - 1; j--, r++){
				
				ans.push_back(mat[j][r]);
				
			}
			
			diagonal.push_back(ans);
		}
		for(int i=0; i<diagonal.size(); i++){
            for(int j=0; j<diagonal[i].size(); j++){
                cout << diagonal[i][j] << " ";
            }
            cout << endl;
        }
		
	}
};

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    Solution obj;
    obj.diagonalTraversal(mat);
}