#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100+10;
int a[maxn];

int main(){
        int T;
        cin >> T;
        while(T--){
                memset(a,0, sizeof(a));
                int n, m, job;
                cin >> n >> m;
                for(int i=0;i<n;i++){
                        cin >> a[i];
                        if(i==m) job = a[i];
                }
                int max, p1=0, p2=0,count=0;
                while(1){
                        max = 0;
                        for(int i=0;i<n;i++){
                                if(a[(p1+i)%n]>max){
                                        max = a[(p1+i)%n]; p2=i;
                                }
                        }
                        p1 = (p1+p2)%n;
                        //cout<<"p1="<<p1<<endl;
                        if(max==job) break;
                        //cout<<"idx="<<p1<<",num="<<a[p1]<<endl;
                        a[p1] = 0; count++;
                        do{
                                p1 = (p1+1)%n;
                        }while(!a[p1]);
                        //cout<<"p1="<<p1<<endl;
                }
                for(int i=0;i<n;i++){
                        if(a[i]==job&&m<p1&&(i>=p1||i<m)) count++;
                        if(a[i]==job&&m>p1&&i>=p1&&i<m) count++;
                        /*if(a[i]==job&&m<p1&&(i>=p1||i<m)){
                                count++;
                                cout<<"idx="<<p1<<",num="<<a[p1]<<endl;
                        }
                        if(a[i]==job&&m>p1&&i>=p1&&i<m){
                                count++;
                                cout<<"idx="<<p1<<",num="<<a[p1]<<endl;
                        }*/
                }
                cout << ++count << endl;
        }
        return 0;
}
