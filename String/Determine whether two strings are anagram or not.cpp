/*

Given two strings, determine whether they are anagrams.

Any word that exactly reproduces the letters in another order is an anagram. In other words, X and Y are anagrams if by rearranging the letters of X, we can get Y using all the original letters of X exactly once.

Input: X = "silent", Y = "listen"
Output: true

Input: X = "incest", Y = "insect"
Output: true

*/

class Solution
{
public:
	bool isAnagram(string X, string Y)
	{
		if(X.size() != Y.size()){   //if size of the strings are not equal
			                        // return false;
			return false;
		}
		
		unordered_map<char, int> map;  //used to store the character in string 
		                               // and their frequency
		for(int i = 0; i < X.size(); i++){
			
			map[X[i]]++;
		}
		
		for(int i = 0; i < Y.size(); i++){  
			
			if(map.find(Y[i]) == map.end()){  //if Y[i] is not found in map, return false
				
				return false;
			}
			
			map[Y[i]]--;         //decrease the frequency of Y[i] by 1
			
			if(map[Y[i]] == 0){  //if frequency of Y[i] is zero, erase Y[i] from map
				
				map.erase(Y[i]);
			}
		}
		
		if(map.size()){  //if size of map is not zero, return false;
			
			return false;
		}
		
		return true;
	}
};
