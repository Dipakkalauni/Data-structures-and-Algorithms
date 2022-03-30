/*

Given a string, find the maximum length contiguous substring of it that is also a palindrome.

Input: "bananas"
Output: "anana"

Input: "abdcbcdbdcbbc"
Output: "bdcbcdb"

The longest palindromic substring is not guaranteed to be unique. If multiple longest palindromic substring exists, the solution should return the one which appear first in the string.

Input: "abracadabra"
Output: "aca"
Explanation: There is no palindromic substring in a string "abracadabra" with a length greater than 3. There are two palindromic substrings with length 3, namely, "aca" and "ada". The solution returns "aca" as it appears before "ada" in the string.

Input: "dcabc"
Output: "d"

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string expand(string s, int low, int high){
    	
    	while(low >=0 && high < s.size() && s[low] == s[high]){
    		
    		low--;
    		high++;
    	}
    	
    	return s.substr(low + 1, high - low - 1);
    }
    
	string longestPalindromicSubstring(string s)
	{
		int n = s.size(); //stores the size of the string
		
		if(n == 0){  //if string is empty, return
			return s;
		}
		 
		 string max = "";  //stores the max length palindromic substring found so far
		 
		 int maxi = 0;  //stores the length of the max-length palindromic substring
		 
		 string curr = "";  //stores the current palindromic substring
		 
		for(int i = 0; i < s.size(); i++){ //traverse the string
			                               //ans consider the ith element as the midpoint of palindromic
		  curr = expand(s, i, i);          //substring and expand in both directions
			
			if(curr.size() > maxi){
				
				maxi = curr.size();
				max = curr;
			}
			
			curr = expand(s, i, i+1);
			
				
			if(curr.size() > maxi){
				
				maxi = curr.size();
				max = curr;
			}
			
		}
		
		return max;
	}
};