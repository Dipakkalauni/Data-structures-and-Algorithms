#include<bits/stdc++.h>
using namespace std;

       bool isConsecutive(vector<int> const &nums, int i, int j, int min_ele, int max_ele){
     	 
     	 if(j - i  != max_ele - min_ele){
     	 	
     	 	return false;
     	 	
     	 }
     	 
     	 unordered_set<int> s;
     	 
     	 for(int k = i; k <= j; k++){
     	 	
     	 	if(s.find(nums[k]) == s.end()){
     	 		  
     	 		 s.insert(nums[k]);
     	 		 
     	 	}else{
     	 		
     	 		return false;
     	 	}
     	 }
     	 
     	 return true;
     }
     

	vector<int> findLargestSubarray(vector<int> const &nums)
	{
	    int n = nums.size();
	    
	    vector<int> ans;
	    
	    int length = 1;
	    int low = 0;
	    int high = 0;
	    
	    for(int i=0; i < n-1; i++){
	    	
	    	 int max_ele = nums[i];
	    	 int min_ele = nums[i];
	    	 
	    	for(int  j = i+1; j<n; j++){
	    		
	    		max_ele = max(max_ele, nums[j]);
	    		min_ele = min(min_ele, nums[j]);
	    		
	    		if(isConsecutive(nums, i, j, min_ele, max_ele)){
	    			
	    			if(length < max_ele - min_ele + 1){
	    				
	    				length = max_ele - min_ele + 1;
	    				
	    				low = i;
	    				
	    				high = j;
	    			}
	    		}
	    	}
	    }
	    
	    for(int i = low; i <= high; i++){
	    	
	    	ans.push_back(nums[i]);
	    	
	    }
	    
	    return ans;
	}

int main(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
           cin >> nums[i];
    }

    vector<int> ans = findLargestSubarray(nums);

    for(int i=0; i<ans.size(); i++){

        cout << ans[i] << " ";

    }

    
}