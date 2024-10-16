#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <map>
#include <set>

using namespace std;

class SparseGraph
{
public:
    SparseGraph()
    {
        // Your code here
    }

    SparseGraph(int n_in)
    {
        // Your code here
    }

    SparseGraph(const SparseGraph &G)
    {
        // Your code
        data = G.data;
        tranpose = G.tranpose;
    }

    void AddEdge(int a, int b)
    {
        // Your code here
        if (!tranpose)
        {
            data.insert({a,b});
        }
        else
        {
            data.insert({b,a});
        }
    }

    void RemoveEdge(int a, int b)
    {
        // Your code here
        if (!tranpose)
        {
            data.erase({a,b});
        }
        else
        {
            data.erase({b,a});
        }
    }

    bool DoesEdgeExist(int a, int b) const
    {
        // Your code here
        if (!tranpose)
        {
            return data.find({a,b}) != data.end();
        }else{
            return data.find({b,a}) != data.end();   
        }
    }

    SparseGraph Transpose() const
    {
        SparseGraph temp;
        temp.data = data;
        temp.tranpose = !tranpose;
        return temp;
    }

protected:
    // Your code here
    set<pair<int,int>> data;
    bool tranpose = false;
};
#endif // __SPARSE_GRAPH_H__
