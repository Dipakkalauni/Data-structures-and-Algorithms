/*

Given a string and a positive number `k`, find the longest substring of the string containing `k` distinct characters. If `k` is more than the total number of distinct characters in the string, return the whole string.

Input: s = "abcbdbdbbdcdabd", k = 2
Output: "bdbdbbd"

Input: s = "abcbdbdbbdcdabd", k = 3
Output: "bcbdbdbbdcd"

Input: s = "abcbdbdbbdcdabd", k = 5
Output: "abcbdbdbbdcdabd"

The longest distinct character substring is not guaranteed to be unique. If multiple longest distinct substring exists, the solution should return the one which appear first in the string.

Input: s = "abcd", k = 3
Output: "abc"
Explanation: There are two longest distinct substrings in "abcd" having 3 distinct characters, namely, "abc" and "bcd". The solution returns "abc" as it appears before "bcd" in the string.


*/

class Solution
{
public:
	string findLongestSubstring(string s, int k)
	{
	  int n = s.size();  //size of the string
	   
	  string res = "";  //stores the longest substring having k distinct characters
	   
	  if(n == 0){
	  	
	  	  return res;
	  }
	  
	   unordered_map<char, int> map;  //map to store the distinct characters and their frequency 
	   
	    int i = 0; int j = 0;  //i,j maintains the sliding windows boundary
	    int max_count = 0;    //max_count stores the maximum number of characters of in a substring
	    int count = 0;       // stores the number of characters in a current substring
	    
	   for(i = 0, j = 0; j < n; j++){  //traverse the string
	   	
	    		map[s[j]]++;      //and insert the characters into map and increase their frequency
	    		count++;          // increase count
	    	
	    	while(map.size() > k){  // if windows size > k, remove characters from left
	    		
	    		map[s[i]]--;
	    		
	    		if(map[s[i]] == 0){  //if the characters frequency becomes zero, erase it from map
	    			
	    			map.erase(s[i]);
	    		}
	    		count--; 
	    		i++;       //decrease the window size
	    	}
	    	
	    	if(count > max_count){   //update the max_count
	    		
	    		max_count = count;
	    		res = s.substr(i, j-i+1);
	    	}
	    }
	    
	    return res;
	}
};