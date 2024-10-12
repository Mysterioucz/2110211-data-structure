#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <map>
#include <set>

using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        map<int,int> temp;
        for(int i = 0;i < 3;i++){
            data[i] = temp;
        }
    }

    SparseGraph(int n_in) {
        // Your code here
        map<int,int> temp;
        for(int i = 0;i < n_in;i++){
            data[i] = temp;
        }
    }

    SparseGraph(const SparseGraph& G) {
        // Your code 
        data = G.data;
        edge_count = G.edge_count;
    }

    void AddEdge(int a, int b) {
        // Your code here
        data[a][b] = 1;
        edge_count++;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if(data.find(a) != data.end()){
            if(data[a].find(b) != data[a].end()){
                data[a][b] = 0;
                edge_count--;
            }
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if(data.find(a) != data.end()){
            if(data.at(a).find(b) != data.at(a).end()){
                return data.at(a).at(b) == 1;
            }
        }
        return false;

    }

    SparseGraph Transpose() const {
        // Your code here
        int i = 0, c = 0;
        SparseGraph temp(data.size());
        while((i < data.size())&&(c < edge_count)){
            for(auto j:data.at(i)){
                if(j.second){
                    temp.AddEdge(j.first,i);
                }
                            c++;
            }
            i++;
        }
        return temp;
    }

protected:
    // Your code here
    map<int,map<int,int>> data;
    int edge_count = 0;
};
#endif // __SPARSE_GRAPH_H__

