#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

struct Book{
        string name, author;
        bool operator < (const Book &b) const{
                if(author==b.author)
                        return name < b.name;
                else
                        return author < b.author;
        }
};

vector<Book> books;
map<string, int> ID;
vector<int> borrowed;
vector<Book> returned;

int main(){
        string str;
        int nums = 0;
        while(getline(cin, str)){
                if(str=="END") break;
                int it = str.find(" by ");
                struct Book a;
                a.name = str.substr(0, it);
                a.author = str.substr(it+4);
                books.push_back(a);
        }
        sort(books.begin(), books.end());
        for(int i=0;i<books.size();i++){
                ID[books[i].name] = i;
                borrowed.push_back(1);
        }
        /*for(int i=0;i<books.size();i++)
                cout << books[i].author << " " << books[i].name << endl;*/
        while(getline(cin, str)){
                if(str=="END") break;
                if(str=="SHELVE"){
                        sort(returned.begin(), returned.end());
                        for(int i=0;i<returned.size();i++){
                                if(ID[returned[i].name]==0)
                                        cout<<"Put "<<returned[i].name<<" first\n";
                                for(int j=ID[returned[i].name]-1;j>=0;j--){
                                        if(borrowed[j]){
                                                cout<<"Put "<<returned[i].name<<" after "<<books[j].name<<"\n";
                                                break;
                                        }
                                        if(!j)
                                                cout<<"Put "<<returned[i].name<<" first\n";
                                }
                                borrowed[ID[returned[i].name]] = 1;
                        }
                        returned.clear();
                        cout<<"END\n";
                }else{
                        int it=str.find(" ");
                        string cmd = str.substr(0,it);
                        string book_name = str.substr(it+1);
                        if(cmd=="BORROW")
                                borrowed[ID[book_name]] = 0;
                        else
                                returned.push_back(books[ID[book_name]]);
                }
        }
        return 0;
}
