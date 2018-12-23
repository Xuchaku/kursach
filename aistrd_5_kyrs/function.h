#pragma once
void FillMatrixDP(char *arr, int N, int **MatrixDP);
int FillArrayChar(char* &arr);
int FillArrayCharUnit(char* &arr);
void DrawMatrix(int **MatrixDP, int N);
void SearchMaxPal(int **MatrixDP, char *arr, int N);
void freeMatrix(int **MatrixDP, int N);