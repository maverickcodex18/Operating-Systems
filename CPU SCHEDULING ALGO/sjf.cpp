#define cpp
#ifdef cpp
//cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
#include"myFcfs.cpp"
using namespace std;


void sjf() {
    fcfs();
    int lengthOfGantt=ganttChart::gantt.size();
    for (int i = 0; i < lengthOfGantt; i++)
    {
        int smallIndex=i;
        for (int j= i+1; j < lengthOfGantt; j++)
        {
            if((ganttChart::gantt[i].getarrivalTime()==ganttChart::gantt[j].getarrivalTime())&&(ganttChart::gantt[i].getburstTime()>ganttChart::gantt[j].getburstTime())) smallIndex=j;
        }
        swap(ganttChart::gantt[i],ganttChart::gantt[smallIndex]);

    }


}




//  int main(){
//     cout<<"Chitransh Agrawal\n22115026\n";
//      cout << "SJF\n";
//      enterProcess();
//      sjf();
//      setTimeGantt();
//      showGantt();
//      showGanttChart();
//      return 0;
//  }
#else
//c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main() {
    return 0;
}
#endif
