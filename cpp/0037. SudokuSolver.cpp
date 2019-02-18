#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
    }

private:
    bool solve(vector<vector<char>>& board){
        int r = board.size();
        int c= board[0].size();

        //每次都从board[0][0]开始，因为下一个空cell的位置不定
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == '.'){
                    //每个空cell可能取值1~9
                    for(char digit = '1'; digit <= '9'; digit++){
                        //判断digit放在这个空的cell里是否满足数独的规则
                        if(checkValid(board, i, j, digit)){
                            board[i][j] = digit;
                            //递归进入下一个空cell
                            if(solve(board))
                                return true;
                        }
                    }
                    //如果该空cell里九个值都不满足数独的规则，说明上一个空cell取值有问题
                    //回溯返回，状态要还原
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        //没有空cell了。
        return true;
    }

    bool checkValid(vector<vector<char>>& board, int i, int j, char c)
    {
        for(int index = 0; index<9; index++){
            if(board[i][index] == c) return false;
            if(board[index][j] == c) return false;
            if(board[(i/3)*3 + index/3][(j/3)*3 + index%3] == c) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<char>> testcase{
        {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}}
    };
    sln.solveSudoku(testcase);
    for(auto vec: testcase){
        for(auto c: vec)
            cout<< c << ",";
        cout << endl;
    }
    return 0;
}
