/*

Given two sorted arrays of integers, find a maximum sum path involving elements of both arrays whose sum is maximum. You can start from either array, but can switch between arrays only through its common elements.

Input:

X = [3, 6, 7, 8, 10, 12, 15, 18, 100]
Y = [1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50]

Output: The maximum sum is 199

Explanation: The maximum sum path is 1 —> 2 —> 3 —> 6 —> 7 —> 9 —> 10 —> 12 —> 15 —> 16 —> 18 —> 100

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMaxPathSum(vector<int> const &X, vector<int> const &Y)
	{     
		 
		 int m = X.size();
		 int n = Y.size();
		 
		 int sum = 0;
		 
		 int sum_x = 0;
		 int sum_y = 0;
		 
		 int i=0;
		 int j=0;
		 
		 while(i < m && j < n){
		 	
		 	while(X[i] == X[i+1]){
		 		sum_x += X[i];
		 		i++;
		 	}
		 	
		 	while(Y[j] == Y[j+1]){
		 		sum_y += Y[j];
		 		j++;
		 	}
		 	 
		 	 if(Y[j] < X[i]){
		 	 	
		 	 	 sum_y += Y[j];
		 	 	 j++;
		 	 	 
		 	 }else if(X[i] < Y[j]){
		 	 	
		 	 	sum_x += X[i];
		 	 	i++;
		 	 	
		 	 }else{
		 	 	
		 	 	sum_x += X[i];
		 	 	sum_y += Y[j];
		 	 	
		 	 	sum += max(sum_x, sum_y);
		 	 	i++;
		 	 	j++;
		 	 	
		 	 	sum_y = 0;
		 	 	sum_x = 0;
		 	 }
		 }
		 
		 
		 while(i < m ){
		 	
		 	 sum_x += X[i];
		 	 i++;
		 }
		 
		 while(j < n){
		 	
		 	sum_y += Y[j];
		 	j++;
		 }
		 
		 sum += max(sum_x, sum_y);
		 
		 return sum;

	}
};