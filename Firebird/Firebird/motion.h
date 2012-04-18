#include "routines.h"
#include "funcs.h"





int find_type(int pres,int dest){
    
    int px=pres%6,py=pres/6,dx=dest%6,dy=dest/6;
    if(px==dx && py==dy)        return -1;
    else if(px==dx && py<dy)    return 0;
    else if(px< dx && py<dy)    return 1;
    else if(px< dx  && py==dy)  return 2;
    else if(px< dx && py>dy)    return 3;
    else if(px==dx && py>dy)    return 4;
    else if(px> dx && py>dy)    return 5;
    else if(px> dx && py==dy)   return 6;
    else  return 7;
}

int dfs(int pres, int dest){
    
    if(dest==pres){         
         path[off++]=pres;
         return 1;
     }
     if(visit[pres]) return 0;
     visit[pres]=1;
     path[off++]=pres;
     
    int x,type =  find_type(pres,dest);
    
    type = priority[type];
    if(edges[pres][type/1000]){
        x = dfs(pres+offset[type/1000], dest);
        if(x==1)return 1; 
    }
    if(edges[pres][(type/100)%10]){
        x = dfs(pres+offset[(type/100)%10], dest);
        if(x==1)return 1;
        }
    if(edges[pres][(type/10)%10]){
        x = dfs(pres+offset[(type/10)%10], dest);
        if(x==1)return 1;
    }
    if(edges[pres][type%10]){
        x = dfs(pres+offset[type%10], dest);
        if(x==1)return 1;
    }
    off--;
    return 0;
}

void dfs_init(){
	int i;
	for(i=0;i<36;i++) visit[i]=0;
	off=0;
}

void set_dest(int i){
	x_dest=path[i]%6;
	y_dest=path[i]/6;
}

void init(){
	int i,j;
	for (i=0;i<36;i++){
		for (j=0;j<4;j++)edges[i][j]=1;
	}
}
