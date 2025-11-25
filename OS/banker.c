/*Q.1) Write a C Program using Bankers Algorithm to implement following functionality. [15]  
a) Accept Available Allocation Max  
b) Display Need Matrix  
c) Calculate & Display Safe Sequence. 

*/

#include<stdio.h> 
int p,r,i,j,ch,ind,req[20]; 
int allocation[20][20],max[20][20],need[20][20],avaliable[10],safe[20]; 
int temp=0,s=0,work[20],finish[20],flag=0; 
void check() 
{ 
for(i=0;i<p;i++) 
{ 
} 
for(j=0;j<r;j++) 
{ 
} 
need[i][j]=max[i][j]-allocation[i][j]; 
printf("\nNeed Table Is:\n"); 
for(i=0;i<p;i++) 
{ 
} 
for(j=0;j<r;j++) 
{ 
} 
printf("%d\t",need[i][j]); 
printf("\n"); 
for(i=0;i<p;i++) 
   { 
       finish[i]=0; 
   } 
   for(i=0;i<r;i++) 
   { 
      work[i]=avaliable[i]; 
   } 
   while(temp<2) 
   { 
      for(i=0;i<p;i++) 
      { 
         for(j=0;j<r;j++) 
          { 
            if(finish[i]==0 && need[i][j]<=work[j]) 
            { 
               flag=1; 
            }  
            else 
            { 
               flag=0; 
               break; 
            } 
          } 
          if(flag==1) 
          { 
            for(j=0;j<r;j++) 
            { 
               work[j]=work[j]+allocation[i][j]; 
            } 
            finish[i]=1; 
            safe[s++]=i; 
          } 
      } 
      temp++; 
   } 
   flag=0; 
   for(i=0;i<p;i++) 
   { 
      if(finish[i]==0) 
      { 
         flag=1; 
         break; 
 
      } 
   } 
   if(flag==1){ 
      printf("System in deadlock state..!"); 
   } 
   else{ 
      printf("System in safe state..!"); 
      printf("\nSafe Sequence is::\n"); 
      for(i=0;i<p;i++) 
      { 
         printf("P%d\t",safe[i]); 
      }  
   } 
} 
int main() 
{ 
   printf("Enter no of resources and processes:"); 
   scanf("%d%d",&r,&p); 
   printf("Enter allocation table:\n"); 
   for(i=0;i<p;i++) 
   { 
     for(j=0;j<r;j++) 
     { 
        scanf("%d",&allocation[i][j]); 
     } 
   } 
    
   printf("Enter max table:\n"); 
   for(i=0;i<p;i++) 
   { 
     for(j=0;j<r;j++) 
     { 
        scanf("%d",&max[i][j]); 
     } 
   } 
    
   printf("Enter allocation table:"); 
     for(i=0;i<r;i++) 
     { 
        scanf("%d",&avaliable[i]); 
     } 
     check(); 
} 
