/*

Given a set of pairs of integers, find all symmetric pairs, i.e., pairs that mirror each other. For instance, pairs `(x, y)` and `(y, x)` are mirrors of each other.

Input : {(1, 2), (5, 2), (3, 4), (7, 10), (4, 3), (2, 5)}
Output: {{(2, 5), (5, 2)}, {(3, 4), (4, 3)}}
Explanation: The pairs (2, 5) and (5, 2) mirror each other. Similarly, pairs (3, 4) and (4, 3) are symmetric.

Input : {(1, 2), (5, 2), (3, 4)}
Output: {}
Explanation: No pairs mirror each other

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	set<set<pair<int,int>>> findSymmetricPairs(set<pair<int,int>> const &pairs)
	{
	    set<set<pair<int,int>>> result;     // used to store final result

	    set<pair<int, int>> ans;            
        
        
        for(auto ele: pairs){           // traverse through the set
         	                            
        	set<pair<int, int>> temp;  //set to store symmetric pair temporarily
        	
        	if(ele.first == ele.second){ // if the first and second elements of a pair is equal,
            	                         // insert the element into temp and insert the temp into result
               temp.insert({ele});
               result.insert(temp);
            	
            }else if(ans.find({ele.second, ele.first}) == ans.end()){
            	                          // if the symmetric pair of current pair is not found in ans
            	ans.insert(ele);           // insert the the pair in ans
            	
            }else{                          // else if symmetric pair of current pair is found 
  	
            	temp.insert({ele});          // insert both current pair and symmetric pair in temp
            	temp.insert({ele.second, ele.first});  // ans insert temp in result
            	
            	result.insert(temp);
            }
         }
         
		return result;                   // return result
	}
};