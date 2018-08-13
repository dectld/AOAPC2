#include <stdio.h>
#define maxn 20

struct piece{
        char s[5];
        int r,c;
}p[maxn];

int n;

int get_num(char type, int r1, int c1, int r0, int c0){
        int count = 0;
        int minr=r0, maxr=r1, minc=c0, maxc=c1;
        if(r1<r0){minr=r1; maxr=r0;}
        if(c1<c0){minc=c1; maxc=c0;}
        for(int i=0; i<n; i++){
                int r2=p[i].r, c2=p[i].c;
                if(type=='r'&&r2==r0&&c2>minc&&c2<maxc) count++;
                if(type=='c'&&c2==c0&&r2>minr&&r2<maxr) count++;
        }
        return count;
}

int horse_dr[8] = {-2,-1,1,2,2,1,-1,-2};
int horse_dc[8] = {1,2,2,1,-1,-2,-2,-1};
int drs[8] = {-1,0,0,1,1,0,0,-1};
int dcs[8] = {0,1,1,0,0,-1,-1,0};
int run(int r0, int c0){
        for(int i=0; i<n; i++){
                char name = p[i].s[0];
                int r1=p[i].r, c1=p[i].c;
                if(r1!=r0||c1!=c0){
                        if(name=='G'&&c1==c0)
                                if(!get_num('c', r1, c1, r0, c0)) return 1;
                        if(name=='R'){
                                if(r1==r0){
                                        if(!get_num('r',r1,c1,r0,c0)) return 1;
                                }
                                if(c1==c0){
                                        if(!get_num('c',r1,c1,r0,c0)) return 1;
                                }
                        }
                        if(name=='C'){
                                if(r1==r0){
                                        if(get_num('r',r1,c1,r0,c0)==1) return 1;
                                }
                                if(c1==c0){
                                        if(get_num('c',r1,c1,r0,c0)==1) return 1;
                                }
                        }
                        if(name=='H'){
                                for(int j=0;j<8;j++){
                                        if(r1-r0==horse_dr[j]&&c1-c0==horse_dc[j]){
                                                int f=1;
                                                for(int k=0;k<n;k++){
                                                        int r2=p[k].r, c2=p[k].c;
                                                        if(r1-r2==drs[j]&&c1-c2==dcs[j]){f=0;break;}
                                                }
                                                if(f) return 1;
                                        }
                                }
                        }
                }
        }
        return 0;
}

int main(){
        int r0,c0;
        while(scanf("%d%d%d",&n,&r0,&c0)==3&&n){
                for(int i=0; i<n; i++)
                        scanf("%s%d%d",p[i].s, &p[i].r, &p[i].c);
                int f=1;
                //printf("r0=%d, c0=%d\n",r0,c0);
                if(r0-1>0&&!run(r0-1,c0)) f=0;//{f=0; printf("step1 wrong\n");}
                if(r0+1<4&&!run(r0+1,c0)) f=0;//{f=0; printf("step2 wrong\n");}
                if(c0-1>3&&!run(r0,c0-1)) f=0;//{f=0; printf("step3 wrong\n");}
                if(c0+1<7&&!run(r0,c0+1)) f=0;//{f=0; printf("step4 wrong\n");}
                if(f) printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}
