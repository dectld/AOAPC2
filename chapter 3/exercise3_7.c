#include <stdio.h>
#define maxm 100
#define maxn 1010
#include <string.h>


int main(){
        int T;
        scanf("%d", &T);
        while(T--){
                //printf("start\n");
                int m,n;
                scanf("%d %d",&m,&n);
                getchar();
                char s[maxm][maxn];
                for(int i=0; i<m; i++){
                        scanf("%s", s[i]);
                        getchar();
                }
                char s1[maxn];
                char s2[] = "TGCA";
                //printf("%s\n",s2);
                memset(s1, '\0', sizeof(s1));

                //printf("%d %d\n", m, n);
                int total = 0;
                for(int j=0; j<n; j++){
                        int min = m, sum;
                        for(int k=0; k<strlen(s2); k++){
                                sum=0;
                                for(int i=0; i<m; i++){
                                        if(s2[k]!=s[i][j]) sum++;
                                }
                                if(sum<=min){
                                        min = sum;
                                        s1[j] = s2[k];
                                }
                        }
                        total += min;
                        //printf("%d %c\n",j, s1[j]);
                }
                printf("%s\n", s1);
                printf("%d\n",total);
        }
        return 0;
}
