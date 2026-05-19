#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    bool bIsAllComplete = false;
    int answerSum = 0;
    
    while(!bIsAllComplete)
    {
        // 하루 작업
        queue<int> progressOrder;
        
        answerSum = accumulate(answer.begin(), answer.end(), 0);
        
        for (int i = 0 + answerSum; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
            progressOrder.push(progresses[i]);
        }
    
        // 가장 앞 순서 진도 체크 (반복)
        int countCompleted = 0;
        while(!progressOrder.empty() && progressOrder.front() >= 100)
        {
            countCompleted += 1;
            progressOrder.pop();
        }
        
        if (countCompleted == 0)
        {
            continue;
        }
        
        answer.push_back(countCompleted);
            
        answerSum = accumulate(answer.begin(), answer.end(), 0);
        
        if (progresses.size() == answerSum)
        {
            bIsAllComplete = true;
        }
    }
    
    return answer;
}