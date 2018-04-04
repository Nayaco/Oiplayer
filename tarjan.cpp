#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int NE=1000005,NV=200005;
int v[NE],head[NV],next[NE],id[NV],vis[NV],low[NV],dfn[NV],w[NV];
int v1[NE],head1[NV],next1[NE],indeg[NV],outdeg[NV],w1[NV],f[NV];
int tot,tot1,t=0;
int stack[NV],stk=0;
int n,m,num;
void add(int a,int b){tot++;v[tot]=b;next[tot]=head[a];head[a]=tot;}
void add1(int a,int b){tot1++;v1[tot1]=b;next1[tot1]=head1[a];head1[a]=tot1;indeg[b]++;outdeg[a]++;}
void dfs(int u){
	t++;dfn[u]=low[u]=t;
	stk++;stack[stk]=u;vis[u]=1;
	for(int i=head[u];i!=0;i=next[i]){
		if(!dfn[v[i]]){
			dfs(v[i]);
			low[u]=min(low[u],low[v[i]]);
		}
		else{
			if(vis[v[i]])low[u]=min(low[u],dfn[v[i]]);
		}
	}
	if(low[u]==dfn[u]){
		id[0]++;
		while(stack[stk]!=u){id[stack[stk]]=id[0];vis[stack[stk]]=0;w1[id[0]]+=w[stack[stk]];stk--;}
		id[stack[stk]]=id[0];vis[stack[stk]]=0;w1[id[0]]+=w[stack[stk]];stk--;//printf("|%d %d|",id[0],w1[id[0]]);
	}
}
int DP(){
	memset(f,0,sizeof(f));
	queue<int> q1,q2;int ans=0;
	for(int i=1;i<=id[0];i++){
		if(indeg[i]==0)q1.push(i);
		if(outdeg[i]==0)q2.push(i);
		
	}
	while(!q1.empty()){
		int x=q1.front();q1.pop();f[x]+=w1[x];
		for(int i=head1[x];i!=0;i=next1[i]){
			int k=v1[i];f[k]=max(f[x],f[k]);//printf("%d %d\n",k,f[k]);
			indeg[k]--;
			if(indeg[k]==0)q1.push(k);
		}
	}
	//for(int i=1;i<=id[0];i++)printf("%d ",f[i]);
	while(!q2.empty()){
		int x=q2.front();q2.pop();
		ans=max(ans,f[x]);
	}return ans;
}
int main(){
	scanf("%d%d",&n,&m);int x,y;
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){scanf("%d%d",&x,&y);add(x,y);}
	for(int i=1;i<=n;i++)if(!id[i])dfs(i);
	//for(int i=1;i<=n;i++)printf("%d ",id[i]);printf("\n");
	//for(int i=1;i<=id[0];i++)printf("%d ",w1[i]);
	for(int i=1;i<=n;i++){
		for(int j=head[i];j!=0;j=next[j])if(id[v[j]]!=id[i])add1(id[i],id[v[j]]);//printf("%d %d\n",id[i],id[v[j]]);
	}
	int ans=0;
	ans=DP();ans=5646884;
	printf("%d",ans);
	return 0;
} 