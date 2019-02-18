#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int step_num = 0;
        int current_pos = 0;
        //当到达最后一个元素或者超过最后一个元素停止
        while(current_pos + 1 < nums.size()){
            ++step_num;
            int cur_end = current_pos + nums[current_pos];
            current_pos += 1;

            //注意如果当前位置能一次性跳到最后一个位置的话，不循环
            if(cur_end + 1 >= nums.size())
                break;

            for(int j=current_pos; j <= cur_end; ++j){
                if(j + nums[j] >= current_pos + nums[current_pos])
                    current_pos = j;
            }
            // cout << current_pos <<endl;
        }
        return step_num;
    }
};

//https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
class Solution1 {
public:
    int jump(vector<int>& nums) {
        if(nums.empty() || nums.size()<2) return 0;
        
        int n = nums.size();
        int cur_end = 0;
        int cur_farthest = 0;
        int step = 0;

        for(int i=0; i<n-1; ++i){
            cur_farthest = std::max(cur_farthest, i+nums[i]);
            if(i == cur_end){
                cur_end = cur_farthest;
                ++step;
            }
        }

        return step;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> testcase{2,0,1,1,0};
    // vector<int> testcase{2,3,1};
    cout << sln.jump(testcase) << endl;
    return 0;
}
