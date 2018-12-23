#include "stdafx.h"
#include "CppUnitTest.h"
#include "../aistrd_5_kyrs/function.h"
#include "iostream"
#include <fstream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(MatrixDP1_x_1)
		{	char *arr;
			int N = 1;
			const int MaxStrLen = N+1;
			
			arr = new char[N];
			int **MatrixDP = new int*[MaxStrLen];
			for (int count = 0; count < MaxStrLen; count++)
				MatrixDP[count] = new int[MaxStrLen];
			FillMatrixDP(arr, N, MatrixDP);
			Assert::AreEqual(MatrixDP[0][0], 1);
			delete[]arr;
			freeMatrix(MatrixDP, MaxStrLen);
			
		}
		TEST_METHOD(MatrixDPN_x_N)
		{
			char *arr = nullptr;
			int N = FillArrayChar(arr);

			const int MaxStrLen = N + 1;
			int **MatrixDP = new int*[MaxStrLen];
			for (int count = 0; count < MaxStrLen; count++)
				MatrixDP[count] = new int[MaxStrLen];
			
			FillMatrixDP(arr, N, MatrixDP);
			
		
			Assert::AreEqual(MatrixDP[0][N-1], 7);
			delete[]arr;
			freeMatrix(MatrixDP, MaxStrLen);

		}

		TEST_METHOD(FillArrayZeroElements)
		{
			char *arr = nullptr;
			int N = FillArrayCharUnit(arr);

			const int MaxStrLen = N + 1;
			int **MatrixDP = new int*[MaxStrLen];
			for (int count = 0; count < MaxStrLen; count++)
				MatrixDP[count] = new int[MaxStrLen];

			FillMatrixDP(arr, N, MatrixDP);


			Assert::AreEqual(N, 0);
			delete[]arr;
			freeMatrix(MatrixDP, MaxStrLen);

		}
		TEST_METHOD(FillArrayNElement)
		{
			char *arr = nullptr;
			int N = FillArrayCharUnit(arr);

			const int MaxStrLen = N + 1;
			int **MatrixDP = new int*[MaxStrLen];
			for (int count = 0; count < MaxStrLen; count++)
				MatrixDP[count] = new int[MaxStrLen];

			FillMatrixDP(arr, N, MatrixDP);


			Assert::AreEqual(N, 11);
			delete[]arr;
			freeMatrix(MatrixDP, MaxStrLen);
		}
		TEST_METHOD(SearchMaxPalZeroN)
		{
			char *arr = nullptr;
			int N = FillArrayCharUnit(arr);

			const int MaxStrLen = N + 1;
			int **MatrixDP = new int*[MaxStrLen];
			for (int count = 0; count < MaxStrLen; count++)
				MatrixDP[count] = new int[MaxStrLen];

			FillMatrixDP(arr, N, MatrixDP);
			SearchMaxPal(MatrixDP, arr, N);

			Assert::AreEqual(N, 0);
			delete[]arr;
			freeMatrix(MatrixDP, MaxStrLen);
		}

	};
}