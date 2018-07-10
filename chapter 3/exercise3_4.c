#include <stdio.h>
#define maxn 100
#include <string.h>


int main(){
        int N;
        scanf("%d",&N);
        //printf("\n");
        while(N--){
                char s[maxn];
                scanf("%s", s);
                //if(N) printf("\n");
                int n = strlen(s);
                for(int i=1;i<=n;i++){
                        int f = 1;
                        for(int j=0;j<i;j++){
                                int c=1, x;
                                while((x=j+c*i)<n){
                                        if(s[j] != s[x]){
                                                f = !f;
                                                break;
                                        }
                                        c++;
                                }
                                if(!f) break;
                        }
                        if(f&&n%i==0){
                                printf("%d\n",i);
                                if(N){
                                        printf("\n");
                                }
                                break;
                        }
                }
        }
        return 0;
}
