/*

Check if a given string can be derived from another string by circularly rotating it. The rotation can be in a clockwise or anti-clockwise rotation.

Input: X = "ABCD", Y = "DABC"
Output: true
Explanation: "DABC" can be derived from "ABCD" by right-rotating it by 1 unit

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool check(string X, string Y)
	{
		if(X.size() != Y.size()){  //if both string are not equal in size, return false
			
			return false;
		}
		
		for(int i = 0; i < X.size(); i++){  
			
			// in-place left rotate string s by 1 unit.
			rotate(X.begin(), X.begin()+1, X.end());
			
			if(!X.compare(Y)){  //return true if 'X' becomes equal to 'Y'
				 
				return true;
			}
		}
		
		return false;
	}
};