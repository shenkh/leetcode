// 461HammingDistance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/*https://leetcode.com/problems/hamming-distance/
The Hamming distance between two integers is
the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ¡Ü x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
	   ¡ü   ¡ü

The above arrows point to positions where the corresponding bits are different.*/

//https://en.wikipedia.org/wiki/Hamming_distance
class Solution {
public:
	int hammingDistance(int x, int y) {
		int dist = 0;
		unsigned  val = x ^ y;

		// Count the number of bits set
		while (val != 0)
		{
			// A bit is set, so increment the count and clear the bit
			dist++;
			val &= val - 1;
		}

		// Return the number of differing bits
		return dist;
	}
};

int main()
{
	Solution sln;
	std::cout << sln.hammingDistance(1, 4) << std::endl;
	std::cout << "Hello World!\n";
}
