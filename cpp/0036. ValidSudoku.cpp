#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        unordered_map<int, unordered_set<char> > rows;
        unordered_map<int, unordered_set<char> > cols;
        unordered_map<int, unordered_set<char> > grids;
        for(int i=0; i< r; i++){
            for(int j=0; j< c; j++){
                if(board[i][j] == '.')
                    continue;
                
                auto iter = rows[i].find(board[i][j]);
                if(iter != rows[i].end())
                    return false;
                else
                    rows[i].insert(board[i][j]);
                
                iter = cols[j].find(board[i][j]);
                if(iter != cols[j].end())
                    return false;
                else
                    cols[j].insert(board[i][j]);

                iter = grids[(i/3)*3+j/3].find(board[i][j]);
                if(iter != grids[(i/3)*3+j/3].end())
                    return false;
                else
                    grids[(i/3)*3+j/3].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<char>> testcase{  
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << sln.isValidSudoku(testcase) << endl;
    return 0;
}
