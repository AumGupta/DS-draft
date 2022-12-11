 /* 
  * 
  * 
  * Program by Om Gupta (214047)
  */
 
 
#include<iostream>
#include<iomanip>
using namespace std;
 
void fcfs(int processCount, int* burstTime){
    int waitTime[processCount],i = 0;
    float sum = 0;
    cout<<endl<<left<<setw(15)<<"PROCESS"<<setw(15)<<"WAITING TIME"<<setw(15)<<"TURN AROUND TIME"<<endl;
    for (i ; i<processCount; i++){
        cout<<setw(15)<<i+1<<setw(15)<<sum;
        waitTime[i] = sum;
        sum+=burstTime[i];
        cout<<setw(15)<<sum<<'\n';
    }
    sum = 0;
    for (i = 0; i < processCount; i++){
        sum += waitTime[i];
    }
    cout<<endl<<"Average Waiting Time = "<<sum/processCount;

 }

 int main(){
    int n;
    cout<<"ENTER NUMBER OF PROCESSES: ";
    cin>>n;
    int bursts[n] = {};
    for(int i = 0; i<n; i++){
        printf("ENTER BURST TIME OF PROCESS-%d: ",i+1);
        cin>>bursts[i];
    }
    fcfs(n ,bursts);
    return 0;
 }