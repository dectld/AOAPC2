#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000+10;
const int maxm = 180+10;
vector<string> strs[maxn];
int maxlens[maxm];

int c = 0;

void print(string str,int len){
        cout << str;
        for(int i=0;i<len-str.length()+1;i++)
                cout << " ";
}

int main(){
        string str;
        int maxsize = 0;
        memset(maxlens,0,sizeof(maxlens));
        //getchar();
        while(getline(cin,str)){
                //if(str[0]=='#') break;
                stringstream ss(str);
                string x;
                int c2 = 0;
                while(ss>>x){
                        //cout << x << endl;
                        strs[c].push_back(x);
                        maxlens[c2] = max(maxlens[c2],(int)x.length());
                        c2++;
                }
                c++;
        }
        for(int i=0;i<c;i++){
                for(int j=0;j<strs[i].size()-1;j++){
                        print(strs[i][j],maxlens[j]);
                }
                cout << strs[i].back() << endl;
        }
        return 0;
}
