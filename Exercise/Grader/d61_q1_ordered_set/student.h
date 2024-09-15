#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for(auto it:A){
        if(s.find(it) == s.end()){
            v.push_back(it);
            s.insert(it);
        }
    }
    for(auto it:B){
        if(s.find(it) == s.end()){
            v.push_back(it);
            s.insert(it);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s,sa(A.begin(),A.end()),sb(B.begin(),B.end());
    for(auto it:A){
        if(sb.find(it) != sb.end()){
            v.push_back(it);
            s.insert(it);
        }
    }
    for(auto it:B){
        if(((sa.find(it)) != sa.end())&&(s.find(it) == s.end())){
            v.push_back(it);
            s.insert(it);
        }
    }
    return v;
}
