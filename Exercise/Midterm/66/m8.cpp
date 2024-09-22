#include <bits/stdc++.h>
using namespace std;

void processTasks(int n,
                  const std::vector<std::pair<std::string, std::pair<std::string, int>>> &tasks, // tasks.size() คือ m
                  std::vector<std::string> &finish_task,
                  std::map<std::string, int> &client_total)
{
    using namespace std;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    string name, job;
    int dur;
    for (int i = 0; i < tasks.size(); i++)
    {
        if (pq.size() < n)
        {
            name = tasks[i].first;
            job = (tasks[i].second).first;
            dur = (tasks[i].second).second;
            pq.push(make_pair(dur, job));
            client_total[name] += dur;
        }
        else
        {
            while (!pq.empty())
            {
                job = (pq.top()).second;
                finish_task.push_back(job);
                pq.pop();
            }
        }
    }
}

int main()
{
    const std::vector<std::pair<std::string, std::pair<std::string, int>>> tasks; // tasks.size() คือ m
    std::vector<std::string> finish_task;
    std::map<std::string, int> client_total; 
    
    return 0;
}