#include <bits/stdc++.h>

// this methord brute forces thorugh all possible solutions

using namespace std;

bool valid(vector<vector<int>> &v){
	for(int i = 0; i < 9; i++){
		int c = 0;
		for (int j = 0; j < 9; j++){
			c += v[i][j];
		}
		if (c != 45){
			return false;
		}
	}
	for(int i = 0; i < 9; i++){
		int c = 0;
		for (int j = 0; j < 9; j++){
			c += v[j][i];
		}
		if (c != 45){
			return false;
		}
	}
	if (v[0][0] + v[0][1] + v[0][2] + v[1][0] + v[1][1] + v[1][2] + v[2][0] + v[2][1] + v[2][2] != 45){
		return false;
	}
	if (v[0][4] + v[0][5] + v[0][3] + v[1][4] + v[1][5] + v[1][3] + v[2][4] + v[2][5] + v[2][3] != 45){
		return false;
	}
	if (v[0][6] + v[0][7] + v[0][8] + v[1][6] + v[1][7] + v[1][8] + v[2][6] + v[2][7] + v[2][8] != 45){
		return false;
	}
	if (v[3][0] + v[3][1] + v[3][2] + v[4][0] + v[4][1] + v[4][2] + v[5][0] + v[5][1] + v[5][2] != 45){
		return false;
	}
	if (v[3][3] + v[3][4] + v[3][5] + v[4][3] + v[4][4] + v[4][5] + v[5][3] + v[5][4] + v[5][5] != 45){
		return false;
	}
	if (v[3][6] + v[3][7] + v[3][8] + v[4][6] + v[4][7] + v[4][8] + v[5][6] + v[5][7] + v[5][8] != 45){
		return false;
	}
	if (v[6][0] + v[6][1] + v[6][2] + v[7][0] + v[7][1] + v[7][2] + v[8][0] + v[8][1] + v[8][2] != 45){
		return false;
	}
	if (v[6][3] + v[6][4] + v[6][5] + v[7][3] + v[7][4] + v[7][5] + v[8][3] + v[8][4] + v[8][5] != 45){
		return false;
	}
	if (v[6][6] + v[6][7] + v[6][8] + v[7][6] + v[7][7] + v[7][8] + v[8][6] + v[8][7] + v[8][8] != 45){
		return false;
	}
	return true;
}

int main()
{
	vector<vector<int>> sudoku(9,vector<int>(9));
	for(int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> sudoku[i][j];
		}
	}
	vector<int> count(10,0);
	for(int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			count[sudoku[i][j]]++;
		}
	}
	vector<int> rem;
	for (int i = 1; i < 10; i++){
		for (int j = 0; j < (9 - count[i]); j++){
			rem.push_back(i);
		}
	}
	rem.shrink_to_fit();
	sort(rem.begin(),rem.end());
	vector<vector<int>> test;
	test = sudoku;
	while(true){
		if (!next_permutation(rem.begin(),rem.end())){
			cout << "NO Possible Solution \n";
			break;
		}
		int k = 0;
		for(int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (test[i][j] == 0){
					test
					[i][j] = rem[k];
					k++;
				}
			}
		}
		if (valid(test)){
			cout << "Solution Found \n";
			for(int i = 0; i < 9; i++){
				for (int j = 0; j < 9; j++){
					cout << test[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		test = sudoku;
	}
}