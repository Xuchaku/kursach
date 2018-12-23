// aistrd_5_kyrs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "function.h"
#include "iostream"
#include <fstream>
using namespace std;
int main()
{

	char *arr = nullptr;
	int N = FillArrayChar(arr);
	
	const int MaxStrLen = N+1;
	int **MatrixDP = new int* [MaxStrLen];
	for (int count = 0; count < MaxStrLen; count++)
		MatrixDP[count] = new int[MaxStrLen];
	

	FillMatrixDP(arr, N, MatrixDP);
	DrawMatrix(MatrixDP, N);
	SearchMaxPal(MatrixDP, arr, N);
	/*w = MatrixDP[0][N-1];
	kk = w;
	char *t = new char[w];
	//SetLength(t, w);
	i = 0; j = N-1; k = 0;
	while (w > 0) {
		while (i < j && MatrixDP[i + 1][j] == w)i++;
		t[k+1] = arr[i];
		t[kk - k] = arr[i];
		cout << endl;
		cout << k + 1 << " " << kk - k;
		cout << endl;
		k++;
		while (arr[i] != arr[j])j--;
		j--;
		w -= 2;
	}
	for (int i = 1; i < kk+1; i++) {
		cout<<t[i];
	}*/
	delete[]arr;
	freeMatrix(MatrixDP, MaxStrLen);
	system("pause");
    return 0;
}

