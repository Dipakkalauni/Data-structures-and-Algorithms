/*

Given a string, find all palindromic permutations of it.

Input : "xyxzwxxyz"
Output: {"xxyzwzyxx", "xxzywyzxx", "xyxzwzxyx", "xyzxwxzyx", "xzxywyxzx", "xzyxwxyzx", "yxxzwzxxy", "yxzxwxzxy", "yzxxwxxzy", "zxxywyxxz", "zxyxwxyxz", "zyxxwxxyz"}

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	unordered_set<string> findPalindromicPermutations(string s)
	{
		
		int n = s.size();  //size of the string
		
		unordered_set<string> set;  //stores all the palindromic permutation
		
		if(n == 0){  // base cae
			
			return set;
		}
		
		unordered_map<char, int> map;  //stores the characters and their frequency
		
		string res = "";  // stores the left half of the palindromic substring
		
		for(int i=0; i < n; i++){ //loop through the map and store the 
			                       //frequency of each character of a string in a map
			map[s[i]]++;
		}
		 
		  int odd_num = 0;  //stores the odd characters count
		  string odd = "";  //stores the odd character
		  
		for(auto itr : map){  //iterate through the map
			
			char ch = itr.first;    //current character
			int c = itr.second;     //character count
			
			if(c % 2 != 0){   //if the character count is odd
				
				odd = ch; 
				
				if(++odd_num > 1){ //if odd character count > 1 , return
			
		       	return set;
		      }
		      
			   c = c-1;           //make count even
			   odd = itr.first;  //update mid
			}
			
			c = c/2;  //append c/2 character to the left-half
			
			while(c--){
				
				res += ch;  
			}
			
		}
		
	//sort the left half to generate permutation in lexicographical order
		sort(res.begin(), res.end());
		
		while(1){
			
		    string right = res; //the right half will be the reverse of left half
			
			reverse(right.begin(), right.end()); 
			
			set.insert(res + odd + right); //insert the string made of res + odd + right into the set
			
			//find the next lexicographically greater permutation
			if(!next_permutation(res.begin(), res.end())){
				
				break;
			}
		}
		
		
	}
};
