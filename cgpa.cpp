#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int sub;
    float percentage,cg,marks,total=0,maxmarks;    
    cout<<"Number of subjects you want to Calculate the CGPA of \n";
    cin>> sub;
    cout<< "Enter the overall marks that a student can take (combination of all subjects) \n";
    cin>> maxmarks;
    for (int i = 1; i <= sub; i++)
    {
        cout<< "Enter the marks of subject "<< i <<"\n";
        cin>> marks;
        total=total+marks;
    }
    cout<< "Total marks obtained " <<total <<"\n";
    if (maxmarks<total)
    {
        cout<<"Invalid Data";
    }
    else
    {
        percentage= (total/maxmarks)*100;
        cg= (percentage/9.5);
        cout<<fixed<<setprecision(2)<<"Your Percentage "<<percentage<<"% \n";
        cout<<fixed<<setprecision(2)<<"Your CGPA "<< cg <<"\n";
    }

    
 

}
