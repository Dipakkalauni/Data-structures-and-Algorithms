/*

Given a string, find the index of the first non-repeating character in it by doing only a single traversal of the string.

Input : "ABCDBAGHC"
Output: 3

The solution should return -1 if the string has all characters repeating.

Input : "AAA"
Output: -1

*/

class Solution
{
public:
	int findFirstNonRepeating(string s)
	{
		int n = s.size();              //size of the string
		
		unordered_map<char, pair<int, int>> map;     //map to store {character, {count, index of first occurance)) 
		
		int index = INT_MAX;         //stores the index of non-repeating first occuring characters
		
		for(int i = 0; i < n; i++){  //traverse the string and stores the count of characters and their first
			                             //occuring index
			if(map.find(s[i]) == map.end()){
				
				map[s[i]].first = 1;
				map[s[i]].second = i;
			}else{
				
				map[s[i]].first += 1;
			}
		}
		
		for(auto itr : map){   //traverse the map and store the least index of non repeating character in 'index'
			
			if(itr.second.first == 1){
				
				index = min(index, itr.second.second);
			}
		}
		
	  return index == INT_MAX ? -1 : index;  //return index
	}
};