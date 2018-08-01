#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    double time = 0.00;
    double hours = 0.00;
    double mins = 0.00;
    double secs = 0.00;
    double intpart = 0.00;
    double fractpart = 0.00;

    cout<<"Enter the seconds to convert: ";
    cin>>time;

    time=time/3600;
   if(floor(time) >=1){
        fractpart = modf(time,&intpart);
        hours=intpart;
        mins = fractpart*60;
        fractpart=modf(mins,&intpart);
        mins=intpart;
        secs=fractpart*60;
    }
   else{
       time = time*60;
       fractpart = modf(time,&intpart);
       mins=intpart;
       secs=fractpart;
   }

    cout<<"This is "<<hours<<" hour(s), "<<mins<<" minute(s), and "
       <<secs<<" second(s). "<<endl;
    return 0;
}
