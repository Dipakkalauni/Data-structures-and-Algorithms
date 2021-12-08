/*

Given an integer array, find a pair with the maximum product in it.

Each input can have multiple solutions. The output should match with either one of them.

Input : [-10, -3, 5, 6, -2]
Output: (-10, -3) or (-3, -10) or (5, 6) or (6, 5)

Input : [-4, 3, 2, 7, -5]
Output: (3, 7) or (7, 3)

If no pair exists, the solution should return the pair (-1, -1).

Input : [1]
Output: (-1, -1)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	pair<int,int> findPair(vector<int> const &nums)
	{
		pair<int,int> ans;
		
        // variables to store largest and second largest element
		int largest = nums[0];
		int second_large = INT_MIN;
		
        // variables to store smallest and second largest element
		int smallest = nums[0];
		int second_small = INT_MAX;
		

        // loop through the vector to find the above declared elements
		for(int i=1; i < nums.size(); i++){
			
			if(nums[i] > largest){
				
				second_large = largest;
				largest = nums[i];
				
			}else if(nums[i] > second_large){
				
				second_large = nums[i];
				
			}
			
			
			if(nums[i] < smallest){
				
				second_small = smallest;
				smallest = nums[i];
				
			}else if(nums[i] < second_small){
				
				 second_small = nums[i];
			}
		}
		
        // if Product of smallest and second smallest is maximum, make a pair of both of them
        //else make pair of largest and second largest

		if((smallest *1LL * second_small) > (largest * 1LL * second_large)){
			ans.first = smallest;
			ans.second = second_small;
		}else{
			ans.first = largest;
			ans.second = second_large;
		}
		
        // return the pair
		return ans;
		
	}
};


int main(){

    Solution sol;

    int n;

    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    pair<int, int> ans = sol.findPair(v);

    cout << ans.first << " " << ans.second << endl;
}