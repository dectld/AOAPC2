#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1000+10;
struct Point{
        int x,y;
}p[maxn];
int a[maxn];

int main(){
        int T, n;
        cin >> T;
        while(T--){
                cin >> n;
                cin >> p[0].x >> p[0].y;
                memset(a,0,sizeof(a));
                int minx = p[0].x, maxx=p[0].x;
                for(int i=1;i<n;i++){
                        cin >> p[i].x >> p[i].y;
                        if(p[i].x<minx) minx = p[i].x;
                        if(p[i].x>maxx) maxx = p[i].x;
                }
                int line = minx+maxx;
                int count = 0;
                for(int i=0;i<n;i++){
                        a[i] = 1;
                        for(int j=0;j<n;j++){
                                if(2*p[i].x==line){ count+=1; break;}
                                if(!a[j]&&p[i].x+p[j].x==line&&p[i].y==p[j].y){
                                        a[j] = 1; count+=2; break;
                                }
                        }
                }
                if(count<n) printf("NO\n");
                else printf("YES\n");
        }
        return 0;
}
