/*

Given a string, find the length of the longest contiguous substring, such that the length of the substring is `2×n` digits and the sum of the leftmost `n` digits is equal to the sum of the rightmost `n` digits. If there is no such substring, return 0.

Input : 13267224
Output: 6
Explanation: 326722 = (3 + 2 + 6) = (7 + 2 + 2) = 11

Input : 546374
Output: 4
Explanation: 4637 = (4 + 6) = (3 + 7) = 10

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
	int findLongestPalindrome(string s)
	{
		int n = s.size();  //size of the string
		
		int max_len = 0;  //stores the maximum length of contiguous substring
	
		for(int i=0; i<n; i++){ //traverse through the string
			                    //consider each ith and i+1th element as the mid point and expand on both sides
			                    //to find the maximum length contiguous substring whose sum of left side is 
			                    // equal to the sum of right side
			int left = i;
			int right = i+1;
			
			int left_sum = 0;
			int right_sum = 0;
			
			while(left >= 0 && right < n){
				
				left_sum += (int)(s[left]);
				right_sum += (int)(s[right]);
				
				if(left_sum == right_sum && max_len < right-left+1){
					
					max_len = right-left+1;
				
				}
				
				left--;
				right++;
			}
		}
		
		return max_len;
	}
};