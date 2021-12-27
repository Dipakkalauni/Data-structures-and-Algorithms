/*

Given two sorted integer arrays, `X[]` and `Y[]`, and an integer `k`, find a pair `(x, y)` whose sum is closest to `k`, where the pair consists of elements from each array. The solution should return the pair `(x, y)` `x` is taken from the first array, and `y` from the second array.

Input:

X[] = [1, 8, 10, 12]
Y[] = [2, 4, 9, 15]
k = 11

Output: (1, 9)


• For some inputs, the multiple pairs are feasible. For such cases, the pair should contain elements with the least index. For example, the solution should return pair (2, 1), and not (2, 3) for the following example:

Input:

X[] = [2, 4, 6, 8, 10]
Y[] = [1, 3, 5, 7, 9]
k = 4

Output: (2, 1)


• If no pair exists, the solution should return the pair (-1, -1).

Input:

X[] = [1, 2, 3]
Y[] = []
k = 4

Output: (-1, -1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	pair<int,int> findClosestPair(vector<int> const &X, vector<int> const &Y, int k)
	{
		
		
	    pair<int, int> p;        //used to store the closest pair
	    
		int m = X.size();         // length of array X
		int n = Y.size();         // length of array Y
		
		if(m==0 || n==0){         // if either of the array has zero length, return {-1, -1}
			return {-1, -1};
		}
		
		int diff_sum = INT_MAX;    // stores abs difference between sum of pair and k.
	
		int i = 0;                 // points at start of the array X
		int j = n-1;              // points at end of the array Y
		
		while(i < m && j >= 0){     // traverse through both the array
			
			if(abs(k - (X[i] + Y[j])) < diff_sum){  //if the absolute difference between 
			                                        //k and X[i] and Y[j] < diff_sum                                
				diff_sum = abs(k - (X[i] + Y[j]));  // diff_sum = abs(k - (X[i] + Y[j]))
				p = {X[i], Y[j]};                   // change the value of pair 'p' to {X[i], Y[j]}
			}
			
			if(X[i] + Y[j] > k){                  // if X[i] + Y[j] > k, decrease j

				j--;
				
			}else if(X[i] + Y[j] < k){          // X[i] + Y[j] < k, increase i
				
				i++;
				
			}else{                             // else increase i and decrease j
				
				i++;
				j--;
			}
		}
		
		return p;
	}
	
};