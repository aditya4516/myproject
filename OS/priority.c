/*Q4)Write a C Program using for Non Preemptive Priority SJF Process Scheduling Algorithm to  
Implement following functionality. [10]  
a) Accept Process Number, Arrival Time, Burst Time.  
b) Display Gant Chart  
c) Calculate & Display Average turn around, Waiting Time 
 */
#include<stdio.h>  
int i,j,n,P[10],AT[10],BT[10],TAT[10],WT[10],s=0,temp,PR[10]; 
float avg; 
int main() 
{ 
    printf("Enter no of processes:"); 
    scanf("%d",&n); 
    for(i=0;i<n;i++) 
    { 
        printf("Enter Process No:"); 
        scanf("%d",&P[i]); 
        printf("Enter Arrival Time:"); 
        scanf("%d",&AT[i]); 
        printf("Enter Burst Time:"); 
        scanf("%d",&BT[i]); 
        printf("Enter Priority:"); 
        scanf("%d",&PR[i]); 
    } 
     for(i=0;i<n;i++) 
    { 
            if(AT[i]==0) 
            { 
                temp=P[0]; 
                P[0]=P[i]; 
                P[i]=temp; 
                temp=AT[0]; 
                AT[0]=AT[i]; 
                AT[i]=temp; 
                temp=BT[0]; 
                BT[0]=BT[i]; 
                BT[i]=temp; 
                temp=PR[0]; 
                PR[0]=PR[i]; 
                PR[i]=temp; 
            } 
         
    } 
    for(i=1;i<n;i++) 
    { 
        for(j=i+1;j<n;j++) 
        { 
            if(PR[i]<PR[j]) 
            { 
                temp=P[i]; 
                P[i]=P[j]; 
                P[j]=temp; 
                temp=AT[i]; 
                AT[i]=AT[j]; 
                AT[j]=temp; 
                temp=BT[i]; 
                BT[i]=BT[j]; 
                BT[j]=temp; 
                temp=PR[i]; 
                PR[i]=PR[j]; 
                PR[j]=temp; 
            } 
        } 
    } 
    for(i=1;i<n;i++) 
    { 
        for(j=i+1;j<n;j++) 
        { 
            if(PR[i]==PR[j]) 
            { 
                if(BT[i]>BT[j]) 
                { 
                temp=P[i]; 
                P[i]=P[j]; 
                P[j]=temp; 
                temp=AT[i]; 
                AT[i]=AT[j]; 
                AT[j]=temp; 
                temp=BT[i]; 
                BT[i]=BT[j]; 
                BT[j]=temp; 
                temp=PR[i]; 
                PR[i]=PR[j]; 
                PR[j]=temp; 
                } 
            } 
        } 
    } 
    printf("\nAfter Sorting on Priority:\n"); 
    printf("\nProcess\tAT\tBT\tPriority\n"); 
    for(i=0;i<n;i++) 
    { 
        printf("\n%d\t%d\t%d\t%d\n",P[i],AT[i],BT[i],PR[i]); 
    } 
    WT[0]; 
    for(i=0;i<n;i++) 
    { 
        WT[i+1]=WT[i]+BT[i]; 
        s+=WT[i]-AT[i]; 
    } 
    WT[n]=WT[n-1]+BT[n-1]; 
    avg=(float)s/(float)n; 
    printf("\nWT=%d",s); 
    printf("\nAWT=%f",avg); 
    s=0; 
    for(i=0;i<n;i++) 
    { 
        TAT[i]=WT[i]-AT[i]; 
        s+=WT[i+1]-TAT[i]; 
    } 
    avg=(float)s/(float)n; 
    printf("\nTAT=%d",s); 
    printf("\nATAT=%f",avg); 
    printf("\nGantt Chart Given Below::\n"); 
    printf("\n------------------------------------------------------------------\n"); 
    for(i=0;i<n;i++) 
    { 
        printf("\t|P %d\t",P[i]); 
    } 
    printf("\n-------------------------------------------------------------------\n"); 
        for(i=0;i<=n;i++) 
    { 
        printf("\t %d\t",WT[i]); 
    } 
} 
 
 
