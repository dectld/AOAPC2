#include <stdio.h>
#define maxn 15

int d[6][6] = {{0,1,2,3,4,5},{1,5,2,3,0,4},{2,1,5,0,4,3},
                {3,1,0,5,4,2},{4,0,2,3,5,1},{5,1,3,2,4,0}};
char s[maxn], s1[maxn], s2[maxn];

void run(){
        int t=s2[1];
        s2[1] = s2[3];
        s2[3] = s2[4];
        s2[4] = s2[2];
        s2[2] = t;
}

int compare(){
        for(int i=0;i<6;i++){
                if(s1[i]!=s2[i]) return 0;
        }
        return 1;
}

int main(){
        while(scanf("%s",s)==1){
                for(int i=0;i<6;i++){
                        s1[i] = s[i];
                }
                int f = 0;
                for(int i=0; i<6; i++){
                        for(int j=0; j<6; j++){
                                s2[j] = s[6+d[i][j]];
                        }
                        for(int k=0;k<4;k++){
                                run();
                                if(compare()) f = 1;
                        }
                        if(f) break;
                }
                if(f) printf("TRUE\n");
                else printf("FALSE\n");
        }
        return 0;
}
