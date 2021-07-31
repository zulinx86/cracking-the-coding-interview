/*
 * M: the number of rows
 * N: the number of columns
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

#include<iostream>
#include<vector>

using namespace std;

void zeroMatrix(vector<vector<int>> &mat) {
	bool hasZeroInFirstRow = false, hasZeroInFirstCol = false;
	for (int r = 0; r < mat.size(); ++r) {
		for (int c = 0; c < mat[r].size(); ++c) {
			if (mat[r][c] == 0) {
				if (r == 0)
					hasZeroInFirstRow = true;
				else
					mat[r][0] = 0;

				if (c == 0)
					hasZeroInFirstCol = true;
				else
					mat[0][c] = 0;
			}
		}
	}

	for (int r = 0; r < mat.size(); ++r) {
		if (mat[r][0] == 0) {
			for (int c = 0; c < mat[r].size(); ++c)
				mat[r][c] = 0;
		}
	}

	for (int c = 0; c < mat[0].size(); ++c) {
		if (mat[0][c] == 0) {
			for (int r = 0; r < mat.size(); ++r)
				mat[r][c] = 0;
		}
	}

	if (hasZeroInFirstCol) {
		for (int r = 0; r < mat.size(); ++r)
			mat[r][0] = 0;
	}

	if (hasZeroInFirstRow) {
		for (int c = 0; c < mat[0].size(); ++c)
			mat[0][c] = 0;
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

int main(void)
{
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

	for (auto &input : inputs) {
		cout << "input: " << endl;
		showMatrix(input);

		zeroMatrix(input);

		cout << "output: " << endl;
		showMatrix(input);
	}

	return 0;
}
