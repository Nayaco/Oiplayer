#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
const int NE=300005,NV=30005,Max=1<<30;
int v[NE],head[NV],next[NE],cap[NE],flow[NE],vis[NV],dep[NV];
int tot=0;
int n,m,s,t;
void add(int a,int b,int w){
	tot++;v[tot]=b;cap[tot]=w;flow[tot]=0;next[tot]=head[a];head[a]=tot;
	tot++;v[tot]=a;cap[tot]=0;flow[tot]=0;next[tot]=head[b];head[b]=tot;
}
int bfs(){
	memset(vis,0,sizeof(vis));
	queue<int > q;
	vis[s]=1;q.push(s);
	dep[s]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=0;i=next[i]){
			int k=v[i];
			if(!vis[k]&&cap[i]>flow[i]){
				dep[k]=dep[x]+1;
				vis[k]=1;q.push(k);
			}
		}
	}
	return vis[t];
}
int dfs(int x,int a){
	if(x==t||a==0)return a;
	int fl=0,f,l=a;
	for(int i=head[x];i!=0;i=next[i]){
		if(dep[v[i]]==dep[x]+1){
			f=dfs(v[i],min(l,cap[i]-flow[i]));
			if(f>0){
				flow[i]+=f;
				if(i&1)flow[i+1]-=f;
				else flow[i-1]-=f;
				fl+=f;l-=f;
				if(l==0)break;
			}
		}
	}return fl;
}
int dinic(){
	int fl=0;
	while(bfs())fl+=dfs(s,Max);
	return fl;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);int x,y,z;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&x,&y,&z),add(x,y,z);
	int ans=dinic();
	printf("%d",ans);return 0;
}
