# [253 Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)

Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (si < ei), find the minimum number of conference rooms required.

Example 1:

```
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
```

Example 2:

```
Input: [[7,10],[2,4]]
Output: 1
```

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

-----

**题目**：最少需要多少个会议室使得所有会议时间没有冲突。

**思路**：这道题是之前那道[252 Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) 的拓展，那道题只让我们是否能参加所有的会，也就是看会议之间有没有时间冲突，而这道题让我们求最少需要安排几个会议室，有时间冲突的肯定需要安排在不同的会议室。这道题有好几种解法，我们先来看使用 TreeMap 来做的，我们遍历时间区间，对于起始时间，映射值自增1，对于结束时间，映射值自减1，然后我们定义结果变量 res，和房间数 rooms，我们遍历 TreeMap，时间从小到大，房间数每次加上映射值，然后更新结果 res，遇到起始时间，映射是正数，则房间数会增加，如果一个时间是一个会议的结束时间，也是另一个会议的开始时间，则映射值先减后加仍为0，并不用分配新的房间，而结束时间的映射值为负数更不会增加房间数，利用这种思路我们可以写出代码如下:

[**工程代码下载**](https://github.com/shenkh/leetcode)

```cpp
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a.start];
            --m[a.end];
        }
        int rooms = 0, res = 0;
        for (auto it : m) {
            res = max(res, rooms += it.second);
        }
        return res;
    }
};
```



第二种方法是用两个一维数组来做，分别保存起始时间和结束时间，然后各自排个序，我们定义结果变量res和结束时间指针 endpos，然后我们开始遍历，如果当前起始时间小于结束时间指针的时间，则结果自增1，反之结束时间指针自增1，这样我们可以找出重叠的时间段，从而安排新的会议室，参见代码如下：

```cpp
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        int res = 0, endpos = 0;
        for (auto a : intervals) {
            starts.push_back(a.start);
            ends.push_back(a.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < intervals.size(); ++i) {
            if (starts[i] < ends[endpos]) ++res;
            else ++endpos;
        }
        return res;
    }
};
```



**转自: <https://www.cnblogs.com/grandyang/p/5244720.html>**