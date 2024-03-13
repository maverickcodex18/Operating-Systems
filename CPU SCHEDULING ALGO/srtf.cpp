// #define cpp
// #ifdef cpp
// //cpp
// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<stack>
// #include<cmath>
// #include"sjf.cpp"
// using namespace std;

// void srtf(){
//     sjf();
//     int timeQuanta=1;
//     int counter=0;
//     int lengthOfGantt=ganttChart::gantt.size();
//     setAllLeftBurstTime();
//     ganttChart::gantt[0].setfutureArrivalTime(ganttChart::gantt[0].getarrivalTime());
//     for (int i = 0; i < lengthOfGantt; i++)
//     {
//         if (ganttChart::gantt[i].getleftBurstTime()==0) continue;
//         int smallIndex=i;
//         for (int j= i+1; j < lengthOfGantt; j++)
//         {   if (ganttChart::gantt[j].getleftBurstTime()==0) continue;
//             else ++counter;
//             int additionalTime=timeQuanta*counter;
//             if((ganttChart::gantt[i].getarrivalTime()+additionalTime>=ganttChart::gantt[j].getarrivalTime())&&(ganttChart::gantt[i].getleftBurstTime()>ganttChart::gantt[j].getleftBurstTime())) smallIndex=j;
//         }

//         showPreemptGantt(smallIndex,timeQuanta);
//     }
// }






// int main(){
//     cout << "SRTF\n";
//     enterProcess();
//     srtf();
//     setTimeGantt();
//     cout<<endl;
//     //showGantt();
//     showGanttChart();
//     return 0;
// }

// #else
// //c

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<math.h>
// int main() {

//     return 0;
// }
// #endif





// C++ program to implement Shortest Remaining Time First
// Shortest Remaining Time First (SRTF)

#include <bits/stdc++.h>
using namespace std;

struct Process {
	int pid; // Process ID
	int bt; // Burst Time
	int art; // Arrival Time
};

// Function to find the waiting time for all
// processes
void findWaitingTime(Process proc[], int n,
								int wt[])
{
	int rt[n];

	// Copy the burst time into rt[]
	for (int i = 0; i < n; i++)
		rt[i] = proc[i].bt;

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	// Process until all processes gets
	// completed
	while (complete != n) {

		// Find process with minimum
		// remaining time among the
		// processes that arrives till the
		// current time`
		for (int j = 0; j < n; j++) {
			if ((proc[j].art <= t) &&
			(rt[j] < minm) && rt[j] > 0) {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false) {
			t++;
			continue;
		}

		// Reduce remaining time by one
		rt[shortest]--;

		// Update minimum
		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;

		// If a process gets completely
		// executed
		if (rt[shortest] == 0) {

			// Increment complete
			complete++;
			check = false;

			// Find finish time of current
			// process
			finish_time = t + 1;

			// Calculate waiting time
			wt[shortest] = finish_time -
						proc[shortest].bt -
						proc[shortest].art;

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		// Increment time
		t++;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int n,
						int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0,
					total_tat = 0;

	// Function to find waiting time of all
	// processes
	findWaitingTime(proc, n, wt);

	// Function to find turn around time for
	// all processes
	findTurnAroundTime(proc, n, wt, tat);

	// Display processes along with all
	// details
	cout << " P\t\t"
		<< "BT\t\t"
		<< "WT\t\t"
		<< "TAT\t\t\n";

	// Calculate total waiting time and
	// total turnaround time
	for (int i = 0; i < n; i++) {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t"
			<< proc[i].bt << "\t\t " << wt[i]
			<< "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
    cout<<"Chitransh Agrawal\n22115026\n";
	Process proc[] = { { 1, 6, 2 }, { 2, 2, 5 },
					{ 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
	int n = sizeof(proc) / sizeof(proc[0]);

	findavgTime(proc, n);
	return 0;
}
