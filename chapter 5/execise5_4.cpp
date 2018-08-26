#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 500000+10;
vector<int> candidates[maxn];
map<vector<int>, int> nums;

int main(){
        int n;
        while(cin>>n&&n){
                int x1,x2;
                nums.clear();
                for(int i=0;i<n;i++){
                        candidates[i].clear();
                        cin >> x1 >> x2;
                        candidates[i].push_back(x1);
                        candidates[i].push_back(x2);
                        if(!nums.count(candidates[i])) nums[candidates[i]] = 0;
                        nums[candidates[i]]++;
                }
                int f=1;
                for(map<vector<int>, int>::iterator it=nums.begin();it!=nums.end();it++){
                        int n1 = it->second, n2=0;
                        vector<int> x = it->first;
                        reverse(x.begin(), x.end());
                        //cout<<"origin:"<<it->first[0]<<" "<<it->first[1]<<" "<<n1<<endl;
                        if(nums.count(x)) n2=nums[x];
                        //cout<<"last:"<<x[0]<<" "<<x[1]<<" "<<n2<<endl;
                        if(n1!=n2){ f=0; break;}
                }
                if(f) cout<<"YES\n";
                else cout<<"NO\n";
        }
        return 0;
}
