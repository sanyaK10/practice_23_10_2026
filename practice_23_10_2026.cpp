#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 10;

void printArray(int a[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << "\t";
        cout << '\n';
    }
}

void fillRandom(int a[][MAX], int rows, int cols, int maxValue)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = rand() % (maxValue + 1);
}

// Завдання 3
void addRowAt(int a[][MAX], int& rows, int cols, int pos, int newRow[])
{
    if (rows >= MAX || pos < 0 || pos > rows)
    {
        cout << "Cannot add row!" << '\n';
        return;
    }

    for (int i = rows; i > pos; i--)
        for (int j = 0; j < cols; j++)
            a[i][j] = a[i - 1][j];

    for (int j = 0; j < cols; j++)
        a[pos][j] = newRow[j];

    rows++;
}

// Завдання 1
void addRowToEnd(int a[][MAX], int& rows, int cols, int newRow[])
{
    addRowAt(a, rows, cols, rows, newRow);
}

// Завдання 2
void addRowToStart(int a[][MAX], int& rows, int cols, int newRow[])
{
    addRowAt(a, rows, cols, 0, newRow);
}

// Завдання 4
void removeZeroRows(int a[][MAX], int& rows, int cols)
{
    int newRows = 0;

    for (int i = 0; i < rows; i++)
    {
        bool hasZero = false;
        for (int j = 0; j < cols; j++)
            if (a[i][j] == 0)
                hasZero = true;

        if (!hasZero)
        {
            for (int j = 0; j < cols; j++)
                a[newRows][j] = a[i][j];
            newRows++;
        }
    }
    rows = newRows;
}

// Завдання 6
void multiply(int A[][MAX], int B[][MAX], int C[][MAX], int M, int N, int K)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Завдання 7
bool convertTo2D(int arr[], int size, int rows, int result[][MAX], int& cols)
{
    if (rows <= 0 || size % rows != 0)
        return false;

    cols = size / rows;
    if (rows > MAX || cols > MAX)
        return false;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = arr[i * cols + j];

    return true;
}

int main()
{
    srand(time(0));

    // Завдання 1, 2, 3
    cout << "=== Tasks 1-3 ===" << '\n';
    int a[MAX][MAX];
    int rows = 3, cols = 4;
    fillRandom(a, rows, cols, 9);
    cout << "Original:" << '\n';
    printArray(a, rows, cols);

    int rowEnd[] = { 1, 1, 1, 1 };
    addRowToEnd(a, rows, cols, rowEnd);
    cout << "\nAdded to end:" << '\n';
    printArray(a, rows, cols);

    int rowStart[] = { 2, 2, 2, 2 };
    addRowToStart(a, rows, cols, rowStart);
    cout << "\nAdded to start:" << '\n';
    printArray(a, rows, cols);

    int rowMid[] = { 3, 3, 3, 3 };
    addRowAt(a, rows, cols, 2, rowMid);
    cout << "\nAdded at position 2:" << '\n';
    printArray(a, rows, cols);

    // Завдання 4
    cout << "\n=== Task 4 ===" << '\n';
    int b[MAX][MAX];
    int rows4 = 6, cols4 = 4;
    fillRandom(b, rows4, cols4, 5);
    cout << "Before:" << '\n';
    printArray(b, rows4, cols4);
    removeZeroRows(b, rows4, cols4);
    cout << "\nAfter:" << '\n';
    printArray(b, rows4, cols4);

    // Завдання 5
    cout << "\n=== Task 5 ===" << '\n';
    int r5, c5;
    cout << "Enter rows and columns (max " << MAX << "): ";
    cin >> r5 >> c5;
    if (r5 > 0 && r5 <= MAX && c5 > 0 && c5 <= MAX)
    {
        int x[MAX][MAX], y[MAX][MAX], z[MAX][MAX];
        fillRandom(x, r5, c5, 9);
        fillRandom(y, r5, c5, 9);

        for (int i = 0; i < r5; i++)
            for (int j = 0; j < c5; j++)
                z[i][j] = x[i][j] + y[i][j];

        cout << "A:" << '\n';     printArray(x, r5, c5);
        cout << "B:" << '\n';     printArray(y, r5, c5);
        cout << "A + B:" << '\n'; printArray(z, r5, c5);
    }
    else
        cout << "Wrong size!" << '\n';

    // Завдання 6
    cout << "\n=== Task 6 ===" << '\n';
    int M = 2, N = 3, K = 2;
    int A[MAX][MAX] = { {1, 2, 3}, {4, 5, 6} };
    int B[MAX][MAX] = { {7, 8}, {9, 10}, {11, 12} };
    int C[MAX][MAX];
    multiply(A, B, C, M, N, K);
    cout << "Matrix C:" << '\n';
    printArray(C, M, K);

    // Завдання 7
    cout << "\n=== Task 7 ===" << '\n';
    const int size7 = 12;
    int line[size7];
    for (int i = 0; i < size7; i++)
        line[i] = i + 1;

    cout << "Possible numbers of rows: ";
    for (int r = 1; r <= size7; r++)
        if (size7 % r == 0)
            cout << r << " ";
    cout << '\n';

    int rows7, cols7;
    int d[MAX][MAX];
    cout << "Enter number of rows: ";
    cin >> rows7;
    if (convertTo2D(line, size7, rows7, d, cols7))
        printArray(d, rows7, cols7);
    else
        cout << "Cannot split array like this!" << '\n';

    // Завдання 8
    cout << "\n=== Task 8 ===" << '\n';
    char surnames[5][100];
    cin.ignore();
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter surname " << i + 1 << ": ";
        cin.getline(surnames[i], 100);
    }

    int maxIndex = 0;
    for (int i = 1; i < 5; i++)
        if (strlen(surnames[i]) > strlen(surnames[maxIndex]))
            maxIndex = i;

    cout << "Longest: " << surnames[maxIndex] << '\n';

    return 0;
}