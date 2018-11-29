// 79WordSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/word-search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.*/

//https://leetcode.com/problems/word-search/discuss/27658/Accepted-very-short-Java-solution.-No-additional-space.

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		board_r = board.size();
		board_c = board[0].size();
		for (int r = 0; r < board_r; r++)
		{
			for (int c = 0; c < board_c; c++)
				if (backtracking(board, word, r, c, 0))
					return true;
		}
		return false;
	}

private:
	int board_r, board_c;

	bool backtracking(vector<vector<char>>& board, string& word, int r, int c, int i) {
		if (i == word.size())
			return true;
		if (r < 0 || c < 0 || r >= board_r || c >= board_c)
			return false;
		if (board[r][c] != word[i])
			return false;

		char tmp = board[r][c];
		board[r][c] = '\0';

		bool existence = backtracking(board, word, r + 1, c, i + 1) ||
			backtracking(board, word, r - 1, c, i + 1) ||
			backtracking(board, word, r, c + 1, i + 1) ||
			backtracking(board, word, r, c - 1, i + 1);

		board[r][c] = tmp;
		return existence;
	}
};

int main()
{
	Solution sln;
	vector<vector<char>> board{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word("SEE");
	cout << sln.exist(board, word) << endl;
	std::cout << "Hello World!\n";
}
