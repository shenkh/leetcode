// 56MergeIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/merge-intervals/
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmpfunc);

		if (intervals.size() <= 1)
			return intervals;

		vector<Interval> ans;
		for (size_t i = 0; i < intervals.size(); i++)
		{
			while (i + 1 < intervals.size() && intervals[i].end >= intervals[i + 1].start)
			{
				intervals[i + 1].start = intervals[i].start;
				intervals[i + 1].end = max(intervals[i].end, intervals[i + 1].end);
				i++;
			}
			ans.push_back(intervals[i]);
		}
		return ans;
	}
private:
	static bool cmpfunc(const Interval &x, const Interval & y) {
		return (x.start < y.start);
	}
};

int main()
{
	Solution sln;
	//vector<Interval> test_case{ {1,3},{2,6},{8,10},{15,18} };
	vector<Interval> test_case{ {1,4},{2,3} };
	vector<Interval> ans = sln.merge(test_case);
	for (const auto & i : ans)
		cout << i.start << "," << i.end << endl;
	std::cout << "Hello World!\n";
}
