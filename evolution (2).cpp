#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<cstdlib>

#define N 100
#define M 50
#define pm 0.15
using namespace std;

struct osob{
    int g[4];
    double f;
    double p;
};

struct osob pr[N];
struct osob pot[6*M];
int pt;

struct osob resh[100];
int nr=0;
double sf=0,sp=0;
double ver[N+1];

void killWeak(struct osob *a){
        for(int i=0;i<6*M;i++){
            if(i>=N){
                for(int j=0;j<4;j++)
                    a[i].g[j]=0;
                a[i].f=0;
                a[i].p=0;
            }

        }
}

void nachPop(void){
    int i=0;
    while(i<N){
        for(int j=0;j<4;j++)
           pr[i].g[j]=rand()%100;
        int zn=abs(pr[i].g[0] + 2*pr[i].g[1] + 3*pr[i].g[2] + 4*pr[i].g[3]-300);
        if(zn==0){
           for(int jj=0;jj<4;jj++){
              resh[nr].g[jj]=pr[i].g[jj];
           }
           nr++;
        }
        else {
           pr[i].f=1./abs(zn);
           sf+=pr[i].f;
           i++;
        }
    }
    for(int i=0;i<N;i++){
        ver[i]=sp;
        pr[i].p=pr[i].f/sf;
        sp+=pr[i].p;
    }
    ver[N]=1;

}

void printMass(struct osob *m, int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<4;j++)
           cout<<m[i].g[j]<<' ';
        cout<<m[i].f<<' '<<m[i].p<<endl;
    }
}

void skreschivaem(void){
    int nommam,nomdad;
    for(int i=0;i<M;i++){
        double dad=rand()/(double)RAND_MAX;
        for(int j=1;j<N+1;j++){
            if(dad<=ver[j] && dad>ver[j-1]){
                nomdad=j;
            }
        }
        double mom=rand()/(double)RAND_MAX;
        for(int j=1;j<N+1;j++){
            if(mom<=ver[j] && mom>ver[j-1]){
                nommam=j;
            }
        }
        for(int k=1;k<4;k++){
            for(int i=0;i<k;i++)
              pot[pt].g[i]=pr[nommam].g[i];
            for(int i=k;i<4;i++)
              pot[pt].g[i]=pr[nomdad].g[i];
            int zn=abs(pot[pt].g[0] + 2*pot[pt].g[1] + 3*pot[pt].g[2] + 4*pot[pt].g[3]-300);
            if(zn==0){
               for(int jj=0;jj<4;jj++){
                  resh[nr].g[jj]=pot[pt].g[jj];
              }
              nr++;
              pot[pt].f=0;
           }
           else {
             pot[pt].f=1./abs(zn);

          }
          pt++;
           for(int i=0;i<k;i++)
              pot[pt].g[i]=pr[nomdad].g[i];
            for(int i=k;i<4;i++)
              pot[pt].g[i]=pr[nommam].g[i];
            zn=abs(pot[pt].g[0] + 2*pot[pt].g[1] + 3*pot[pt].g[2] + 4*pot[pt].g[3]-300);
            if(zn==0){
               for(int jj=0;jj<4;jj++){
                  resh[nr].g[jj]=pot[pt].g[jj];
              }
              nr++;
              pot[pt].f=0;
           }
           else {
             pot[pt].f=1./abs(zn);

          }
          pt++;
         }
    }
}

bool menshe(struct osob a, struct osob b){
    if(a.f<b.f) return true;
    else return false;
}

int main()
{
    srand(time(NULL));
    //int det=0;
    nachPop();
    //printMass(pr,N);
    //cout<<"resh"<<endl;
    //printMass(resh,nr);
    for(int k=0;k<M;k++){
        skreschivaem();
    }
    sort(pot,pot+6*M,menshe);

    //cout<<"resh"<<endl;
    //printMass(resh,nr);
    killWeak(pot);
    cout<<"pot"<<endl;
    printMass(pot,6*M);
    return 0;
}
