#include <stdio.h>
#define maxn 200
#include <string.h>

int main(){
        int n;
        scanf("%d",&n);
        char s[maxn];
        while(n--){
                scanf("%s", s);
                int c = 0, sum=0;
                for(int i=0; i<strlen(s);i++){
                        if(s[i]=='O'){
                                sum += (++c);
                        }else{
                                c = 0;
                        }
                }
                printf("%d\n",sum);
        }
        return 0;
}
