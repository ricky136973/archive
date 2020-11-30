// #define NDEBUG

#include "assignment.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <valarray>
#include <cassert>
#include <cstdlib>
#include <ctgmath>

class Matrix {
    public:
        typedef std::size_t size_type;
        typedef int scalar_type;
        typedef std::valarray<scalar_type> array_type;

    private:
        const size_type dim;
        const array_type val;
    
    public:
        Matrix(size_type dim, const array_type &val) noexcept :
            dim(dim), val(val) { assert(val.size() == dim * dim); }

        Matrix operator~() const noexcept {
            array_type _val(dim * dim);
            for (size_type i = 0; i < dim; ++i) {
                _val[std::slice(i * dim, dim, 1)] = val[std::slice(i, dim, dim)];
            }
            return Matrix(dim, _val);
        }

        Matrix operator+(const Matrix &rhs) const noexcept {
            assert(dim == rhs.dim);
            return Matrix(dim, val + rhs.val);
        }

        Matrix operator*(const Matrix &rhs) const noexcept {
            assert(dim == rhs.dim);
            std::vector<array_type> rows, cols;
            for (size_type k = 0; k < dim; ++k) {
                rows.push_back(val[std::slice(k * dim, dim, 1)]);
                cols.push_back(rhs.val[std::slice(k, dim, dim)]);
            }
            array_type _val(dim * dim);
            size_type count = 0;
            for (array_type row : rows) {
                for (array_type col : cols) {
                    _val[count++] = (row * col).sum();
                }
            }
            return Matrix(dim, _val);
        }

        template<class CharT, class Traits, class Allocator>
        operator std::basic_string<CharT, Traits, Allocator>() const {
            std::basic_ostringstream<CharT, Traits, Allocator> oss;
            size_type count = 0;
            for (size_type i = 0; i < dim; ++i) {
                for (size_type j = 0; j < dim; ++j) {
                    oss << val[count++] << ' ';
                }
                oss << '\n';
            }
            return oss.str();
        }
};

template<class T, class CharT, class Traits>
inline std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits> &os, const T &value) {
    return os << std::basic_string<CharT, Traits>(value);
}

void ex3() {
    using namespace std;

    typedef Matrix::size_type   size_type;
    typedef Matrix::scalar_type scalar_type;
    typedef Matrix::array_type  array_type;

    ifstream fin("matrices.txt");
    ofstream fout("result.txt");
    vector<scalar_type> vec;

    while (!fin.eof()) {
        scalar_type s;
        fin >> s;
        vec.push_back(s);
    }

    array_type val(vec.size());
    size_type count = 0;
    for (scalar_type s : vec) {
        val[count++] = s;
    }

    size_type size = vec.size() >> 1;
    size_type dim = size_type(sqrt(size));
    Matrix A(dim, val[slice(0, size, 1)]);
    Matrix B(dim, val[slice(size, size, 1)]);

    fout
        <<  A +  B << endl
        <<  A *  B << endl
        << ~A * ~B << endl;

    fin.close();
    fout.close();
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex3();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
