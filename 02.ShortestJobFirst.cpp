#include<bits/stdc++.h>
using namespace std;

class Pro{
public:
    int pid;
    int att;
    int bt;
    int ct;
    int tat;
    int wt;

    Pro(int id, int arrival, int brust)
    {
        pid = id;
        att = arrival;
        bt = brust;
        ct = tat = wt = 0;
    }
};

bool cmpBrust(Pro a, Pro b)
{
    return a.bt < b.bt;
}

int main()
{
    int n;
    cout << "Enter no of process: ";
    cin >> n;

    vector<Pro> process;

    for(int i = 0; i < n; i++)
    {
        int att, bt;
        cout << "Enter Arrival time & Brust time: ";
        cin >> att >> bt;
        process.push_back(Pro(i+1, att, bt));
    }

    sort(process.begin(), process.end(), cmpBrust);

    int time = 0;
    float waitingTime = 0;
    for(int i = 0; i < n; i++)
    {
        if(time < process[i].att)
        {
            time = process[i].att;
        }
        process[i].ct = time + process[i].bt;
        time = process[i].ct;

        process[i].tat = process[i].ct - process[i].att;
        process[i].wt = process[i].tat - process[i].bt;

        waitingTime += process[i].wt;
    }

    cout << "\nProcess\t " << "At\t " << "Bt\t " << "ct\t " << "Tat\t " << "Wt\n";
    for(int i = 0; i < n; i++)
    {
        cout << process[i].pid << "\t\t " << process[i].att << "\t " << process[i].bt << "\t " << process[i].ct << "\t " << process[i].tat << "\t " << process[i].wt << "\n";
    }

    cout << "\nAverage Waiting Time: " << waitingTime / n << "\n";
}