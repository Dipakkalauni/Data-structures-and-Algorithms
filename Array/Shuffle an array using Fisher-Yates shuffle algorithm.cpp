
/*

Given an array of distinct integer, in-place shuffle the array. The solution should produce an unbiased permutation, i.e., every permutation is equally likely.

Input: [1, 2, 3, 4, 5]
Output: [5, 4, 2, 1, 3] or [4, 1, 5, 3, 2] or any other unbiased permutation.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

     void swap(int *a, int *b){
     	 int temp = *a;
     	  *a = *b;
     	  *b = temp;
     }
     
	void shuffle(vector<int> &nums)
	{
		 
		int n = nums.size()-1;
		int j;
		
		for(int i = n-1; i >= 1; i--){
			
			 j = rand() % (i+1);
			
			swap(&nums[i], &nums[j]);
		}
	}
};

int main(){
   Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    srand(time(NULL));
   
   obj.suffle(nums);

    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }

    cout << endl;
}