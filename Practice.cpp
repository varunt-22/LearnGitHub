#include "ArrayADT.cpp"
#include<iostream>
using namespace std;

class ExtendedArray:public Array
{
    public:
        ExtendedArray(int);
        void sort();
        int greatest();
        int smallest();
        int search(int);
        int sum();
        float average();
        void rotateByOnePosition();
        int getCapacity();
        void removeDuplicate();
        int secondLargest();
        void swap(int,int);
};
void ExtendedArray::swap(int i, int j)
{
    int temp;
    temp=get(i);
    edit(i,get(j));
    edit(j,temp);

}
int ExtendedArray::secondLargest()
{
    int r,i,temp;
    for(r=1;r<=2;r++)
        for(i=0;i<=count()-1-r;i++)
            if(get(i)>get(i+1))
            {
                temp=get(i);
                edit(i,get(i+1));
                edit(i+1,temp);
            }
    return get(count()-2);
}
void ExtendedArray::removeDuplicate()
{
    int i,j;
    for(i=0;i<count();i++)
        for(j=1;j<count();j++)
            if(get(i)==get(j))
                del(j);
}
int ExtendedArray::getCapacity()
{
    Array::getCapacity();
}
void ExtendedArray::rotateByOnePosition()
{
    int temp;
    int lastIndex;
    if(!isEmpty())
    {
        lastIndex=count()-1;
        temp=get(lastIndex);
        for(int i=lastIndex;i>0;i--)
            edit(i,get(i-1));
        edit(0,temp);
    }
}
ExtendedArray::ExtendedArray(int cap):Array(cap) {}

float ExtendedArray::average()
{
    float avg=0;
    avg=(float)sum()/count();
    return avg;
}
int ExtendedArray::sum()
{
    int sum=0;
    for(int i=0;i<count();i++)
        sum=sum+get(i);
    return sum;
}
int ExtendedArray::search(int data)
{
    for(int i=0;i<count();i++)
        if(get(i)==data)
            return i;
    return -1;
}
int ExtendedArray::smallest()
{
    int min=get(0);
    for(int i=1;i<count();i++)
        if(min>get(i))
            min=get(i);
    return min;
}
int ExtendedArray::greatest()
{
    int max=get(0);
    for(int i=1;i<count();i++)
    {
        if(max<get(i))
            max=get(i);
    }
    return max;
}
void ExtendedArray::sort()
{
     int r,i,temp;
     for( r=1;r<=count()-1;r++)
        for(i=0;i<=count()-1-r;i++)
            if(get(i)>get(i+1))
            {
                temp=get(i);
                edit(i,get(i+1));
                edit(i+1,temp);
            }
}

int main()
{
    ExtendedArray a1(4);
    a1.append(40);
    a1.append(30);
    a1.append(20);
    a1.append(10);
    // cout<<"Before sorting: ";
    // for(int i=0;i<a1.count();i++)
    //     cout<<a1.get(i)<<" ";
    // cout<<endl;
    // a1.sort();
    // for(int i=0;i<a1.count();i++)
    //     cout<<a1.get(i)<<" ";
    // cout<<endl;
    // cout<<"The greatest element out of all is: "<<a1.greatest()<<"\n";
    // cout<<"The smallest element out of all is: "<<a1.smallest()<<"\n";
    // // int no;
    // cout<<"Enter the data you want to find: "<<endl;
    // cin>>no;
    // cout<<"The data is at index number: \n";
    // cout<<a1.search(no);
    // cout<<"The Sum of all elements of the array:"<<a1.sum();
    // cout<<"The Average of all elements of the array:"<<a1.average()<<endl;
    // cout<<"The second largest element in the array is \n"<<a1.secondLargest();
    a1.swap(1,2);
     for(int i=0;i<a1.count();i++)
        cout<<a1.get(i)<<" ";

    


}