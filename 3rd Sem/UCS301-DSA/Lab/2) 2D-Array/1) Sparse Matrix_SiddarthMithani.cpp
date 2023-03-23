#include <iostream>
using namespace std;

int main()
{
    // Assume 4x5 sparse matrix
    int sparseMatrix1[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};

    // TO find the total number of non zero entries
    int size1 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix1[i][j] != 0)
                size1++;
        }
    }

    int compactMatrix1[3][size1];

    // Making of new matrix
    // 0 Index to store the row number
    // 1 Index to store the column number
    // 2 Index to store the value
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix1[i][j] != 0)
            {
                compactMatrix1[0][k] = i;
                compactMatrix1[1][k] = j;
                compactMatrix1[2][k] = sparseMatrix1[i][j];
                k++;
            }
        }
    }

    // Printing the compact Matirx
    cout << "Row\tColumn\tValue" << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << compactMatrix1[0][i] << "\t" << compactMatrix1[1][i] << "\t" << compactMatrix1[2][i] << endl;
    }

    int sparseMatrix2[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};

    int size2 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix2[i][j] != 0)
                size2++;
        }
    }

    int compactMatrix2[3][size2];

    // Making of new matrix
    // 0 Index to store the row number
    // 1 Index to store the column number
    // 2 Index to store the value
    k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix2[i][j] != 0)
            {
                compactMatrix2[0][k] = i;
                compactMatrix2[1][k] = j;
                compactMatrix2[2][k] = sparseMatrix2[i][j];
                k++;
            }
        }
    }

    // Printing the compact Matirx
    cout << "Row\tColumn\tValue" << endl;
    for (int i = 0; i < size2; i++)
    {
        cout << compactMatrix2[0][i] << "\t" << compactMatrix2[1][i] << "\t" << compactMatrix2[2][i] << endl;
    }

    // Addition
    int x = 0;
    int max = size1+size2;
    int result[3][max];
    int AddedSparseMatrix[4][5];

    for (int i = 0; i < max; i++)
    {
        
    }

    return 0;
}
