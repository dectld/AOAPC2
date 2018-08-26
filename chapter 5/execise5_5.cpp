#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> words;
const int maxn = 120000+10;
map<string, int> hasword;

int main(){
        string str;
        while(cin>>str){
                words.push_back(str);
                hasword[str] = 1;
        }
        for(int i=0;i<words.size();i++){
                for(int j=1;j<words[i].length();j++){
                        string x1 = words[i].substr(0,j);
                        string x2 = words[i].substr(j);
                        if(hasword.count(x1)&&hasword.count(x2)){
                                cout << words[i] << endl;
                                break;
                        }
                }
        }
        return 0;
}
