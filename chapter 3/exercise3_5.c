#include <stdio.h>
#include <string.h>
#define maxn 20

int main(){
        int n = 5;
        int kase = 0;
        while(1){
                char s[maxn][maxn];
                for(int i=0;i<maxn;i++){
                        for(int j=0;j<maxn;j++){
                                s[i][j] = '\0';
                        }
                }

                int ch,n1=0,n2=1;
                if(kase) s[0][0] = ' ';
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                //printf("%d\n",j);
                                if((ch=getchar())=='\n'){
                                        if(j==1&&s[0][0]=='Z'){
                                                n2 = 0;
                                                break;
                                        }
                                        j--;
                                }else{
                                        s[i][j] = ch;
                                }
                        }
                        if(!n2) break;
                }
                if(n2==0){
                        break;
                }

                int x,y;
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                if(s[i][j]==' '){
                                        x = i;
                                        y = j;
                                }
                        }
                }
                int c, f=1;
                while((c=getchar())!='0'){
                        if(c=='A'&&f){
                                if(x-1<0){
                                        f = 0;
                                }else{
                                        s[x][y] = s[x-1][y];
                                        s[--x][y] = ' ';
                                }
                        }
                        if(c=='B'&&f){
                                if(x+1>=n){
                                        f = 0;
                                }else{
                                        s[x][y] = s[x+1][y];
                                        s[++x][y] = ' ';
                                }
                        }
                        if(c=='L'&&f){
                                if(y-1<0){
                                        f=0;
                                }else{
                                        s[x][y] = s[x][y-1];
                                        s[x][--y] = ' ';
                                }
                        }
                        if(c=='R'&&f){
                                if(y+1>=n){
                                        f=0;
                                }else{
                                        s[x][y] = s[x][y+1];
                                        s[x][++y] = ' ';
                                }
                        }
                }
                if(kase) printf("\n");
                printf("Puzzle #%d:\n", ++kase);
                if(f){
                        for(int i=0;i<n;i++){
                                for(int j=0; j<n;j++){
                                        if(j) printf(" ");
                                        printf("%c", s[i][j]);
                                }
                                printf("\n");
                        }
                }else{
                        printf("This puzzle has no final configuration.\n");
                }

        }
        return 0;
}
