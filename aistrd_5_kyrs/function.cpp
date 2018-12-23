#include "stdafx.h"
#include "iostream"
#include "function.h"
#include <fstream>
using namespace std;
void FillMatrixDP(char *arr, int N, int **MatrixDP) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			MatrixDP[i][j] = 0;
	}
	int save_point, count, found;
		for (int j = 0; j < N; j++) {
			MatrixDP[j][j] = 1;
			for (int i = j; i >= 0; i--) {
			count = MatrixDP[i+1][j];
			save_point = j;
			while (arr[save_point] != arr[i])save_point--;
			found = save_point - i + 1;
			if(save_point >= i + 2)
				found = MatrixDP[i + 1][save_point - 1] + 2;
			if (count < found)
				count = found;
			MatrixDP[i][j] = count;
		}
	}



}

void SearchMaxPal(int **MatrixDP, char *arr, int N) {
	if (!N) {
		cout << "Length string = 0" << endl;
		system("pause");
		return;
		
	}
	int max_length, save_point, i, j, search_index;

	max_length = save_point = MatrixDP[0][N - 1];
	
	char *max_pal = new char[max_length];
	
	i = 0; j = N - 1; search_index = 0;
	while (max_length > 0) {
		while (i < j && MatrixDP[i + 1][j] == max_length)i++;
		max_pal[search_index + 1] = arr[i];
		max_pal[save_point - search_index] = arr[i];
		search_index++;
		while (arr[i] != arr[j])j--;
		j--;
		max_length -= 2;
	}
	cout << "Search max pal:";
	for (i = 1; i < save_point + 1; i++) {
		cout << max_pal[i];
	}
	cout << endl;
	
}

void DrawMatrix(int **MatrixDP, int N) {
	cout << "Array length pal:";
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << MatrixDP[i][j] << " ";
		}
	}
	cout << endl;
}
int FillArrayChar(char* &arr) {
	ifstream fin;
	fin.open("in.txt");
	if (!fin) {
		cout << "File not open";
		return 0;
	}
	char next_character;
	int N_arr = 0, i = 0;
	while (!fin.eof()) {
		N_arr++;
		fin >> next_character;
	}
	N_arr--;
	
	arr = new char[N_arr];
	fin.clear();
	fin.seekg(0);
	
	while (!fin.eof()) {
		fin >> arr[i];
		i++;
	}
	cout << "Original string: ";
	for (i = 0; i < N_arr; i++) {
		cout<<arr[i];
	}
	cout << endl;
	fin.close();
	return N_arr;
}
void freeMatrix(int **MatrixDP, int N) {
	for (int i = 0; i < N; ++i)
		delete[] MatrixDP[i];
	delete[] MatrixDP;
}
int FillArrayCharUnit(char* &arr) {
	ifstream fin;
	fin.open("unit.txt");
	if (!fin) {
		cout << "File not open";
		return 0;
	}
	char next_character;
	int N_arr = 0, i = 0;
	while (!fin.eof()) {
		N_arr++;
		fin >> next_character;
	}
	N_arr--;

	arr = new char[N_arr];
	fin.clear();
	fin.seekg(0);

	while (!fin.eof()) {
		fin >> arr[i];
		i++;
	}
	cout << "Original string: ";
	for (i = 0; i < N_arr; i++) {
		cout << arr[i];
	}
	cout << endl;
	fin.close();
	return N_arr;
}