#include <iostream>
#include <iomanip>
#include <cmath>


//There are no functions to check if the input is correct.
using namespace std;

void userReviews(int userMovies[3],int userRatings[3]);
void nearestNeighbor(int knn[4][3],int userMovies[3],int userRatings[3],const int movieReviews[4][6],int&reviewer);
void predict(int reviewer,const int movieReviews[4][6],int userMovies[3]);

int main(int argc, char *argv[])
{
    int movieReviews[4][6]={3,1,5,2,1,5,
                            4,2,1,4,2,4,
                            3,1,2,4,4,1,
                           5,1,4,2,4,2};
    int userMovies[3]={0},userRatings[3]={0};
    int knn[4][3]={0};
    int reviewer=-1;

    cout<<setw(5)<<100<<" "<<101<<" "<<102<<" "<<103<<" "<<" "<<104<<" "<<105<<endl;

    for(int i=0;i<4;i++)
    {
        cout<<setw(1)<<i<<" ";
        for(int j=0;j<6;j++){
            cout<<setw(3)<<movieReviews[i][j]<<" ";
        }
        cout<<endl;
    }

    userReviews(userMovies,userRatings);
    nearestNeighbor(knn,userMovies,userRatings,movieReviews,reviewer);
    predict(reviewer,movieReviews,userMovies);

    return 0;
}


void userReviews(int userMovies[3], int userRatings[3])
{
    int movieNumber=0;

    for(int i=0;i<3;i++)
    {
        cout<<"Enter the "<<i+1<<" movie you want to review from numbers(100-106): ";
        cin>>movieNumber;
        userMovies[i]=movieNumber-100;

        cout<<"\nEnter the rating for movie "<<movieNumber<<" (1(bad)-5(good)): ";
        cin>>userRatings[i];
    }
}
void nearestNeighbor(int knn[4][3],int userMovies[3], int userRatings[3],const int movieReviews[4][6],int&reviewer)
{
    int min=100;
    for(int i=0;i<3;i++)
    {
        int col=userMovies[i];
        int rating=userRatings[i];
        for(int j=0;j<4;j++)
        {
            knn[j][i]=pow(rating-movieReviews[j][col],2);
        }
    }

    for(int i=0;i<4;i++)
    {
        int sum=0;
        for(int j=0;j<3;j++)
        {
            sum+=knn[i][j];
        }
        if(sum<min)
        {
            min=sum;
            reviewer=i;
        }
    }
}

void predict(int reviewer, const int movieReviews[4][6], int userMovies[3])
{
    int otherFilms[3]={0},film=-1,i=0,index=0;

    while(i<6)
    {
        int j=0;
        while(j<3)
        {
            if(i!=userMovies[j])
            {
                film=i;
            }

            else{
                film=-1;
                break;
           }
            j++;
        }

        if(film!=-1)
        {
            otherFilms[index]=film;
            index+=1;
        }
           i++;
   }

    cout<<"\nYou matched closest with reviewer "<<reviewer<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"\nWe predict that for movie "<<otherFilms[i]+100<<" your interest is: "<<movieReviews[reviewer][otherFilms[i]]<<endl;

    }

}
