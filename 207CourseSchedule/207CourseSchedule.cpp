// 207CourseSchedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*https://leetcode.com/problems/course-schedule
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
						To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
			 To take course 1 you should have finished course 0, and to take course 0 you should
			 also have finished course 1. So it is impossible.*/

#if 0
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<int> degree = indegree(numCourses, prerequisites);

		//如果图中不存在环，则i会循环numCourses次
		for (int i = 0; i < numCourses; i++)
		{
			int j;
			//找到入度为0的顶点
			for (j = 0; j < numCourses; j++) {
				if (degree[j] == 0)
					break;
			}

			//如果存在环,则内层的循环会比外层的循环更快结束
			if (j == numCourses)
				return false;

			//标记入度为0的点为-1，同时更新其他有关联的顶点的入度
			degree[j] = -1;
			for (auto const & s : graph[j])
				degree[s]--;
		}
		return true;
	}
private:

	//构建图邻接表
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto const &pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

	//计算每个顶点的入度
	vector<int> indegree(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> degree(numCourses, 0);
		for (auto const s : prerequisites)
			degree[s.first]++;
		return degree;
	}
};
#else

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		//0: 未访问的顶点
		//1: 已经访问完的顶点
		//-1:正在访问的顶点
		vector<int> visited(numCourses, 0);


		for (size_t i = 0; i < numCourses; i++)
		{
			if (DFS(graph, visited, i) == false)
				return false;
		}
		return true;
	}
private:

	//构建图邻接表
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto const &pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

	//返回表示当前是否能满足条件
	bool DFS(vector<unordered_set<int>> &graph, vector<int> & visited, int vert) {
		if (visited[vert] == -1)
			return false;

		visited[vert] = -1;
		//循环当前顶点下的所有关联的顶点
		for (auto const &s : graph[vert])
		{
			if (DFS(graph, visited, s) == false)
				return false;
		}
		visited[vert] = 1;

		return true;
	}
};
#endif // 0

int main()
{
	Solution sln;
	int numCourses = 2;
	vector<pair<int, int>> prerequisites{ make_pair(0,1),make_pair(1,0) };
	cout << sln.canFinish(numCourses, prerequisites) << endl;
	std::cout << "2018-12-16.Hello World!\n";
}
