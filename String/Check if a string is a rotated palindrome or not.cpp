/*

Given a string, check if it is a rotated palindrome or not.

Input: "CBAABCD"
Output: true
Explanation: "CBAABCD" is a rotation of the palindrome "ABCDCBA"

Input: "BAABCC"
Output: true
Explanation: "BAABCC" is a rotation of the palindrome "ABCCBA"

Input: "DCABC"
Output: false

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
   //finds if palindrome substring of length k exists or not
   //by expending low and high on both sides 
    bool isexpend(string s, int low, int high, int k){
    	
    	int n = s.size();
    	
    	while(low >= 0 && high <= n-1 && s[low] == s[high]){
    		
    		if(high - low + 1 == k ){
    			return true;
    		}
    		
    		low--;
    		high++;
    	}
    	
    	return false;
    }
   
    //finds if the palindrome of length k exists in s or not
    bool islongestpalindrome(string s, int k){
    	
    	int n = s.size();
    	
    	for(int i=0; i<n; i++){ //takes each index i as mid-point and checks if 
    		                    //palindromic substring of length k exists or not
    		                    //by taking even length and odd length substring
    		if(isexpend(s, i, i, k) || isexpend(s, i, i+1, k)){
    			return true;
    		}
    	}
    	
    	return false;
    }
    
	bool isRotatedPalindrome(string s)
	{
		int n = s.size();  //size of the string
		 
		 //return true if longest palindrome of length n exist in string s+s
		return islongestpalindrome(s+s, n);  
	}
};