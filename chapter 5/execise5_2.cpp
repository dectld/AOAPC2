#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<vector<int>, int> IDcache;
vector<vector<int> > seqcache;

const int maxn = 1000+10;
vector<int> seq[maxn];

int ID(vector<int> x){
        if(IDcache.count(x)) return IDcache[x];
        seqcache.push_back(x);
        return IDcache[x] = seqcache.size()-1;
}

int main(){
        int T;
        cin >> T;
        while(T--){
                int n,x;
                cin >> n;
                seq[0].clear();
                seq[1].clear();
                for(int i=0;i<n;i++){
                        cin>>x;
                        seq[0].push_back(0);
                        seq[1].push_back(x);
                }
                IDcache.clear();
                seqcache.clear();
                ID(seq[0]);
                ID(seq[1]);
                //cout<<ID(seq[0])<<"  "<<ID(seq[1])<<"\n";
                //cout << "step 1\n";
                for(int i=2;;i++){
                        seq[i].clear();
                        for(int j=0;j<n;j++){
                                //cout << "step2\n";
                                seq[i].push_back(abs(seq[i-1][j]-seq[i-1][(j+1)<n?j+1:0]));
                                //cout << seq[i][j] << "  ";
                        }
                        //cout << endl;
                        if(!IDcache.count(seq[i])) ID(seq[i]);
                        else if(ID(seq[i])==ID(seq[0])){ cout<<"ZERO\n"; break;}
                        else{ cout<<"LOOP\n"; break;}
                }
                /*for(int i=0;i<seqcache.size();i++){
                        printf("%d\t",ID(seqcache[i]));
                }
                printf("\n");*/
        }
        return 0;
}
