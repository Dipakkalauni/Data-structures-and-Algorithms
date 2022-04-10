/*

Given a string, remove adjacent duplicates characters from it. In other words, remove all consecutive same characters except one.

Input : "AABBBCDDD"
Output: "ABCD"

*/

class Solution
{
public:
	void removeAdjacentDuplicates(string &s)
	{
		int n = s.size();  //stores the size of the string
		
		if(n == 0){  //base case
			
			return;
		}
		
		string res = "";  //stores the resulting string
		
	      res += s[0];
		
		for(int i = 1; i < n; i++){  //traverse the string 
			
		    if(s[i] != s[i-1]){  //if current character != previous character, include the current
		    	                 //character in the resulting string
		    	res += s[i];
		    }
		}
		
		s = res;  //set s = resulting string
	}
};