/*

Run–length encoding (RLE) is a simple form of lossless data compression that runs on sequences with the same value occurring many consecutive times. It encodes the sequence to store only a single value and its count.

Input: "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW"
Output: "12W1B12W3B24W1B14W"
Explanation: String can be interpreted as a sequence of twelve W’s, one B, twelve W’s, three B’s, and so on..

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string encode(string s)
	{
		int n = s.size();   //stores the size of s
		
		if(n == 0){  
			return s;
		}
		
		int i = 1;     //keeps track of the index of string
		int count = 1;  //counts the same consecutive characters
		string res = "";  //stores the encoded string
		
		while(i < n){  //loop through the string
			
			if(s[i] == s[i-1]){   //if current character is equal to previous character, increase count
				
				count++;
			}else{              //else add count and previous character into res
				
			   res += to_string(count) + s[i-1];
			   count = 1;
			}
			
			i++;
		}
		
	    	res += to_string(count) + s[i-1];  
	    	
	    	return res;
	}
};
