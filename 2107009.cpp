#include <iostream>
#include <string>

using namespace std;

class movieSystem;
class addRating;
class movies;

class movies
{

    string director_name;
    int release_date;
    string language;
    double rating;
public:
    movies()
    {
        ;
    }
    string name;
    movies(string aName, string dName,int aRelease_date,string aLanguage,double aRating)
    {
        name=aName;
        director_name=dName;
        release_date=aRelease_date;
        language=aLanguage;
        rating=aRating;
    }
    void display_movie()
    {
        cout<<"*"<<endl;
        cout<<"Movie: "<<name<<endl;
        cout<<"Director: "<<director_name<<endl;
        cout<<"Release Date: "<<release_date<<endl;
        cout<<"Language: "<<language<<endl;
        cout<<"Rating: "<<rating<<endl;
      }
    friend void search_movie(movieSystem &k,string name);
    friend class addRating;
};

 class movieSystem
{
public:
    movies n[1000];

    movieSystem()
    {}
    int num_of_movies{0};
    void add();
    void displayall();
    friend void search_movie(movieSystem &k,string aname);
    friend class addRating;
};
 void movieSystem:: displayall()
    {
        int i;
        for(i=0; i<num_of_movies; i++)
        {
            n[i].display_movie();
        }
        cout<<"==========="<<endl;
        cout<<"Total Number of Movies in Database: "<<num_of_movies<<endl;
    }
void movieSystem:: add()
    {
        cin.ignore();
        string aName;
        cout<<"Movie name: ";
        getline(cin,aName);
        string dName;
        cout<<"Director: ";
        getline(cin,dName);
        int aRelease_date;
        cout<<"Release Date: ";
        cin>>aRelease_date;
        cin.ignore();
        string aLanguage;
        cout<<"Language: ";
        getline(cin,aLanguage);
        double aRating;
        cout<<"Rating(out of 5): ";
        cin>>aRating;
        n[num_of_movies]=movies(aName,dName,aRelease_date,aLanguage,aRating);
        num_of_movies++;

    }

void search_movie(movieSystem &k,string aname)
{
    int i,x=0;
    for(i=0; i<k.num_of_movies; i++)
    {
        if(aname==k.n[i].name)
        {
            x=1;
            break;
        }
    }
    if(x==1)
    {
        cout<<"=========="<<endl;
        cout<<"Availability: Yes"<<endl;
        k.n[i].display_movie();
    }
    else
    {
        cout<<"=========="<<endl;
        cout<<"Availability: This movie is not available in the database right now."<<endl;
    }

}

class user
{
    int age;
public:
    int id;
    user() {}
    void add_id(int aId,int aAge)
    {
        id=aId;
        age=aAge;
    }

};

class addRating
{
    double aRating;
public:
    user u[100];
    addRating()
    {

    }
    void AddRating(movieSystem &k,string &sName);
};
void addRating :: AddRating(movieSystem &k,string &sName)
    {
        int i,x=0;
            for(i=0; i<k.num_of_movies; i++)
            {
                if(k.n[i].name==sName)
                {
                    x=1;
                    break;
                }
            }
            if(x==1)
            {
                cout<<"Availability:Yes"<<endl;
                double sRating;
                cout<<"Rate (out of 5):";
                cin>>sRating;
                k.n[i].rating=(k.n[i].rating+sRating)/2;
                cout<<"=========="<<endl;
                cout<<"The present details:"<<endl;
                k.n[i].display_movie();
            }
            else
            {
                cout<<"Availability:Not Available at this moment."<<endl;
            }
        }


    int main()
    {
        cout<<"Welcome to MDB"<<endl;
        movieSystem k;
        addRating l;
        char ch;
        cout<<"Do you want to add movie?(Y/N)";
        cin>>ch;
        while(ch=='Y'||ch=='y')
        {
            k.add();
            cout<<"Do you want to add movie?(Y/N)";
            cin>>ch;
        }
        cout<<"=========="<<endl;
        cout<<"Data of all movies: "<<endl;
        k.displayall();
        cout<<"=========="<<endl;
        string sName;
        char ch1;
        cout<<"Do you want to search movie?(Y/N)";
        cin>>ch1;
        while(ch1=='Y'||ch1=='y')
        {
            cin.ignore();
            cout<<"Search movie by name:";
            getline(cin,sName);
            search_movie(k,sName);
            cout<<"Do you want to search again?(Y/N)";
            cin>>ch1;

        }


        cout<<"Do you want to rate?(Y/N)";
        char ch2;
        cin>>ch2;
        string mName;
        while(ch2=='Y'||ch2=='y')
        {
            cout<<"Do you have an id?(Y/N)";
            char ch3;
            cin>>ch3;
            int aId;
            int i;
            int f=0;
            if(ch3=='Y'||ch3=='y')
            {

                cout<<"Enter id:";
                cin>>aId;
                for(i=0; i<100; i++)
                {
                    if(aId==l.u[i].id)
                    {
                        f=1;
                        break;
                    }

                }
                if(f==1)
                {
                    cin.ignore();
                    cout<<"Which Movie do you want to rate?";
                    getline(cin,mName);
                    l.AddRating(k,mName);
                    cout<<"Do you want to rate again?(Y/N)";
                    cin>>ch2;
                }
                else if(f==0)
                {
                    cout<<"Sorry Id was not found."<<endl;
                    cout<<"Please create one."<<endl;
                    int age;
                    cout<<"Id number:";
                    cin>>aId;
                    cout<<"Age:";
                    cin>>age;
                    cout<<"You can rate now."<<endl;
                    cin.ignore();
                    cout<<"Which Movie do you want to rate?";
                    getline(cin,mName);
                    l.AddRating(k,mName);
                    cout<<"Do you want to rate again?(Y/N)";
                    cin>>ch2;

                }


            }
            else if(ch3=='N'||ch3=='n')
            {
                int i=0,j=0;

                cout<<"Please create one."<<endl;
                cout<<"Id number:";
                cin>>aId;
                int age;
                cout<<"Age:";
                cin>>age;
                l.u[j].add_id(aId,age);
                j++;
                cout<<"You can rate now."<<endl;
                cin.ignore();
                cout<<"Which Movie do you want to rate?";
                getline(cin,mName);
                l.AddRating(k,mName);
                cout<<"Do you want to rate again?(Y/N)";
                cin>>ch2;
                i++;

            }

        }
        if(ch2=='N'||ch2=='n')
        {
            cout<<"========="<<endl;
            cout<<"Thanks for choosing us."<<endl;
        }

    }
