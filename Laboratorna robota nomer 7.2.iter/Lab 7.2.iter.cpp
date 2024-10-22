// Lab 7.2.iter

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool SearchMinOfMaxInEvenRows(int** a, const int n, int& minMax);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;

    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    int minMax;
    if (SearchMinOfMaxInEvenRows(a, n, minMax))
        cout << "min of max in even rows = " << minMax << endl;
    else
        cout << "there are no even rows" << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool SearchMinOfMaxInEvenRows(int** a, const int n, int& minMax)
{
    int maxInEvenRow = -1;
    bool found = false;

    for (int i = 0; i < n; i += 2)
    {
        int currentMax = a[i][0];
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] > currentMax)
            {
                currentMax = a[i][j];
            }
        }

        if (!found || currentMax < minMax)
        {
            minMax = currentMax;
            found = true;
        }
    }

    return found;
}
