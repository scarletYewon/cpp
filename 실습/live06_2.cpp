#include <iostream>
using namespace std;

class Kvector{
    int *m;
    int len;
public:
    Kvector(int sz=0, int value = 0){
        cout << this << " : Kvector( " << sz << ", " << value << ")\n";
        len = sz;
        if (sz>0) {
            m = new int[sz];
        }
        else {
            m = nullptr;
        }
        for(int i=0; i<sz; i++) m[i] = value;
    }
    Kvector(Kvector& v){
        len = v.len;
        if (v.len>0){
             m = new int[v.len];
        }
        else {
            m= nullptr;
        }
        for(int i=0; i<v.len; i++) m[i] = v.m[i];
        cout << this << " : Kvector(*" << &v << ")\n";
    }
    ~Kvector(){
        cout << this << " : ~Kvector()" << endl;
        delete[] m;
    }
    void print(){
        for(int i=0; i<len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear(){
        delete[] m;
        m = nullptr;
        len = 0;
    }
    int size(){return len;}
};

int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2,9); v2.print();
    Kvector v3(v2); v3.print();
    v2.clear();
    v2.print();
    v3.print();
    return 0;
}