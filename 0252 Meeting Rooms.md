# [252 Meeting Rooms](https://leetcode.com/problems/meeting-rooms/)

Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (si < ei), determine if a person could attend all meetings.

For example,
Given `[[0, 30],[5, 10],[15, 20]]`,
return `false`.

-----

**题目**：给定若干会议的时间，问能不能同时参加所有的会议。

**思路**：实际上就是求区间是否有交集的问题。先给所有区间排个序，用起始时间的先后来排，然后我们从第二个区间开始，如果开始时间早于前一个区间的结束时间，则说明会议时间有冲突，返回false，遍历完成后没有冲突，则返回true。

[**工程代码下载**](https://github.com/shenkh/leetcode)

```cpp
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};
```



**转自：<https://www.cnblogs.com/grandyang/p/5240774.html>**

