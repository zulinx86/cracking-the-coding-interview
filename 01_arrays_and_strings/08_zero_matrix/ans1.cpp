/*
 * Store list of cols and rows
 * Time complexity: O(n^2)
 * Space complexity: O(n);
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void zeroMatrix(vector<vector<int>> &mat) {
		vector<int> zc, zr;
		for (int r = 0; r < mat.size(); ++r) {
			for (int c = 0; c < mat[r].size(); ++c) {
				if (mat[r][c] == 0) {
					zc.push_back(c);
					zr.push_back(r);
				}
			}
		}

		for (const auto &r : zr) {
			for (int c = 0; c < mat[r].size(); ++c) mat[r][c] = 0;
		}

		for (const auto &c : zc) {
			for (int r = 0; r < mat.size(); ++r) mat[r][c] = 0;
		}
	}

	void showMatrix(const vector<vector<int>> &mat) {
		for (const auto &v : mat) {
			for (const auto &e : v) {
				printf("%02d ", e);
			}
			printf("\n");
		}
		printf("\n");
	}
};

int main(void) {
	Solution solution;
	vector<vector<vector<int>>> inputs({
		{
			{11, 12,  0, 14},
			{21, 22, 23, 24},
			{31,  0, 33, 34},
			{41, 42, 43, 44}
		},
		{
			{ 0, 12, 13, 14},
			{21,  0, 23, 24},
			{31, 32,  0, 34},
			{41, 42, 43,  0},
		}
	});

	for (auto& input : inputs) {
		cout << "input: " << endl;
		solution.showMatrix(input);

		solution.zeroMatrix(input);

		cout << "output: " << endl;
		solution.showMatrix(input);
	}

	return 0;
}
