/*
 * Handle each layer
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotateMatrix(vector<vector<int>> &mat) {
		int n = mat.size();

		for (int l = 0; l < n / 2; ++l) {
			for (int i = 0; i < (n - 1) - 2 * l; ++i) {
				int tmp;
				tmp                                 = mat[l][l + i];
				mat[l][l + i]                       = mat[(n - 1) - (l + i)][l];
				mat[(n - 1) - (l + i)][l]           = mat[(n - 1) - l][(n - 1) - (l + i)];
				mat[(n - 1) - l][(n - 1) - (l + i)] = mat[l + i][(n - 1) - l];
				mat[l + i][(n - 1) - l]             = tmp;
			}
		}
	}

	void showMatrix(const vector<vector<int>> &mat) {
		for (int i = 0; i < mat.size(); ++i) {
			for (int j = 0; j < mat[i].size(); ++j) {
				printf("%02d ", mat[i][j]);
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
			{ 0,  1,  2,  3,  4},
			{ 5,  6,  7,  8,  9},
			{10, 11, 12, 13, 14},
			{15, 16, 17, 18, 19},
			{20, 21, 22, 23, 24}
		},
		{
			{ 0,  1,  2,  3},
			{ 4,  5,  6,  7},
			{ 8,  9, 10, 11},
			{12, 13, 14, 15}
		}
	});

	for (int i = 0; i < inputs.size(); ++i) {
		cout << "input: " << endl;
		solution.showMatrix(inputs[i]);

		solution.rotateMatrix(inputs[i]);

		cout << "output: " << endl;
		solution.showMatrix(inputs[i]);
	}

	return 0;
}
