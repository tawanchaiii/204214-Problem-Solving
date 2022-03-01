// C++ program for weighted job scheduling using Dynamic
// Programming and Binary Search
#include <bits/stdc++.h>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
	int start, finish, profit;
};

// to store subset of jobs
struct weightedJob
{
	// vector of Jobs
	vector<Job> job;

	// find profit associated with included Jobs
	int value;
};

// A utility function that is used for sorting events
// according to finish time
bool jobComparator(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job. "index" is index of the current job. This function
// returns -1 if all jobs before index conflict with it. The
// array jobs[] is sorted in increasing order of finish time
int latestNonConflict(Job jobs[], int index)
{
	// Initialize 'lo' and 'hi' for Binary Search
	int lo = 0, hi = index - 1;

	// Perform binary Search iteratively
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (jobs[mid].finish <= jobs[index].start)
		{
			if (jobs[mid + 1].finish <= jobs[index].start)
				lo = mid + 1;
			else
				return mid;
		}
		else
			hi = mid - 1;
	}

	return -1;
}

// The main function that finds the subset of jobs
// associated with maximum profit such that no two
// jobs in the subset overlap.
int findMaxProfit(Job arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr + n, jobComparator);

	// Create an array to store solutions of subproblems.
	// DP[i] stores the Jobs involved and their total profit
	// till arr[i] (including arr[i])
	weightedJob DP[n];

	// initialize DP[0] to arr[0]
	DP[0].value = arr[0].profit;
	DP[0].job.push_back(arr[0]);

	// Fill entries in DP[] using recursive property
	for (int i = 1; i < n; i++)
	{
		// Find profit including the current job
		int inclProf = arr[i].profit;
		int l = latestNonConflict(arr, i);
		if (l != - 1)
			inclProf += DP[l].value;

		// Store maximum of including and excluding
		if (inclProf > DP[i - 1].value)
		{
			DP[i].value = inclProf;

			// including previous jobs and current job
			DP[i].job = DP[l].job;
			DP[i].job.push_back(arr[i]);

		}
		else
			// excluding the current job
			DP[i] = DP[i - 1];
	}

	// DP[n - 1] stores the result
	cout << "Optimal Jobs for maximum profits are\n" ;
	for (int i=0; i<DP[n-1].job.size(); i++)
	{
		Job j = DP[n-1].job[i];
		cout << "(" << j.start << ", " << j.finish
			<< ", " << j.profit << ")" << endl;
	}
	cout << "\nTotal Optimal profit is " << DP[n - 1].value;
}

// Driver program
int main()
{
	Job arr[] = {{1,3,2}, {2,4,3}, {3,5,2}};
	int n = sizeof(arr)/sizeof(arr[0]);

	findMaxProfit(arr, n);

	return 0;
}
