#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> Result;
		//key: nums value; value: nums index
		map<int, int> nums_index;
		for (size_t i; i < nums.size(); i++)
		{
            if(~nums_index.count(nums[i]))
			    nums_index[nums[i]] = i;
		}

		for (size_t i = 0; i < nums.size(); i++)
		{
			map<int, int> :: iterator itr = nums_index.find(target - nums[i]);
			if (itr != nums_index.end() && itr->second != i)
			{ 
				Result.push_back(i);
				Result.push_back(itr->second);
				break;
			}
		}
		return Result;
	}
};

/* int main(int argc, char const *argv[])
{
    Solution sum;
    vector<int> input;
    
    for(size_t i = 0; i < 5; i++)
    {
        input.push_back(i);
    }
    
    vector<int> result = sum.twoSum(input, 9);
    
    for(size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    
    return 0;
}
 */
