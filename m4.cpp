#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
string sent,word;
int lens,lenw,t,pos; 
int main()
 {
	 getline(cin,word);  
	 getline(cin,sent);
	 lenw=word.size();   
	 lens=sent.size();
	 for(int i=0;i<lenw;i++)
	 	word[i]=toupper(word[i]); 
	 for(int i=0;i<lens;i++)
	 	sent[i]=toupper(sent[i]);
	 t=0;
	 for(int i=0;i<=lens-lenw;i++)
	 {
		 int j;
		 for(j=0;j<lenw;++j)
		 {
		     if(sent[j+i]!=word[j])break;
		 	 if(i>0&&sent[i-1]!=' ')break;     
		}
		if(j==lenw&&(sent[j+i]==' '||j+i==lens)) 
		{
			 t++;
			 if(t==1) pos=i;
		 }
	 }
	 if(t==0)cout<<-1;
	 else cout<<t<<" "<<pos;
	 return 0;
 }