#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> processPriority;
    queue<pair<int, int>> process;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        processPriority.push(priorities[i]);
        process.push({priorities[i], i});
    }
    
    while(!process.empty())
    {
        if (process.front().first == processPriority.top())
        {
            answer += 1;
            processPriority.pop();
            
            if (process.front().second == location)
            {
                break;
            }
        }
        else
        {
            process.push(process.front());
        }
        
        process.pop();
    }
    
    return answer;
}