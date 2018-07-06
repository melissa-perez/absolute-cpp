#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int T=0,O=0,G=0,D=0;

    while(T<=9){
        if(O==10){O=0;}
        while(O<=9){
            if(G==10){G=0;}
            while(G<=9){
                if(D==10){D=0;}
                while(D<=9){
                    if(((D!=G)&&(D!=O)&&(D!=T)&&(G!=O)&&(G!=T)&&(G!=D)
                        &&(O!=D)&&(O!=T)&&(O!=G)&&(T!=D)&&(T!=O)&&(T!=G))&&(4*(T*100+O*10+O*1)==(G*1000+O*100+O*10+D*1))){
                    cout<<"T: "<<T<<" O: "<<O<<" G: "<<G<<" D: "<<D<<endl;
                    }
                    D++;
                    if((T==9)&&(O==9)&&(D==9)&&(G==9)){break;}
                 }
                 if((T==9)&&(O==9)&&(D==9)&&(G==9)){break;}
                 G++;
                }
            if((T==9)&&(O==9)&&(D==9)&&(G==9)){break;}
            O++;
            }
        if((T==9)&&(O==9)&&(D==9)&&(G==9)){break;}
        T++;
    }







    return 0;
}
