#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*[Time Limit Exceeded]*/
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return true;
        return backtraking(nums, 0);
    }

private:
    bool backtraking(vector<int>& nums, int current_pos){
        //只要到达或超过最后一个位置就返回
        if(current_pos >= nums.size()-1)
            return true;
        
        //循环当前位置下所有可能前进的步数
        for(int i = 1; i <= nums[current_pos]; ++i){
            // cout << current_pos + i << endl;
            //注意这里的写法，不能直接 return backtraking(nums, current_pos + i)。
            //因为backtracking返回为false时，for循环可能还没结束
            if(backtraking(nums, current_pos + i))
                return true;
        }
        
        return false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return true;

        int max_next_position = 0;
        int i = 0;
        for(; i < nums.size() && i <= max_next_position; ++i){
            max_next_position = max(max_next_position, i+nums[i]);
        }
        return i == nums.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> testcase{3,2,1,0};
    cout << sln.canJump(testcase) << endl;
    return 0;
}
