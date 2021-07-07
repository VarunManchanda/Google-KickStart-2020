//Hint:- Solved using Dynamic Programming Approach.


/* 
 * File:   main.cpp
 * Author: apxb08
 *
 * Created on 06 January 2021, 8:29 PM
 */
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

bool  vis[51][1501];
long long int  res[51][1501];
int a[51][31];
int n,k;

/*
 * 
 */
int  plate_beauty[55][55];
int  max_beauty( int i,int p)
{
    if(i>=n && p>0)
    {
        return INT_MIN;
    }
if(p<=0|| i>=n)
        return 0;
if(vis[i][p])
    return res[i][p];
int maxt=0;
maxt = max_beauty(i+1,p);
for(int j = 1;j<=min(p,k);j++)
{
    maxt = max(a[i][j-1]+ max_beauty(i+1,p-j),maxt);
}
res[i][p]= maxt;
vis[i][p]=1;
return maxt;
}
        

 int  main(int  argc, char** argv) {

  
     int t,p,j,i,tnum,plate,stk;
    
    scanf("%d",&t);
    for(tnum=1;tnum<=t;tnum++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&n,&k,&p);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i][0]);
            for(j=1;j<k;j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]+=a[i][j-1];
            }
        }
    
    
        
         printf("Case #%d: %d\n",tnum,max_beauty(0,p));
    }
}
