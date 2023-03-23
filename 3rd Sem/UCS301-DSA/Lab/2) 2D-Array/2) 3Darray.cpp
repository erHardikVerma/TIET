#include<iostream>
using namespace std;
class arrayrotation
{
    int n;
    int ***arr;
    arrayrotation(int size)
    {
        n=size;
        this->arr=new int[size][size][size];
    }
    void input(int n)
    {
        
    }
    public:
   void print(int ***arr,int n)
   {
    //Printing the 3d Array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout<<arr[i][j][k]<<" ,";
            }
   
        }

    }

   }
};

int main()
{
    arrayrotation obj;
    int n;
    cout<<"Enter the size of the araay: "<<endl;
    cin>>n;
    //i is for the plane
    //j is for the rows
    //k is for the column
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin>>arr[i][j][k];
            }
            
        }
        
    }
    obj.print(&arr,n);

    
}
