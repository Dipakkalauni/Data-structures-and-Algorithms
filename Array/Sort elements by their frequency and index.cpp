Given an integer array, sort its element by their frequency and index. If two elements have different frequencies, then the one which has more frequency should come first; otherwise, the one which has less index should come first, i.e., the solution should preserve the relative order of the equal frequency elements.

Input : [3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8]
Output: [3, 3, 3, 1, 1, 1, 8, 8, 8, 6, 7]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

     //custom Comparator function
     static bool compareInterval(tuple<int, int, int> const& lhs, tuple<int, int, int> const& rhs){
    	
    	//if two elements have different frequency then the one which has more frequency should come
    	// first
    	// else one with less index should come first
    	if(get<1>(lhs) != get<1>(rhs)){
    		
    		return get<1>(lhs) > get<1>(rhs);
    	}else{
    		
    		return get<2>(lhs) < get<2>(rhs); 
    	}
    }
    
	void sortByFrequencyAndIndex(vector<int> &nums)
	{
		int n = nums.size();
		
		if(n < 2){
			return;
		}

        // stores the element as its key, and pair of frequency 
        // and first index of occurance as value
		unordered_map<int, pair<int, int>> m;
		//insert the element, its frequency and index of its first occurance in the array
		for(int i=0; i<n; i++){
			
			if(m.find(nums[i]) != m.end()){
				
				 m[nums[i]].first++; 
			}else{
				m[nums[i]] = make_pair(1, i);
			}
		}
		
		//a vector of tuples to store the elements of map and sort them based on frequency
		vector<tuple<int, int, int>> v;
		
		for(auto it: m){
			
			pair<int, int> p = it.second;
			
			v.push_back(make_tuple(it.first, p.first, p.second));
		}
		
		//sort the vector of tuple
		sort(v.begin(), v.end(), Solution::compareInterval);
		
		int a, b, c, k = 0;
		for(auto ele: v){
			
		  tie(a, b, c) = ele;
		  
		  for(int i=0; i<b; i++){
		  	
		  	nums[k] = a;
		  	k++;
		  }
		}
		
	}
};
