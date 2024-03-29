/*

Given an unsorted integer array `A` of size `n`, whose elements lie in the range 0 to `n-1`, rearrange the array such that `A[A[i]]` is set to `i` for every array element `A[i]`. Do this in linear time and without using any extra constant space.

Input : [1, 3, 4, 2, 0]
Output: [4, 0, 3, 1, 2]
Explanation:

A[0] = 1, A[1] becomes 0
A[1] = 3, A[3] becomes 1
A[2] = 4, A[4] becomes 2
A[3] = 2, A[2] becomes 3
A[4] = 0, A[0] becomes 4

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void rearrange(vector<int> &A)
	{
		
		int n = A.size();
	  //traverse the array and increment element at A[i]th index by i*n
	    for(int i=0; i<n; i++){
	    	
	    	A[A[i] % n] += i*n;
	    }
	    
	    // traverse the array again and replace A[i] with A[i]/n
	    for(int i=0; i<n; i++){
	    	
	    	A[i] = A[i]/n;
	    }
	}
};