#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <functional>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p){
    os << "[" << p.first << "]" << p.second;
    return os;
}
template <class T>
void print_container(const T& container, string s=""){
    cout << s << "(" << container.size() << ") ";
    auto it = container.begin();
    for (; it != container.end(); it++) cout << *it << " ";
    cout << endl;
}
int main(){
    int a[10] = {3,7,3,1,2,7,0,5,4,6};
    vector<int> v(&a[0], &a[10]);
    deque<int> dq(&v[0], &v[10]);
    list<int> li(&dq[0], &dq[10]);
    set<int> s;
    multiset<int> ss;
    map<int,int> m;
    multimap<int, int> mm;
    for(int i=0; i<10; i++){
        s.insert(a[i]);
    }
    for(int i=0; i<10; i++){
        ss.insert(a[i]);
    }
    for(int i=0; i<10; i++){
        m.insert(make_pair(i,a[i]));
    }
    for(int i=0; i<10; i++){
        mm.insert(make_pair(i,a[i]));
    }
    print_container(v, "v= ");
    print_container(dq, "dq= ");
    print_container(li, "li= ");
    print_container(s, "s= ");
    print_container(ss, "ss= ");
    print_container(m, "m= ");
    print_container(mm, "mm= ");
    return 0;
}