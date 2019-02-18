#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> single;
        sort(nums.begin(), nums.end());

        DFS(nums, res, single, 0, target, 4);
        return res;
    }

private:
    void DFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& single, int start, int remain, int knum){
        //也可以通过single.size()==4来进行判断
        if(knum == 0){
            if(remain == 0) res.push_back(single);
            return;
        }
        
        for(int i=start; i < nums.size() && knum > 0; ){
            single.push_back(nums[i]);
            // cout << nums[i] << endl;
            DFS(nums, res, single, i+1, remain-nums[i], knum-1);
            single.pop_back();
            
            //跳过重复的元素
            int value = nums[i];
            while(++i < nums.size() && nums[i] == value)
                continue;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> testcase{-3, 1, 1, 1, 1, 1, 1};
    vector<vector<int>> res;
    res = sln.fourSum(testcase, 0);
    for(auto vec: res){
        for(auto i: vec){
            cout << i << ",";
        }
        cout << endl;
    }    
    return 0;
}