#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
        int n;
        while(scanf("%d",&n)==1&&n){
                queue<int> cards;
                for(int i=1;i<=n;i++) cards.push(i);
                printf("Discarded cards:");
                for(int i=0;i<n-1;i++){
                        int x1 = cards.front(); cards.pop();
                        int x2 = cards.front(); cards.pop();
                        cards.push(x2);
                        printf(" %d",x1);
                        if(i<n-2) printf(",");
                }
                printf("\n");
                printf("Remaining card: %d\n",cards.front());
        }
        return 0;
}
