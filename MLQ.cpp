#include<bits\stdc++.h>
using namespace std;
int main()
{
    int process[20],burst_time[20], sys_usr[20], wt[20],tat[20], n, temp;
    float wtavg, tatavg;
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        process[i] = i;
        cout<<"Enter the Burst Time of Process "<<i<<": ";
        cin>>burst_time[i];
        cout<<"System/User Process (0/1) ? ";
        cin>>sys_usr[i];
    }
    //sorting process, burst time and system or user priority number
    for(int i=0; i<n; i++)
    {
        for(int k=i+1; k<n; k++)
            if(sys_usr[i] > sys_usr[k])
            {
                temp=process[i];
                process[i]=process[k];
                process[k]=temp;
                temp=burst_time[i];
                burst_time[i]=burst_time[k];
                burst_time[k]=temp;
                temp=sys_usr[i];
                sys_usr[i]=sys_usr[k];
                sys_usr[k]=temp;
            }
    }
    wtavg = wt[0] = 0;
    tatavg = tat[0] = burst_time[0];
    //calculating average waiting time and average turn around time
    for(int i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + burst_time[i-1];
        tat[i] = tat[i-1] + burst_time[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    cout<<"_________________________________________________________________________________"<<endl;
    cout<<"PROCESS\t  SYSTEM/USER PROCESS \t   BURST TIME\t  WAITING TIME\t  TURNAROUND TIME"<<endl;
    cout<<"_________________________________________________________________________________"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"  "<<process[i]<<"\t\t"<<sys_usr[i]<<"\t\t\t"<<burst_time[i]<<"\t\t"<<wt[i]<<"  \t\t"<<tat[i]<<endl;
        if(i<n-1)
            cout<<"---------------------------------------------------------------------------------"<<endl;
    }
    cout<<"_________________________________________________________________________________"<<endl;
    cout<<"\nAverage Waiting Time = "<<wtavg/n;
    cout<<"\nAverage Turnaround Time = "<<tatavg/n;
    return 0;
}
