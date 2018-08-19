#include <iostream>
#include <vector>
using namespace std;

const int MAX_SUITORS=101;
int main(int argc, char *argv[])
{
    for(int i=1;i<MAX_SUITORS;i++)
    {
        int numberOfSuitors=i;
        int count=0;
        vector<int> suitors(numberOfSuitors);

        for(int i=0;i<numberOfSuitors;i++)suitors[i]=(i+1);
        //can also use push_back

        for(unsigned int i=0;i<suitors.size();i++)
        {
            count+=1;
            if(suitors.size()==1)break;
            if(count==3)
            {
                suitors.erase(suitors.begin()+i);
                suitors.resize(suitors.size());
                count=0;
                i-=1;
            }
            if(i==(suitors.size()-1))
            {
                i=-1;
            }
        }
        cout<<"The lucky suitor for Eve in a group size of "<<numberOfSuitors<<" suitors is "<<suitors[0]<<endl;
    }
    return 0;
}
