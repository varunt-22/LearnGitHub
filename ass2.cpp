#include "ArrayADT.cpp"
class ExtendedArray:public Array
{
    public:
        ExtendedArray(int);
        int greatest();
        int smallest();
        int search(int);
        int sum();
        float avg();
        void rotateRightByOne();
        void removeDuplicate();
        int secondLargest();
        void printArray();
        void sort();
        void swapItems(int,int);
};



ExtendedArray::ExtendedArray(int cap):Array(cap){ }

void ExtendedArray::sort()
{
    int r,temp,i;
    for(r=1;r<=count()-1;r++)
        for(i=0;i<=count()-1-r;i++)
            if(get(i)>get(i+1))
            {
                temp=get(i);
                edit(i,get(i+1));
                edit(i+1,temp);
            } 
}
void ExtendedArray::swapItems(int i, int j)
{
    int temp;
    if(i>=0 && i<count() && j>=0 && j<count())
    {
        temp=get(i);
        edit(i,get(j));
        edit(j,temp);

    }
}
void ExtendedArray::printArray()
{
    if(isEmpty())
    {
        cout<<"Array is empty";
    }
    for(int i=0;i<count();i++)
        cout<<get(i)<<" ";
}
int ExtendedArray::secondLargest()
{
    int r,temp,i;
    if(count()>=2)
    {
        for(r=1;r<=2;r++)
            for(i=0;i<=count()-1-r;r++)
                if(get(i)>get(i+1))
                {
                    temp=get(i);
                    edit(i,get(i+1));
                    edit(i+1,temp);
                }
        return get(count()-2);
    }
}
void ExtendedArray::removeDuplicate()
{
    for(int i=0;i<count();i++)
        for(int j=i+1;j<count();j++)
            if(get(j)==get(i))
            {
                del(j);
                j--;
            }
}
void ExtendedArray::rotateRightByOne()
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
float ExtendedArray::avg()
{
    float avg=0;
    if(isEmpty())
    {
        cout<<"Array is empty";
        return -1;
    }
    for(int i=0;i<count();i++)
        return avg=(float)sum()/count();
}
int ExtendedArray::sum()
{
    if(isEmpty())
    {
        cout<<"Array is empty";
        return -1;
    }
    int sum=0;
    for(int i=0;i<count();i++)
        sum=sum+get(i);
    return sum;
}
int ExtendedArray::search(int data)
{
    if(isEmpty())
    {
        cout<<"Array is Empty";
        return -1;
    }
    for(int i=0;i<count();i++)
        if(get(i)==data)
            return i+1;
}
int ExtendedArray::smallest()
{
    int min;
    if(isEmpty())
    {
        cout<<"Array is empty";
        return -1;
    }
    min=get(0);
    for(int i=1;i<count();i++)
        if(min>get(i))
            min=get(i);
        return min;
}
int ExtendedArray::greatest()
{
    int max;
    if(isEmpty())
    {
        cout<<"\n Array is Empty";
        return -1;
    }
    max=get(0);
    for(int i=1;i<count();i++)
        if(max<get(i))
            max=get(i);
    return max;
}
