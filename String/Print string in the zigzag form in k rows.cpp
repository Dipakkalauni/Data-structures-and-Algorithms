/*

Given a string and a positive integer `k`, print the string in `k` rows in the zigzag form.

Input:

str = "THISPROBLEMISAWESOME"
k = 3

Output: "TPLSSHSRBEIAEOEIOMWM"

Explanation:

(Row 1)		T				P				L				S				S
(Row 2)			H		S		R		B		E		I		A		E		O		E
(Row 3)				I				O				M				W				M


Note: If `k` is more than length of the string, return the whole string.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string printZigZag(string s, int k)
	{
		int n = s.size();  //size of the string
		
		vector<char> arr(n); 
		
		string res = ""; //stores the final string
		
		if(k == 0){  //base case
			return res;
		}
		
		if(k == 1){  //base case
			return s;
		}
		
		int j = 0;
		  // print first row
		for(int i=0; i<n && j<n; i += (k-1)*2){
			
			arr[j] = s[i];
			j++;
		}
		  //print middle rows
		for(int i=1; i < k-1 && j < n; i++){
			
			int l = i;
			bool down = true;
			
			while(l < n){
				
				 arr[j] = s[l];
				 
				 if(down){
				 	
				 	l += (k-1-i)*2;
				 }else{
				 	
				 	l += (k-1)*2 - (k-i-1)*2;
				 }
				 
				 down = !down;
				 j++;
				 
			}
		}  
		  //print last rows
		for(int i = k-1; i<n && j<n; i += (k-1)*2){
			
			arr[j] = s[i];
			j++;
		}
		

		for(int i=0; i<n; i++){
			res += arr[i];
		}
		
		return res;
	}
};