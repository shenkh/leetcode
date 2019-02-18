#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> tmp;
        helper(candidates, res, tmp, 0, target);
        return res;
    }
private:
    void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& single, int start, int remain){
        //All numbers (including target) will be positive integers.
        if(remain < 0)
            return;

        if(remain == 0){
            res.push_back(single);
            return;
        }

        for(int i = start; i< candidates.size(); ){
            single.push_back(candidates[i]);
            helper(candidates, res, single, i+1, remain-candidates[i]);
            single.pop_back();
            /** skip duplicates */
            while(++i < candidates.size() && candidates[i] == candidates[i-1])
                continue;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> testcase{10,1,2,7,6,1,5};
    vector<vector<int>> res = sln.combinationSum2(testcase, 8);
    for(auto vec: res){
        for(auto i : vec)
            cout << i << ",";
        cout << endl;
    }
    return 0;
}
