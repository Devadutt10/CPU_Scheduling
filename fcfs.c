#include<stdio.h>


struct process{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
};

void main(){
	
	int num_process;
	printf("Enter the number of processes:");
	scanf("%d",&num_process);
	
	struct process p[num_process];
	
	printf("Start entering the details of the processes...\n");
	
	for(int i=0;i<num_process;i++){
		printf("Enter the Process ID, Arrival time and the Burst time of process %d:",i+1);
		scanf("%d %d %d",&p[i].pid, &p[i].at, &p[i].bt);
	}
	
	//Arranging the processes based on arrival time...
	
	for(int i=0;i<num_process;i++){
		for(int j=0;j<num_process-i-1;j++){
			if(p[i].at > p[i+1].at){
				struct process temp = p[i];
				p[i] = p[i+1];
				p[i+1]=temp;
			}
		}
	}
	
	int temp;
	p[0].ct = p[0].bt;
	p[0].tat = p[0].ct - p[0].at;
	p[0].wt = p[0].tat - p[0].bt;
	temp = p[0].ct;
	
	for(int i=1;i<num_process;i++){
		p[i].ct = temp + p[i].bt;
		temp = p[i].ct;
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
	
	printf("The scheduled processes in FCFS scheduling is...\n");
	
	printf("%-12s %-14s %-12s %-17s %-17s %-14s\n",
		
		"PROCESS ID",
		"ARRIVAL TIME",
		"BURST TIME",
		"COMPLETION TIME",
		"TURNAROUND TIME",
		"WAITING TIME"
	
	
	);
	
	for(int i=0;i<num_process;i++){
		printf("%-12d %-14d %-12d %-17d %-17d %-14d\n",
		
		p[i].pid,
		p[i].at,
		p[i].bt,
		p[i].ct,
		p[i].tat,
		p[i].wt
		
		
		);
	}
	
	float total_tat=0;
	float total_wt=0;
	
	for(int i=0;i<num_process;i++){
		total_tat += p[i].tat;
		total_wt += p[i].wt;
	}
	
	float avg_tat, avg_wt;
	
	avg_tat = total_tat/num_process;
	avg_wt = total_wt/num_process;
	
	printf("The average Turnaround time is: %f\n",avg_tat);
	printf("The average Waiting time is: %f\n",avg_wt);
	


}
