#include<bits/stdc++.h>
using namespace std;

/*

Given two sorted integer arrays, `X[]` and `Y[]` of size `m` and `n` each, in-place merge elements of `X[]` with elements of array `Y[]` by maintaining the sorted order, i.e., fill `X[]` with the first `m` smallest elements and fill `Y[]` with remaining elements.

Input :

X[] = [1, 4, 7, 8, 10]
Y[] = [2, 3, 9]

Output:

X[] = [1, 2, 3, 4, 7]
Y[] = [8, 9, 10]

*/

class Solution
{
public:
	void merge(vector<int> &X, vector<int> &Y)
	{
		// length of vector X and Y
	    int m = X.size();
	    int n = Y.size();
	     
	     // variable to point to first element of Y
	     int j = 0;
	     
	     // Stores element  of vector x temporarily to help swapping element of vector X and Y
	     int temp;
	     
	     int k;
	     
	     // Loop through the vector X and compare the X's element with Y's first element
	    for(int i=0; i<m; i++){
	    	
	    // If Y's first element is less than the X's current element swap both.
	    // and Put the X's element in correct position in Y to maintain the order of Y.
	    
	    	if(X[i] > Y[j]){
	    		
	    		temp = X[i];
	    		X[i] = Y[j];
	    		
	    		k = 1;
	    		
	    		while(Y[k]<temp && k < n){
	    			Y[k-1] = Y[k];
	    			k++;
	    		}
	    		
	    	
	    		Y[k-1] = temp;
	    		
	    	}
	    	
	    	
	    	
	    }
	}
};
