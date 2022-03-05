/*

Given three sorted arrays of variable length, efficiently compute the minimum range with at least one element from each array.

Input : [[3, 6, 8, 10, 15], [1, 5, 12], [4, 8, 15, 16]]
Output: (3, 5)

Input : [[2, 3, 4, 8, 10, 15], [1, 5, 12], [7, 8, 15, 16]]
Output: (4, 7)

Input : [[1], [1, 2], [0, 1]]
Output: (1, 1)

If minimum range doesn't exist, the solution should return the pair (-1, -1).

Input : [[], [], []]
Output: (-1, -1)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	pair<int,int> findMinRange(vector<int> const &X, vector<int> const &Y, vector<int> const &Z)
	{
		int i=0;
		int j=0;
		int k=0;
		
		int min_range = INT_MAX;
		pair<int,int> p;
	    bool flag = true;
	  while(i<X.size() && j<Y.size() && k < Z.size()){
	  	  int minimum = min(X[i], min(Y[j], Z[k]));
	  	  int maximum = max(X[i], max(Y[j], Z[k]));
	  	  
	  	  int range = maximum - minimum;
	  	  
	  	  if(range < min_range){
	  	  	min_range = range;
	  	  	p.first = minimum;
	  	  	p.second = maximum;
	  	  	flag = false;
	  	  }
	  	  
	  	  if(minimum == X[i]){i++;}
	  	  else if(minimum == Y[j]){j++;}
	  	  else{k++;}
	  	  
	  }	
	  
	  if(flag == true){
	  	p.first = -1;
	  	p.second = -1;
	  }
	  return p;
		
	}
};
