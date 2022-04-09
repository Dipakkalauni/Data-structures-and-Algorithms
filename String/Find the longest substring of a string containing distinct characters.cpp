/*

Given a string, find the longest substring containing distinct characters.

Input : "longestsubstr"
Output: "longest"

Input : "abbcdafeegh"
Output: "bcdafe"

Input : "aaaaaa"
Output: "a"

The longest distinct character substring is not guaranteed to be unique. If multiple longest distinct substring exists, the solution should return the one which appear first in the string.

Input: "cbabc"
Output: "cba"
Explanation: There are two longest distinct substrings in "cbaabc" of length 3, namely, "cba" and "abc". The solution returns "cba" as it appears before "abc" in the string.

*/

class Solution
{
public:
	string findLongestSubstring(string s)
	{
		int n = s.size();  //stores the size of string
		
		string res = "";   //stores the maximum length substring having distinct characters
	
		unordered_set<char> set; //used to maintain the window that stores 
		                          //all the distinct characters
		int i = 0; //i,j keeps track of start and end point of the window
		int j = 0;
		
		while(j < n){  //loop through the string
			
			if(set.find(s[j]) == set.end()){  //if the jth element is distinct than the previous
				                               // character in the window insert s[j] in window
				set.insert(s[j]);
				j++;
			}else{         //else increase 'i' till the jth element is removed from the window
				
				while(set.find(s[j]) != set.end()){
					set.erase(s[i]);
					i++;
				}
			}
			
			if(s.substr(i, j-i).size() > res.size()){  //if the current window is greater than the previous
				                                  //substring containing i.e. res distinct characters update
				res = s.substr(i, j-i);            // res
			}
			
			
		}
		
		return res;
	}
};