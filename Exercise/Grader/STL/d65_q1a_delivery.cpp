#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m, method, a, b, k,total=0,count=0,t_min;
    cin >> n >> m;
    map<int, int> p;
    vector<int> target;
    for (int i=0; i<m; i++)
    {
        cin >> k;
        p[k] = -1;
        target.push_back(k);
    }
    queue<int> dotman, platong;
    t_min = p.begin()->first;
    for(int i=0; i<n; i++)
    {
        cin >> method;
        if (method == 1)
        {
            cin >> a >> b;
            if (a == 1)
            {
                platong.push(b);
            }
            else if (a == 2)
            {
                dotman.push(b);
            }
        }
        else if (method == 2)
        {
            count++;
            if ((!platong.empty()) && (!dotman.empty()))
            {
                if (platong.front() <= dotman.front())
                {
                    total += platong.front();
                    platong.pop();
                }else{
                    total += dotman.front();
                    dotman.pop();
                }
                
            }else if(!platong.empty()){
                total += platong.front();
                platong.pop();
            }else if(!dotman.empty()){
                total += dotman.front();
                dotman.pop();
            }

            while(total >= t_min){
                if(p[t_min]==-1){
                    p[t_min] = count;
                }
                auto it = p.upper_bound(t_min);
                if(it == p.end()){
                    break;
                }
                t_min = it->first;
            }
        }
    }
    for(auto it:target){
        cout << p[it] << " ";
    }
    return 0;
}