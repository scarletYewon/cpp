#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Kvector{
    int *m;
    int len;
public:
    Kvector(int sz = 0, int value = 0);
    Kvector(Kvector& v);
    Kvector& operator=(Kvector& v);
    friend bool operator==(const Kvector& v, const Kvector& z);
    friend bool operator!=(const Kvector& v, const Kvector& z);
    friend ostream& operator<<(ostream& os, Kvector &v);
    int& operator[](int idx) { return m[idx]; }
    const int& operator[](int idx) const { return m[idx]; }

    ~Kvector(){
        cout << this << " : ~Kvector()" << endl;
        delete[] m;
    }
    void print() const{
        for(int i=0; i<len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear(){
        delete[] m;
        m = NULL;
        len = 0;}
    int size(){ return len; }
};

Kvector::Kvector(int sz, int value): len(sz) {
    cout << this << " : Kvector( " << sz << ", " << value << ")\n";
    if (sz>0) { m = new int[sz]; }
    else { m = nullptr; }
    for(int i=0; i<sz; i++) m[i] = value;
}

Kvector::Kvector(Kvector& v) {
    cout << this << " : Kvector(*" << &v << ")" << endl;
    len=v.len;
    if (len < 0) {
        m=nullptr;
    }
    else {
        m=new int[len];
    }
    for (int i = 0; i < len; i++){
        m[i] = v.m[i];
    }
}

Kvector& Kvector::operator= (Kvector& v) {
    if(this != &v){
        delete[] m;
        len=v.len;
        m=new int[len];
        for(int i=0;i<len;i++) {
            m[i]=v.m[i];
        }
    }
    return *this;
}

bool operator==(const Kvector& v, const Kvector& z) {
    if (v.len==z.len) {
        for (int i=0;i<v.len;i++) 
            if(v.m[i]!=z.m[i]) return false;
        return true;
    } 
    else {
        return false;
    }
}

bool operator!= (const Kvector& v, const Kvector& z) {
    if (v.len==z.len) {
        for (int i=0;i<v.len; i++) 
            if(v.m[i]!=z.m[i]) return true;
        return false; 
    } 
    else { 
        return true;
    }
}

ostream& operator<<(ostream& os, Kvector& v) {
    for(int i=0;i<v.len; i++){
        os << v.m[i] << " ";
    }
    return os;
}

int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    return 0;
}