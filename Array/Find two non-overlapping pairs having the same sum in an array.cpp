/*

Given an unsorted integer array, find all non-overlapping pairs in it having the same sum.

Input : [3, 7, 6, 2]
Output: {{(7, 2), (3, 6)}}
Explanation: The pairs (7, 2) and (3, 6) are non-overlapping (having different indices) and have the same sum.

Input : [3, 4, 7, 4]
Output: {}
Explanation: No non-overlapping pairs are present in the array. The pairs (3, 4) and (3, 4) are overlapping as the index of 3 is the same in both pairs.

• The input can contain multiple non-overlapping pairs with the same sum, the solution should return a set containing all the distinct pairs.

Input : [3, 4, 7, 6, 1]
Output: {{(6, 1), (3, 4)}, {(4, 6), (3, 7)}}

Input : [3, 7, 6, 2, 4, 5]
Output: {{(7, 2), (3, 6)}, {(6, 2), (3, 5)}, {(6, 4), (3, 7)}, {(6, 5), (7, 4)}, {(2, 5), (3, 4)}, {(4, 5), (3, 6)}, {(4, 5), (7, 2)}}

Note: The solution should return all pairs in the same order as they appear in the array.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	set<set<pair<int,int>>> findPairs(vector<int> const &nums)
	{
		set<set<pair<int,int>>> result;
		
		int n = nums.size();
		
		if(n <= 1){
			return result;
		}

		unordered_map<int, vector<pair<int, int>>> map;
		
		for(int i=0; i<n-1; i++){
		   
		   for(int j= i+1; j<n; j++){
		   	
		   	 int sum = nums[i] + nums[j];
              
              if(map.find(sum) != map.end()){
              	
              	for(auto ele: map.find(sum)->second){
              		
              		int m = ele.first;
              		int p = ele.second;
              		
              		if((m != i && m != j) && (p != i && p != j)){
              			
              			set<pair<int, int>> s;
              			
              			s.insert({m, p});
              			s.insert({i, j});
              			result.insert(s);

              		}
              	}
              	
              }	   	
              
              map[sum].push_back({i, j});
		   	
		   }
		}
          
        
		return result;
	}
};
