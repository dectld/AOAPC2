#include <stdio.h>
#include <string.h>
#define maxn 1000

int H[maxn][maxn], V[maxn][maxn];
int n;

int get_square(int line){
        //printf("%d\n",line);
        int num = 0;
        for(int i=1;i<=n-line;i++){
                for(int j=1;j<=n-line;j++){
                        int f=1;
                        for(int k=0;k<line;k++){
                                if((!H[i][j+k]) || (!H[i+line][j+k]) || (!V[i+k][j]) || (!V[i+k][j+line])){
                                        f = 0; break;
                                }
                        }
                        if(f) num++;
                }
        }
        return num;
}

int main(){
        int m, kase=0;
        while(scanf("%d%d",&n,&m)==2){
                memset(H, 0, sizeof(H));
                memset(V, 0, sizeof(V));
                char type[3];
                int r,c;
                //printf("n=%d m=%d\n",n,m);
                for(int i=0;i<m;i++){
                        scanf("%s", type);
                        scanf("%d%d", &r,&c);
                        //printf("type=%c, r=%d c=%d\n",type[0],r,c);
                        if(type[0]=='H') H[r][c] = 1;
                        else V[c][r] = 1;
                }
                /*
                printf("H\n");
                for(int i=1;i<=n;i++){
                        for(int j=1;j<=n;j++)
                                printf("%3d",H[i][j]);
                        printf("\n");
                }
                printf("V\n");
                for(int i=1;i<=n;i++){
                        for(int j=1;j<=n;j++)
                                printf("%3d",V[i][j]);
                        printf("\n");
                }*/

                if(kase) printf("\n**********************************\n\n");
                printf("Problem #%d\n\n",++kase);
                int f=1;
                for(int i=1; i<=n; i++){
                        if(get_square(i)){
                                printf("%d square (s) of size %d\n",get_square(i), i);
                                f = 0;
                        }
                }
                if(f) printf("No completed squares can be found.\n");
        }
        return 0;
}
