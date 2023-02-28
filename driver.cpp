#include "ass2.cpp"
#include<iostream>
using namespace std;

int main()
{
    ExtendedArray obj(5);
    obj.append(25);
    obj.append(30);
    obj.append(22);
    obj.append(30);
    obj.append(22);

    for(int i=0;i<obj.count();i++)
    {
        cout<<obj.get(i)<<" ";
    }
    cout<<"The greatest Element amongst all is "<<obj.greatest();
    cout<<"The smallest Element amongst all is "<<obj.smallest();
    cout<<"The element is at "<<obj.search(45)<<endl;
    cout<<obj.sum()<<endl;
    cout<<obj.avg()<<endl;
    cout<<"Before removing duplicates: ";
    for(int i=0;i<obj.count();i++)
    {
        cout<<obj.get(i)<<" ";
    }
    cout<<"After removing duplicates: ";
    obj.removeDuplicate();
    obj.printArray();
    cout<<"After swapping elements";
    obj.swapItems(1,2);
    obj.printArray();

    cout<<"\n \n Array after sorting : ";
    obj.sort();
    obj.printArray();
    cout<<"The second largest element is: ";
    cout<<obj.secondLargest();

  

    
}