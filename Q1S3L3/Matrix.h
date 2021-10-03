#pragma once

#include <vector>
#include <iostream>

class Matrix {
private:
    std::vector<std::vector<double>> mtx;
public:
    Matrix(std::vector<std::vector<double>>& matx);
    double findDet();
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matx);
};