#include <iostream>
#include <string>
using namespace std;

/**
 * Find an intersection of 2 lines.
 *
 * 4 points are given:
 *   first 2 - first line
 *   second 2 - second line
 */

int euclid(int a, int b) {
    if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a;
    }
    return euclid(b, a % b);
}

class Fraction {
public:
    Fraction(int n, int d): m_numer{n}, m_denom{d} {
        if (m_denom == 0) { throw 1; }
        if (m_denom < 0) {
            m_numer *= -1;
            m_denom *= -1;
        }
        int gcd = euclid(m_numer, m_denom);
        m_numer /= gcd;
        m_denom /= gcd;
    };
    string to_string() {
        string result{std::to_string(m_numer)};
        if (m_denom != 1) {
            result.append("/");
            result.append(std::to_string(m_denom));
        }
        return result;
    }
private:
    int m_numer;
    int m_denom;
};

string IntersectingLines(string strArr[], int arrLength) {
    // code goes here
    if (arrLength < 4) {
        return "no intersection";
    }
    int x[4] = {};
    int y[4] = {};
    for (int i = 0; i < 4; ++i) {
        x[i] = std::stoi(strArr[i].c_str()+1);
        y[i] = std::stoi(strArr[i].c_str()+1+strArr[i].find_first_of(','));
        //std:: cout << '{' << x[i] << ',' << y[i] << "}\n";
    }

    int denom = (x[0] - x[1]) * (y[2] - y[3]) - (y[0] - y[1]) * (x[2] - x[3]);
    if (denom == 0) {
        return "no intersection";
    }

    std::string result{"("};
    Fraction px{(x[0]*y[1] - y[0]*x[1])*(x[2] - x[3]) - (x[0] - x[1])*(x[2]*y[3] - y[2]*x[3]), denom};
    Fraction py{(x[0]*y[1] - y[0]*x[1])*(y[2] - y[3]) - (y[0] - y[1])*(x[2]*y[3] - y[2]*x[3]), denom};
    result.append(px.to_string());
    result.append(",");
    result.append(py.to_string());
    result.append(")");
    return result;
}

int main() {
    // keep this function call here
    string A[] = {"(9,-2)","(-2,9)","(3,4)","(10,11)"};
    int arrLength = sizeof(A) / sizeof(*A);
    cout << IntersectingLines(A, arrLength);
    return 0;
}
