#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    queue<char> StringQ;
    
    for (char c : s)
    {
        StringQ.push(c);
    }

    int CountLeft = 0;
    int CountRight = 0;
    
    while(!StringQ.empty())
    {
        if(StringQ.front() == '(')
        {
            CountLeft += 1;
        }
        else
        {
            CountRight += 1;
        }
        
        if(CountLeft < CountRight)
        {
            return answer;
        }

        StringQ.pop();
    }
    
        if(CountLeft == CountRight)
        {
            return answer = true;
        }
    
    return answer;
}