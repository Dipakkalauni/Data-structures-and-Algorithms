/*

Give an `M × N` binary matrix, change all elements of row `i` and column `j` to 0 if cell (i, j) has value 0.

Input:
[
	[1, 1, 0, 1, 1],
	[1, 1, 1, 1, 1],
	[1, 1, 1, 0, 1],
	[1, 1, 1, 1, 1],
	[0, 1, 1, 1, 1]
]

Output:
[
	[0, 0, 0, 0, 0],
	[0, 1, 0, 0, 1],
	[0, 0, 0, 0, 0],
	[0, 1, 0, 0, 1],
	[0, 0, 0, 0, 0]
]

Explanation:

0’s are present at (0, 2), (4, 0), and (2, 3) in the input matrix. Therefore, every element of the following cells is changed to 0:

• row 0 and column 2
• row 4 and column 0
• row 2 and column 3

*/

#include<bits/c++.h>
using namespace std;

class Solution
{
public:
	void convertMatrix(vector<vector<int>> &mat)
	{
		bool firstrow = false;
		bool firstcol = false;
		
		//base case
		if(mat.size() == 0){
			return;
		}
		
		//check the first row for any zero
		for(int i=0; i<mat[0].size(); i++){
			
			if(mat[0][i] == 0){
				firstrow = true;
				break;
			}
		}
		
		//check the first col for any zero
		for(int i=0; i<mat.size(); i++){
			
			if(mat[i][0] == 0){
				firstcol = true;
				break;
			}
		}
		
		
		//if any cell in the rest of the matrix has a value of zero,
		// mark the corresponding cell int first row and column as zero
		for(int i=1; i<mat.size(); i++){
			
			for(int j=1; j<mat[0].size(); j++){
				
				if(mat[i][j] == 0){
					mat[0][j] = 0;
					mat[i][0] = 0;
				}
			}
		}
		
		// if any cell in the first row has zero value, make all value of corresponding column zero
		for(int i = 0; i < mat[0].size(); i++){
			
			if(mat[0][i] == 0){
				
				for(int j=0; j<mat.size(); j++){
					
					mat[j][i] = 0;
				}
			}
		}
		
		//if any cell in the first column has zero value, make all value of corresponding row zero
		for(int i = 0; i < mat.size(); i++){
			
			if(mat[i][0] == 0){
				
				for(int j=0; j<mat[0].size(); j++){
					
					mat[i][j] = 0;
				}
			}
		}
		
		//if firstrow is true, make all cell of first row zero
		if(firstrow == true){
			
		for(int i=0; i<mat[0].size(); i++){
			
			mat[0][i] = 0;
		
		}
		
	}
		
		//if firstcol is true, make all cell of first column zero
		if(firstcol == true){
			
			for(int i=0; i<mat.size(); i++){
			
	      	  mat[i][0] = 0;
		}
	}
		
		
	}
};