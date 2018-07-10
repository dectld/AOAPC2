#include <stdio.h>
#define maxn 4000
#include <string.h>

int main(){
        int a,b;
        int s1[maxn], s2[maxn];
        while(scanf("%d %d", &a, &b)==2&&b){
                memset(s1,0,sizeof(s1));
                memset(s2,0,sizeof(s2));
                s1[0] = a/b;
                s2[0] = a%b;
                int c=0, m=0;
                while(1){
                        //printf("ss\n");
                        c++;
                        s1[c] = s2[c-1]*10/b;
                        s2[c] = s2[c-1]*10%b;
                        for(int i=0;i<c;i++){
                                if(s2[c]==s2[i]){
                                        m = i+1;
                                        break;
                                }
                        }
                        if(m) break;
                }
                printf("%d/%d = %d.",a,b,s1[0]);
                for(int i=0;i<c;i++){
                        if(i+1==m) printf("(");
                        if(i==50){
                                printf("...");
                                break;
                        }
                        printf("%d",s1[i+1]);
                }
                printf(")\n   %d = number of digits in repeating cycle\n\n", c-m+1);
        }
        return 0;
}
