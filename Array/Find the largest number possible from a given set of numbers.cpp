/*

Find the largest number possible from a set of given numbers, where the numbers append to each other in any order to form the largest number. The solution should return the string representation of the largest number.

Input : [10, 68, 75, 7, 21, 12]
Output: 77568211210

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    static bool compare(int const &a, int const &b){
    	
    	string first = to_string(a) + to_string(b);
    	string second = to_string(b) + to_string(a);
    	
    	return first > second;
    }
    
	string findLargestNumber(vector<int> &nums)
	{
		int n = nums.size();  //stores the size of the array
		
		string ans = "";    // stores the largest number possible
		
		//sort the array with the help of custom compare function
		sort(nums.begin(), nums.end(), Solution::compare);
		
		for(int i = 0; i < n; i++){
			
			ans += to_string(nums[i]);
		}
		
		return ans;
		
	}
};
