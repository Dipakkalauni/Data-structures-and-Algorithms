/*

The lexicographically minimal string rotation (or lexicographically least circular substring) is the problem of finding a string's rotation possessing the lowest lexicographical order among all possible rotations.

Input : "bbaaccaadd"
Output: "aaccaaddbb"

Note that a string can have multiple lexicographically minimal rotations, but this doesn't matter – rotations must be equivalent.

*/

class Solution
{
public:
	string findLexicalMinRotation(string s)
	{
		int n = s.size();  //stores the size of the string
		
		//stores the lexicographically minimum string
		string min = s;
		
		
		for(int i=0; i<n; i++){
			
			//left rotate the string by 1 unit
			rotate(s.begin(), s.begin()+1, s.end());
			
			//update the result if the rotation is minimum so far
			if(s.compare(min) < 0){
				
				min = s;
			}
		}
		
		return min;
	}
};