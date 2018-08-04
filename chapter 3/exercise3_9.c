#include <stdio.h>
#include <string.h>
#define maxn 100000
char s[maxn], t[maxn];

int main(){
        while(scanf("%s%s",s,t)==2){
                int index=0;
                for(int i=0; i<strlen(t);i++){
                        if(t[i] == s[index])
                                index++;
                }
                if(index==strlen(s)){
                        printf("Yes\n");
                }else{
                        printf("No\n");
                }
        }
        return 0;
}
