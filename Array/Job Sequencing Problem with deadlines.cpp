/*

Given a list of tasks with deadlines and total profit earned on completing a task, find the maximum profit earned by executing the tasks within the specified deadlines. Assume that each task takes one unit of time to complete, and a task can't execute beyond its deadline.

Input: (Task Id, Deadline, Profit)

[(1, 9, 15), (2, 2, 2), (3, 5, 18), (4, 7, 1), (5, 4, 25), (6, 2, 20), (7, 5, 8), (8, 7, 10), (9, 4, 12), (10, 3, 5)]

Output: {1, 3, 4, 5, 6, 7, 8, 9}
Explanation: The maximum profit that can be achieved is 109 by leaving tasks 2 and 10 out.

Constraints:

• Only a single task can be executed at a time.
• The maximum number of tasks are 100.
• The maximum deadline that can be associated with a job is 1000.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

	
		// Defination of Job class
		class Job
		{
		public:
			int taskId, deadline, profit;

			bool operator==(const Job &p) const {
				return taskId == p.taskId && deadline == p.deadline && profit == p.profit;
			}
		};
	

	unordered_set<int> scheduleJobs(vector<Job> jobs)
	{
		int n = jobs.size();   // stores the size of the vector
		
		unordered_set<int> s;  
		
		if(n <= 0){
			return s;
		}
			
		int T = 0;             // stores the maximum deadline for any task
		
		for(const Job &job: jobs){ // loop through the vector to find maximum deadline and assign it to T
			if(job.deadline > T){
				T = job.deadline;
			}
		}
		
		sort(jobs.begin(), jobs.end(), [](Job &lhs, Job &rhs){ // sort the vector on the basis of decreading order                                                                  //  of profits
			   
			   return lhs.profit > rhs.profit;
		});
		
		vector<int> slot(T, -1);        //vector to store the used slot 
		       //used to store selected taskId
		
		 
		
		 
	for (const Job &job: jobs)
    {
        // search for the next free slot and map the task to that slot
        for (int j = job.deadline - 1; j >= 0; j--)
        {
            if (j < T && slot[j] == -1)
            {
                slot[j] = job.taskId;
                s.insert(job.taskId);
                break;
            }
        }
    }
		
		return s;
	}
};