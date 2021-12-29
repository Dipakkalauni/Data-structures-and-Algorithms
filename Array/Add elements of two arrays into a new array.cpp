/*

Given two arrays of positive integers, add their elements into a new array. The solution should add both arrays, one by one starting from the 0'th index, and split the sum into individual digits if it is a 2–digit number.

Input : [23, 5, 2, 7, 87], [4, 67, 2, 8]
Output: [2, 7, 7, 2, 4, 1, 5, 8, 7]

Input : [], [4, 67, 2, 8]
Output: [4, 6, 7, 2, 8]

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	vector<int> add(vector<int> const &X, vector<int> const &Y)
	{
	    vector<int> ans;           //stores the final array
	    
	    int m = X.size();           //stores the length of the first array
	    int n = Y.size();           //stores the length of the second array
	    
	    
	    
	    int i = 0;            //points to the 0th index of X array
	    int j = 0;            //points to the 0th index of Y array
	    
	    while(i < m && j < n){  //loop through both the array
	    	
	    	int sum = X[i] + Y[j];  //add the ith and jth elements of X and Y array
	    	vector<int> temp;        //array to temporarily store each of the digits of sum
	    	
	    	 while(sum > 0){   //insert each digits of sum into the vector "temp"
	    	 	
	    	 	int rem = sum%10;
	    	 	temp.push_back(rem);
	    	 	sum /= 10;
	    	 }
	    	 
	    	 for(int k = temp.size()-1; k >= 0; k--){  //from "temp" array push_back the digits into "ans" vector
	    	 	                                       //from right end of the array
	    	 	ans.push_back(temp[k]); 
	    	 }
	    	 
	    	 i++;
	    	 j++;
	    }
	    
	    while(i < m){           //if X array is still remaining, push_back each digits of the array element into ans
	    	
	    	int sum = X[i];
	    	vector<int> temp;
	    	
	    	 while(sum > 0){
	    	 	
	    	 	int rem = sum%10;
	    	 	temp.push_back(rem);
	    	 	sum /= 10;
	    	 }
	    	 
	    	 for(int k = temp.size()-1; k >= 0; k--){
	    	 	
	    	 	ans.push_back(temp[k]);
	    	 }
	    	 
	    	 i++;
	    }
	    
	    
	    while(j < n){   //if X array is still remaining, push_back each digits of the array element into ans
	    	
	    	int sum = Y[j];
	    	vector<int> temp;
	    	
	    	 while(sum > 0){
	    	 	
	    	 	int rem = sum%10;
	    	 	temp.push_back(rem);
	    	 	sum /= 10;
	    	 }
	    	 
	    	 for(int k = temp.size()-1; k >= 0; k--){
	    	 	
	    	 	ans.push_back(temp[k]);
	    	 }
	    	 
	    	 j++;
	    }
	    
	    return ans;          //return the final array, ans
	}
};