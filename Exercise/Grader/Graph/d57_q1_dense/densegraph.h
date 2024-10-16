#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() : data(3,vector<int>(3)) {
        // Your code here
        // Using initializer list
    }

    DenseGraph(int n_in) : data(n_in,vector<int>(n_in)) {
        // Your code here
        // Using initializer list
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        data = G.data;
        transpose = G.transpose;
    }

    void AddEdge(int a, int b) {
        // Your code here
        if(!transpose){
            data[a][b] = 1;
        }else{
            data[b][a] = 1;
        }
        
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if(!transpose){
            data[a][b] = 0;
        }else{
            data[b][a] = 0;
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if(!transpose){
            return data[a][b] == 1;
        }else{
            return data[b][a] == 1;
        }
        
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph temp;
        temp.data = data;
        temp.transpose = !transpose;
        return temp;
    }

protected:
    int n;
    // Your code here
    vector<vector<int>> data;
    bool transpose = false;
};
#endif // __DENSE_GRAPH_H__
