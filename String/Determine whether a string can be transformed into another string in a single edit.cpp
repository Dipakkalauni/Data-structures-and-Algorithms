/*

Given two strings, determine whether the first string can be transformed into the second string with a single edit operation. An edit operation can insert, remove, or replace a character in the first string.

Input : X = "xyz", Y = "xz"
Output: true
Explanation: The total number of edits required is 1 (remove 'y' from the first string)

Input : X = "xyz", Y = "xyyz"
Output: true
Explanation: The total number of edits required is 1 (add 'y' in the first string)

Input : X = "xyz", Y = "xyx"
Output: true
Explanation: The total number of edits required is 1 (replace 'z' in the first string by 'x')

Input : X = "xyz", Y = "xxx"
Output: false
Explanation: The total number of edits required are 2 (replace 'y' and 'z' in the first string by 'x')

Input : X = "xyz", Y = "xyz"
Output: false
Explanation: The total number of edits required is 0 (both strings are the same)

*/

class Solution
{
public:
	bool isTransformable(string X, string Y)
	{
		int n = X.size();  //size of string X and Y
		int m = Y.size();
		
	
		if(abs(n - m) > 1){  //if size of X and Y vary by more than 1, return false
			return false;
		}
		
		int edit = 0;  //stores the number of edits to be made
		
		int i = 0;   //keeps track of indexes of X and Y
		int j = 0;
		
		while(i < n && j < m){  //loop till either string runs out
			
			if(X[i] != Y[j]){  //if ith and jth character of both string do not match
				
				if(m > n){    //if string Y is bigger than X, increase j
					
					j++;
				}else if(n > m){  //if string X is bigger than Y, increase i
					
					i++;
				}else{           //else increase both
					i++;
					j++;
				}
				
				edit++; //increase edit
				
			}else{ //if current character of both string are equal, move to the next character
			
			i++;
			j++;
			
			}
		}
		
		if(i < n){  //remove any extra character in X
			edit++;
		}
		
		if(j < m){  //add any extra character in Y
			
			edit++;
		}
		
		if(edit == 1){  //if edit == 1, return true else return false
			return true;
		}
		
		return false;
		
	}
};