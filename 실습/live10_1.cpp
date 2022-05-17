#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Kvector{
protected:
    int *m;
    public : int len;
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
    cout << this << " : Kvector(int, int)\n";
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

Kvector& Kvector::operator=(Kvector& v) {
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

#define N 3
class Avector : public Kvector{
    char table[N];
public:
    Avector(int sz=0, int v=0, const char *t = "abc") : Kvector(sz, v){
        cout << this << " : Avector(int, int, const char*)\n";
        setTable(t);
        cout << table << endl;
        //여기채우기
    }
    void setTable(const char *t){
        //여기채우기
        for (int i = 0; i < N; i++) {
            table[i] = t[i];
        }
    }
friend ostream& operator<<(ostream& os, const Avector& v);
};
ostream& operator<<(ostream& os, const Avector& v){
    //여기채우기
    for(int i=0;i<N; i++){
        os << v.table[(v.m[i]%3)] << " ";
    }
    return os;
}

int main(int argc, char *argv[]){
    if (argc != 2){
        cout << "usage : ./avector pqr\n";
        return 1;
    }
    Avector v1(3); v1.print();
    Avector v2(2, 1,"xyz"); v2.print();
    Avector v3(v2); v3.print();
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    v1.print();
    cout << v2 << endl;
    v2.print();
    cout << v3 << endl;
    v3.print();
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}