#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> char_num;
        int res = 0;
        for(const auto &c : J){
            char_num[c] = 1;
        }
        
        //判断Stone中的每个元素是否在Jewels中
        for(const auto &c: S){
            auto iter = char_num.find(c);
            if(iter != char_num.end())
                res++;
        }
        return res;
    }
};

class Solution2 {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        //只有大小写字母,对应的ASCII码A:65,a:97.
        int char_num[128] = {0};
        for(const auto &c : S){
            char_num[c]++;
        }
        
        //对于Jewels中的每个元素,在Stone对应的char_num数组中查找
        for(const auto &c: J){
            res += char_num[c];
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    cout << sln.numJewelsInStones("aA", "aAAbbbb") << endl;
    return 0;
}
