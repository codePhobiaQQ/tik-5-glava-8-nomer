#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "MatrixClass/MatrixClass.cpp"

using namespace std;

int main() {
    int N;
    int M;
    vector<vector<int> > A;
    vector<vector<int> > B;
    vector<vector<int> > C;
    vector<vector<int> > D;

    fstream fin("FilesData/matrixes.txt");
    int ptr;

    // Матрица A
    fin >> N;
    fin >> M;
    A.resize(N, vector<int > (M, 0));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            fin >> ptr;
            A[i][j] = ptr;
        }
    }

    // Матрица B
    fin >> N;
    fin >> M;
    B.resize(N, vector<int > (M, 0));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            fin >> ptr;
            B[i][j] = ptr;
        }
    }

    // Матрица С
    fin >> N;
    fin >> M;
    C.resize(N, vector<int > (M, 0));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            fin >> ptr;
            C[i][j] = ptr;
        }
    }

    // Матрица D
    fin >> N;
    fin >> M;
    D.resize(N, vector<int > (M, 0));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            fin >> ptr;
            D[i][j] = ptr;
        }
    }

    fin.close();

    MatrixClass MatrixA(A);
    MatrixClass MatrixB(B);
    MatrixClass MatrixC(C);
    MatrixClass MatrixD(D);

    MatrixClass MatrixK3(C);
    MatrixK3.K(C, A, 6).show();

    return 0;
}