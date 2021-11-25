#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "MatrixClass/MatrixClass.cpp"

using namespace std;

float Probability(vector<int> a, vector<int> b, float p) {
    float result = 1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i]) {
            result *= p;
        } else {
            result *= (1 - p);
        }
    }
    return result;
}

int FindMax(vector<float> p) {
    float result = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] > result) {
            result = p[i];
        }
    }
    int count = 0;
    int position = -1;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == result) {
            count++;
            position = i;
        }
    }
    if (count == 1 && position != -1) {
        return position;
    } else {
        return -1;   
    }
}

int main() {
    int N;
    int M;
    vector<vector<int> > vectors;

    fstream fin("FilesData/vectors.txt");
    fin >> N;
    fin >> M;
    vectors.resize(N);
    for (int i = 0; i < N; i++) {
        vectors[i].resize(M);
        for (int j = 0; j < M; j++) {
            fin >> vectors[i][j];
        }
    }
    fin.close();

    //initial y
    vector<vector<int> > y;
    y.resize(pow(2, M));
    for (int i = 0; i < pow(2, M); i++) {
        y[i] = vector<int> (M, 0);
    }


    for (int i = 0; i < pow(2, M); i++) {
        int ptr = i;
        int j = M - 1;
        while (ptr > 0) {
            y[i][j] = ptr % 2;
            ptr /= 2;
            j--;
        }
    }

    //Probability table
    float p = 0.49;
    vector<vector<float> > probabilityTable (y.size(), vector<float> (N, 0));
    for (int i = 0; i < y.size(); i++)
    {
        for (int j = 0; j < vectors.size(); j++)
        {
            probabilityTable[i][j] = Probability(y[i], vectors[j], p);
        }
    }

    vector<int > areaNumber (y.size(), -2);
    for (int i = 0; i < y.size(); i++)
    {
        areaNumber[i] = FindMax(probabilityTable[i]);
        // cout << areaNumber[i] << endl;
    }

    vector<vector<int> > areas;
    areas.resize(N);
    for (int i = 0; i < areaNumber.size(); i++)
    {
        if (areaNumber[i] != -1) {
            areas[areaNumber[i]].push_back(i);
        }
    }

    for (int i = 0; i < areas.size(); i++)
    {
        for (int j = 0; j < areas[i].size(); j++)
        {
            cout << areas[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    

    //print
    // for (int i = 0; i < probabilityTable.size(); i++) {
    //     for (int j = 0; j < probabilityTable[i].size(); j++) {
    //         cout << probabilityTable[i][j];
    //     }
    //     cout << endl;
    // }
    
    return 0;
}