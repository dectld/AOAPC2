#include <stdio.h>
#define maxn 100

int main(){
        int kase = 0;
        while(1){
                int r, c;

                scanf("%d", &r);
                if(r == 0) break;
                scanf("%d", &c);
                getchar();
                char s[maxn][maxn];
                for(int i=0; i<r;i++){
                        scanf("%s", s[i]);
                        getchar();
                }

                int n=0, n1=0, n2=0;
                int across_x[maxn], across_y[maxn], down_x[maxn], down_y[maxn];
                int across[maxn], down[maxn];
                for(int i=0; i<r; i++){
                        for(int j=0; j<c; j++){
                                if(s[i][j]!='*'){
                                        if(i==0||j==0||s[i][j-1]=='*'||s[i-1][j]=='*'){
                                                ++n;
                                                if(i==0||s[i-1][j]=='*'){
                                                        down[n2] = n;down_x[n2] = i;down_y[n2++] = j;
                                                }
                                                if(j==0||s[i][j-1]=='*'){
                                                        across[n1] = n;across_x[n1] = i;across_y[n1++] = j;
                                                }
                                        }
                                }
                        }
                }
                char s1[maxn][maxn], s2[maxn][maxn];
                for(int i=0;i<maxn;i++){
                        for(int j=0;j<maxn;j++){
                                s1[i][j] = '\0';
                                s2[i][j] = '\0';
                        }
                }
                if(kase) printf("\n");
                printf("puzzle #%d:\n", ++kase);
                printf("Across\n");
                for(int i=0; i<n1; i++){
                        int end = c;
                        for(int j=across_y[i]; j<c; j++){
                                if(s[across_x[i]][j] == '*'){
                                        end = j;
                                        break;
                                }
                        }
                        for(int j=across_y[i]; j<end; j++){
                                s1[i][j-across_y[i]] = s[across_x[i]][j];
                        }
                        printf("%3d.%s\n", across[i], s1[i]);
                }
                printf("Down\n");
                for(int i=0; i<n2; i++){
                        int end = r;
                        for(int j=down_x[i]; j<r; j++){
                                if(s[j][down_y[i]] == '*'){
                                        end = j;
                                        break;
                                }
                        }
                        for(int j=down_x[i]; j<end; j++){
                                s2[i][j-down_x[i]] = s[j][down_y[i]];
                        }
                        printf("%3d.%s\n", down[i], s2[i]);
                }

        }
        return 0;
}
