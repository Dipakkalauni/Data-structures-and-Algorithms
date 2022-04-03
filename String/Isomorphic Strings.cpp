/*

Given two strings, check if they are isomorphic. Two strings, X and Y, are called isomorphic if all occurrences of each character in X can be replaced with another character to get Y and vice-versa.

Note that mapping from a character to itself is allowed, but the same character may not replace two characters.

Input: X = "ACAB", Y = "XCXY"
Output: true
Explanation: The strings "ACAB" and "XCXY" are isomorphic as we can map 'A' to 'X', 'B' to 'Y', and 'C' to 'C'.

Input: X = "xbxb", Y = "Ybyb"
Output: false

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool isIsomorphic(string X, string Y)
	{
		if(X.size() != Y.size()){  //if the strings are not equal in size, return false
			
			return false;
		}
		
		unordered_map<char, char> map;  //stores a mapping of a character from X to Y
		
		unordered_set<char> set;  //stores the mapped character
		
		for(int i=0; i<X.size(); i++){ // traverse the strings
			
			if(map.find(X[i]) == map.end()){ //if X[i] is not seen before
				                              // then check if Y[i] is mapped or not
				if(set.find(Y[i]) != set.end()){ //if yes, return false
					                                //else insert a mapping of X[i] and Y[i] to map and Y[i] to set
					return false;
				}
				
				map[X[i]] = Y[i];
				
				set.insert(Y[i]);
				
			}else if(map[X[i]] != Y[i]){    //if X[i] is seen before but not mapped to Y[i]
				                             // return false;
				return false;
			}
		}
		
		return true;
	}
};