#include <stdio.h>
#include <string.h>

int a[6][2];
int b[3];
int main(){
        while(scanf("%d%d", &a[0][0], &a[0][1])!=EOF){
                for(int i=1; i<6; i++){
                        scanf("%d%d", &a[i][0], &a[i][1]);
                }
                memset(b, 0, sizeof(b));
                for(int i=0;i<6;i++){
                        if(a[i][0]>a[i][1]){
                                int t = a[i][0];
                                a[i][0] = a[i][1];
                                a[i][1] = t;
                        }
                }
                for(int i=0;i<6;i++){
                        for(int j=i+1;j<6;j++){
                                if(a[i][0] > a[j][0]){
                                        int t1 = a[i][0], t2=a[i][1];
                                        a[i][0] = a[j][0]; a[i][1] = a[j][1];
                                        a[j][0] = t1; a[j][1] = t2;
                                }
                                if(a[i][0]==a[j][0]){
                                        if(a[i][1] > a[j][1]){
                                                int t3 = a[i][0], t4=a[i][1];
                                                a[i][0] = a[j][0]; a[i][1] = a[j][1];
                                                a[j][0] = t3; a[j][1] = t4;
                                        }
                                }
                        }
                }
                int f = 1, b[12], k=0;
                for(int i=0; i<6; i++)
                        for(int j=0; j<2; j++)
                                b[k++] = a[i][j];
                for(int i=0; i<k; i++){
                        for(int j=i+1; j<k; j++){
                                if(b[i]>b[j]){
                                        int t = b[i]; b[i] = b[j]; b[j] = t;
                                }
                        }
                }
                /*for(int i=0; i<6; i++){
                        for(int j=0; j<2; j++){
                                printf("%d ", a[i][j]);
                        }
                        printf("\n");
                }
                for(int i=0; i<k; i++){
                        printf("%d ", b[i]);
                }
                printf("\n");*/
                for(int i=0; i<3;i++){
                        if(a[2*i][0]!=a[2*i+1][0]||a[2*i][1]!=a[2*i+1][1]){
                                //printf("1\n");
                                f = 0; break;
                        }
                        for(int j=1;j<=3;j++){
                                if(b[4*i]!=b[4*i+j]){
                                        //printf("2\n");
                                        f = 0; break;
                                }
                        }
                }
                if(f) printf("POSSIBLE\n");
                else printf("IMPOSSIBLE\n");
        }
        return 0;
}
