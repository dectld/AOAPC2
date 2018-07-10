#include <stdio.h>
#define maxn 100
#include <string.h>
#include <ctype.h>


double getmol(char ch){
        if(ch == 'C') return 12.01;
        if(ch == 'H') return 1.008;
        if(ch == 'O') return 16.00;
        if(ch == 'N') return 14.01;
}

int main(){
        int T;
        scanf("%d", &T);
        char s[maxn];
        while(T--){
                scanf("%s", s);
                int n = strlen(s);
                double mol, sum=0;
                for(int i=0;i<n;i++){
                        if(isalpha(s[i])){
                                mol = getmol(s[i]);
                                int c = 0;
                                //printf("%c %f\n",s[i],mol);
                                for(int j=i+1;j<n&&isdigit(s[j]);j++){
                                        c = 10*c + (s[j] - '0');
                                }
                                if(c==0) c=1;
                                //printf("%c %d\n", s[i],c);
                                sum += mol*c;
                                //printf("%f\n", sum);
                        }
                }
                printf("%.3f\n", sum);
        }
        return 0;
}
