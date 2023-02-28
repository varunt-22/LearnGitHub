#include<iostream>
using namespace std;

class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        DynArray(int);
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        bool isEmpty();
        int get(int);
        int count();
        ~DynArray();
        int find(int);
        void doubleArray();
        void halfArray();


};
void DynArray:: del(int index)
{
    int i;
   if(isEmpty())
   {
    cout<<endl<<"Array is empty";
   }
   else
   {
    for(i=index;i<lastIndex;i++)
        ptr[i]=ptr[i+1];
    lastIndex--;
    if(capacity/2>=lastIndex+1 && capacity>1)
        halfArray();
   }
}
void DynArray::append(int data)
{
   if(isFull())
     doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}
void DynArray::insert(int index,int data)
{
   int i;
   if(index<0 || index>lastIndex+1)
        cout<<"Invalid Index";
    else
    {
        if(isFull())
            doubleArray();
        else
        {
            for(int i=lastIndex;i>=index;i--)
            {
                ptr[i+1]=ptr[i];
            }
            ptr[index]=data;
            lastIndex++;
        }
    }
}
void DynArray::doubleArray()
{
    int *temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void DynArray::halfArray()
{
    int *temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}

DynArray::DynArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
DynArray::~DynArray()
{
    delete[]ptr;
}

bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
bool DynArray::isFull()
{
    return lastIndex==capacity-1;
    
}
void DynArray::edit(int index,int data)
{
    if(index>=0 && index<=lastIndex)
    {
        ptr[index]=data;
    }
}
int DynArray::get(int index)
{
    if(index>=0 && index<=lastIndex)
        return ptr[index];
    else
        cout<<"Invalid Index";
        return -1;
}
int DynArray::count()
{
    return lastIndex+1;
}
int DynArray::find(int data)
{
    for(int i=0;i<=lastIndex;i++)
    {
        if(ptr[i]==data)
            return i;
    }
}
int main()
{
    DynArray obj(8);
    if(obj.isEmpty())
        cout<<"Array is Empty \n";
    obj.append(14);
    obj.append(45);
    obj.insert(2,58);
    obj.insert(3,88);
    obj.insert(4,98);
    obj.insert(5,99);
    obj.insert(6,199);
    obj.insert(7,55);
    obj.append(47);
    for(int i=0;i<=obj.count()/2;i++)
        obj.del(i);
    obj.del(4);
    cout<<obj.count();


    for(int i=0;i<obj.count();i++)
        cout<<obj.get(i)<<" ";
    

}