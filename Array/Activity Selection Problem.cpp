/*

Given a set of activities, along with the starting and finishing time of each activity, find the maximum number of activities performed by a single person assuming that a person can only work on a single activity at a time.

Input : [(1, 4), (3, 5), (0, 6), (5, 7), (3, 8), (5, 9), (6, 10), (8, 11), (8, 12), (2, 13), (12, 14)]
Output: {(1, 4), (5, 7), (8, 11), (12, 14)}

Input : [(3, 7), (1, 3), (2, 9), (2, 7), (1, 2), (7, 8)]
Output: {(1, 3), (3, 7), (7, 8)} or {(1, 2), (3, 7), (7, 8)} or {(1, 2), (2, 7), (7, 8)}

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

	set<pair<int,int>> selectActivity(vector<pair<int,int>> activities)
	{
		int n = activities.size();    //size of the vector of pair
		
		set<pair<int, int>> s;       //set to store the activities performed
		
		sort(activities.begin(), activities.end(), [](pair<int, int> const &lhs, pair<int, int> const &rhs){
			 return lhs.second < rhs.second;
		});                               //sort the activities on the basis of non-decreasing order of finish time
		
		if(n > 0){
			s.insert(activities[0]);    //if vector is non-empty, insert the first pair into the set
		}
		
		int k = 0;                //stores the index of last selected activity
		
		for(int i=1; i<n; i++){    //loop through the vector, and if the starting time of current activity 
			                       // is greater than or equal to finishing time of last selected activity
			                       // insert the current activity into the set and update the value of k.
			                       
			if(activities[i].first >= activities[k].second){
				s.insert(activities[i]);
				k = i;
			}
		}
		
		return s;            // return s
	}
};