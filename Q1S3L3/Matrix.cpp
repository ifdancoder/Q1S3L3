#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<double>>& matx) {
    mtx.resize(matx.size());
    for (int i = 0; i < mtx.size(); i++) {
        mtx[i].resize(matx.size());
        for (int j = 0; j < mtx.size(); j++) {
            mtx[i][j] = matx[i][j];
        }
    }
}

double Matrix::findDet() {
    int ed = 1;
    double sum = 0;
    for (int i = 0; i < mtx.size(); i++, ed *= -1) {
        std::vector<std::vector<double>> tmp1;
        if (mtx.size() != 1) {
            for (int j = 1; j < mtx.size(); j++) {
                std::vector<double> tmp2;
                for (int k = 0; k < mtx.size(); k++) {
                    if (i != k) {
                        tmp2.push_back(mtx[j][k]);
                    }
                }
                tmp1.push_back(tmp2);
            }
        }
        else {
            return mtx[0][0];
        }
        sum += ed * mtx[0][i] * Matrix(tmp1).findDet();
    }
    return sum;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matx) {
    for (auto i : matx.mtx) {
        for (auto j : i) {
            os << j << '\t';
        }
        os << std::endl;
    }
    return os;
}