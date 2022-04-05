/*

Given a list of words, efficiently group all anagrams. The two strings, X and Y, are anagrams if by rearranging X's letters, we can get Y using all the original letters of X exactly once.

Input : ["CARS", "REPAID", "DUES", "NOSE", "SIGNED", "LANE", "PAIRED", "ARCS", "GRAB", "USED", "ONES", "BRAG", "SUED", "LEAN", "SCAR", "DESIGN"]

Output:

{
	["CARS", "ARCS", "SCAR"],
	["REPAID", "PAIRED"],
	["SIGNED", "DESIGN"],
	["LANE", "LEAN"],
	["GRAB", "BRAG"],
	["NOSE", "ONES"],
	["DUES", "USED", "SUED"]
}


Input : ["CARS", "LANE", "ONES"]
Output: {}

The solution should return a set containing all the anagrams grouped together, irrespective of the order.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	set<set<string>> groupAnagrams(vector<string> const &words)
	{
		set<set<string>> anagrams;  //stores all the anagrams grouped together

		int n = words.size();  //stores the size of the words vector
		
		if(n == 0){     //if words is empty return false
			
			return anagrams;
		}
		
		vector<string> list(words);  //vector to store the word is sorted form
		
		for(string &s: list){
			
			sort(s.begin(), s.end());
		}
		
		unordered_map<string, vector<int>> map;  //map to store the word and its indexes where it is present
		
		for(int i=0; i < list.size(); i++){
			
			map[list[i]].push_back(i);
		}
		
		for(auto itr: map){ //traverse the map and read the indexes and store the word present at those indexes
			                  // in a given set 
			set<string> res;
			
			for(int index: itr.second){
				
				res.insert(words[index]);
			}
			
			if(res.size() > 1){
				anagrams.insert(res);
			}
		}

		return anagrams;
	}
};