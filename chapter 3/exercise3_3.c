#include <stdio.h>
#include <string.h>
#define maxn 10000 + 100

int main(){
        int T;
        scanf("%d", &T);
        while(T--){
                int N, a[10];
                scanf("%d",&N);
                memset(a, 0, sizeof(a));
                for(int i=1; i<=N; i++){
                        int x=i;
                        while(x>0){
                                a[x%10]++;
                                x /= 10;
                        }
                }
                for(int i=0;i<10;i++){
                        if(i) printf(" ");
                        printf("%d", a[i]);
                }
                printf("\n");
        }
        return 0;
}
