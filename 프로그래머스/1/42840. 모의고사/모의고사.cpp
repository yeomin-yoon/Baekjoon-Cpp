#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == first[i % first.size()])
        {
            count1++;
        }
        if (answers[i] == second[i % second.size()])
        {
            count2++;
        }
        if (answers[i] == third[i % third.size()])
        {
            count3++;
        }
    }
    
    int maxCount = max({count1, count2, count3});
    if (maxCount == count1)
    {
        answer.push_back(1);
    }
    if (maxCount == count2)
    {
        answer.push_back(2);
    }
    if (maxCount == count3)
    {
        answer.push_back(3);
    }
    
    return answer;
}