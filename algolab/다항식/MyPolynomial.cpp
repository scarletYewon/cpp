#include "MyPolynomial.h"

const myPolynomial myPolynomial::ZERO(0);
const myPolynomial myPolynomial::ONE(1, (unsigned)0);
const myPolynomial myPolynomial::X(1, 1);

ostream& operator <<(ostream &outStream, const myPolynomial& poly) {
    bool compare = false;
    if (poly == myPolynomial::ZERO) {
        return outStream << 0;
    }
    outStream<< poly.polynomial[0];

    if (poly.polynomial[0].getCoeff() != 0) {
        compare = true;
    }

    for(int i = 1; i < poly.nterm; i++) {
        if (poly.polynomial[i].getCoeff() != 0) {
            compare = true;
        }
        if (poly.polynomial[i].getCoeff() > 0) {
            outStream<<'+';
        }
        outStream << poly.polynomial[i];
    }
    if (compare == false) {
        return outStream << '0';
    }
    return outStream;
}
myPolynomial::myPolynomial(int c, unsigned e):nterm(1) {
    polynomial[0].coeff = c, polynomial[0].exp = e;
}
myPolynomial::myPolynomial(int nTerms, int mono[]) : nterm(nTerms) {
    for (int i = 0; i < nterm; i++) {
        polynomial[i].coeff=mono[2 * i], polynomial[i].exp=mono[2 * i + 1];
    }
    sort(polynomial, polynomial + nterm);
    if (nTerms == 1 && polynomial[0].coeff == 0 && polynomial[0].exp == 0) {
        degree = 0;
    }
    else {
        degree = polynomial[0].exp;
    }
}
myPolynomial::myPolynomial(const myPolynomial &poly):nterm(poly.nterm), degree(poly.degree) {
    for (int i = 0; i < nterm; i++) {
        polynomial[i].coeff = poly.polynomial[i].coeff, polynomial[i].exp = poly.polynomial[i].exp;
    }
}
bool myPolynomial::operator == (const myPolynomial &poly) const {
    if (nterm != poly.nterm) {
        return false;
    }
    for (int i = 0; i < nterm; i++) {
        if (polynomial[i].coeff != poly.polynomial[i].coeff || polynomial[i].exp != poly.polynomial[i].exp) {
            return false;
        }
    }
    return true;
}
bool myPolynomial::operator != (const myPolynomial &poly) const {
    return !(*this == poly);
}
myPolynomial& myPolynomial::operator += (const myPolynomial &poly) {
    return *this = *this + poly;
}
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly) {
    return *this = *this - poly;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly) {
    return *this = *this * poly;
}   
myPolynomial& myPolynomial::operator *= (int k) {
    return *this = *this * myPolynomial(k, (unsigned) 0);
}
myPolynomial myPolynomial::operator -() const {
    myPolynomial answer(*this);
    for(int i=0; i<nterm; i++)
        answer.polynomial[i].coeff*=-1;
    return answer;
}
myPolynomial myPolynomial::operator *(int k) const {
    return *this * myPolynomial(k, (unsigned) 0);
}
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const {
    int arr[102]={ 0 };
    int a = 0, b = 0, size = 0;
    for(size; a != nterm && b != poly.nterm; size++) {
        if (polynomial[a].exp > poly.polynomial[b].exp) {
            arr[2 * size] = polynomial[a].coeff, arr[2 * size + 1] = polynomial[a].exp, a++;
        }
        else if (polynomial[a].exp < poly.polynomial[b].exp) {
            arr[2 * size] = poly.polynomial[b].coeff, arr[2 * size + 1] = poly.polynomial[b].exp, b++;
        }
        else {
            arr[2 * size] = polynomial[a].coeff + poly.polynomial[b].coeff, arr[2 * size + 1] = polynomial[a].exp, a++, b++;
        }    
    }
    while(a != nterm) {
        arr[2 * size] = polynomial[a].coeff, arr[2 * size + 1] = polynomial[a].exp, a++, size++;
    }
    while(b != poly.nterm) {
        arr[2 * size] = poly.polynomial[b].coeff, arr[2 * size + 1] = poly.polynomial[b].exp, b++, size++;
    }
    return myPolynomial(size, arr);
}
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const {
    return *this + (-poly);
}
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const {
    myPolynomial answer(0, (unsigned) 0);
    for(int i = 0; i < nterm; i++) {
        myPolynomial temp(poly);
        for(int j = 0; j < poly.nterm; j++) {
            temp.polynomial[j].coeff *= polynomial[i].coeff;
            temp.polynomial[j].exp += polynomial[i].exp;
        }
        answer += temp;
    }
    return answer;
}
long myPolynomial::operator() (int x) const {
    long answer=0;
    for (int i = 0; i < nterm; i++) {
        answer += polynomial[i].coeff * (long)pow(x, polynomial[i].exp);
    }
    return answer;
}
int myPolynomial::getDegree() const {
    return degree;
}
unsigned myPolynomial::getNumTerms() const {
    return nterm;
}
myPolynomial myPolynomial::ddx() const {
    myPolynomial answer(*this);
    for (int i = 0; i < nterm; i++) {
        answer.polynomial[i] = polynomial[i].ddx();
    }
    return answer;
} 
myPolynomial operator *(int k, const myPolynomial &poly) {
    return myPolynomial(k, (unsigned) 0) * poly;
}