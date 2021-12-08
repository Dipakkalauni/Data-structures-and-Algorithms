#include<bits/stdc++.h>
using namespace std;

 /*

Given two sorted integer arrays `X[]` and `Y[]` of size `m` and `n` each where `m >= n` and `X[]` has exactly `n` vacant cells, merge elements of `Y[]` in their correct position in array `X[]`, i.e., merge `(X, Y)` by keeping the sorted order.

Input : Two arrays X[] and Y[] where vacant cells in X[] is represented by 0.

X[] = [0, 2, 0, 3, 0, 5, 6, 0, 0]
Y[] = [1, 8, 9, 10, 15]

Output: X[] = [1, 2, 3, 5, 6, 8, 9, 10, 15]

*/

class Solution
{
public:
	void merge(vector<int> &X, vector<int> &Y)
	{
		//length of vector X and Y
		int m = X.size();
		int n = Y.size();
		
		//rearrange the vector X so all the non-zero elements 
		// are at the beginning of the vector
		int k = 0;
		for(int i=0; i<m; i++){
			
			if(X[i] != 0){
				X[k] = X[i];
				k++;
			}
		}
		
		// merge the two vector

		// k is the index up to which there are non-zero element in X.
		 k = k- 1;

		 m = m - 1;
		 n = n - 1;
		 
		 // loop through the both the vectors
		 // and compare each elements from end 
		while(k >= 0 && n >= 0){
    
			if(X[k] > Y[n]){
				X[m] = X[k];
				k--;
				m--;
			}else{
				X[m] = Y[n];
				 m--;
				 n--;
			}
		}
		
		// loop through Y, if remaining
		while(n >= 0){
			X[m] = Y[n];
			m--;
			n--;
		}
	  
	}
};
