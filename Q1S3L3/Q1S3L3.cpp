#include <iostream>
#include <list>
#include "Matrix.h"
#include "IntArr.h"

using namespace std;

void addAverage(list<double>& lst) {
    double sum = 0;
    for (auto i : lst) {
        sum += i;
    }
    lst.push_back(sum / lst.size());
}

int main()
{
    {
        // #1
        cout << "Ex 1:" << endl;
        list<double> lst = { 1.2, 4.7, 9.2 };
        cout << "Before adding: ";
        for (auto i : lst) {
            cout << i << ' ';
        }
        cout << endl;
        addAverage(lst);
        cout << "After adding: ";
        for (auto i : lst) {
            cout << i << ' ';
        }
        cout << endl << endl;
    }

    {
        // #2
        cout << "Ex 2:" << endl;
        vector<double> a = { 1.9, 2.8, 3.7 };
        vector<double> b = { 4.6, 5.5, 6.4 };
        vector<double> c = { 7.3, 8.2, 10.1 };
        vector<vector<double>> mtx = { a, b, c };
        Matrix matx(mtx);
        cout << "Matrix is:" << endl << matx;
        cout << "Determinant is " << matx.findDet() << endl << endl;
    }

    {
        // #3
        cout << "Ex 3:" << endl;
        OwnContainer arr = { 1, 2, 3, 4, 5 };
        for (auto i : arr) {
            cout << i << ' ';
        }
        cout << endl << endl;
    }
    return 0;
}