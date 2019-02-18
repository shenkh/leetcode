#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tasks_num[26] = {0};
        for(auto c : tasks){
            tasks_num[c-'A']++;
        }

        sort(begin(tasks_num), end(tasks_num));
        int time = 0;

        while(tasks_num[25] > 0){
            int interval = 0;
            //注意这里是等于n
            while(interval <= n){
                //处理最后一段idle开始,但并不是idle结束
                if(tasks_num[25] == 0)
                    break;

                if(interval < 26 && tasks_num[25-interval] > 0){
                    tasks_num[25-interval]--;
                }
                interval++;
                time++;
            }
            sort(begin(tasks_num), end(tasks_num));
        }
        return time;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<char> testcase{'A','A','A','B','B','B'};
    cout << sln.leastInterval(testcase, 2) << endl;
    return 0;
}
