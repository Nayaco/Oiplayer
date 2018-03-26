#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
char str[1000005];
int  main(){
    cin>>str;
    int t = str[0]=='-'?1:0;
    if(t==1)cout<<'-';
    int s=strlen(str)-1;while(str[s]=='0')s--;
    for(int i = s; i >= t; i--){       
        cout<<str[i];
    }
    getchar();
    getchar();
    return 0;
}