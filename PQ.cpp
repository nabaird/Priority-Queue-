#include <iostream>
#include "PQ.h"

using namespace std;

PQ::PQ(unsigned x=2)
{
    Init(x);
}

PQ::~PQ()
{
    delete arrayPntr;
}

void PQ::Insert(int x)
{
    if(theCapacity == theSize)
    {
        Resize();
    }

    arrayPntr[0] = x;//Ensures that the while loop below concludes when hole==1

    theSize++;//We never use index 0 of the array to store data
    int hole = theSize;
    while(arrayPntr[hole/2]>x)
    {
        arrayPntr[hole]=arrayPntr[hole/2];
        hole/=2;
    }

    arrayPntr[hole]=x;

}

int PQ::DeleteMin()
{
    int hole = 1;
    int val = arrayPntr[hole];
    int looseVal = arrayPntr[theSize];
    bool done = false;

    while(!done)
    {
        if((hole*2)+1<=theSize)//A check to make sure a node has two children
        {
            if(arrayPntr[hole*2]<arrayPntr[(hole*2)+1])//We check for which node is smaller
            {
                arrayPntr[hole]=arrayPntr[hole*2];
                hole = hole*2;
            }
            else
            {
                arrayPntr[hole]=arrayPntr[(hole*2)+1];
                hole = (hole*2)+1;
            }
        }
        else if(hole*2<=theSize)//In case a node only has 1 child
        {
             arrayPntr[hole]=arrayPntr[hole*2];
             hole = hole*2;
             arrayPntr[hole]= looseVal;
             done = true;
        }
        else//In case we are at a leaf
        {
            arrayPntr[hole]= looseVal;
            done = true;
        }
    }

    theSize-=1;
    return val;
}

void PQ::Init(unsigned x)
{
    if(x<=2)//the array must be initialized with at least a capacity of 2
    {
        arrayPntr = new int[2];
        theCapacity = 2;

    }
    else
    {
        arrayPntr = new int[x];
        theCapacity = x;

    }
    theSize=0;
}

void PQ::Resize()
{
    int* alt = new int[(theCapacity*2)];
    for(int i=0; i<theSize+1; i++)
    {
        alt[i]=arrayPntr[i];
    }
    delete arrayPntr;
    arrayPntr = alt;
    theCapacity*=2;
}

void PQ::Read()
{
    for(int i =1; i<theSize+1; i++)
    {
        cout<<arrayPntr[i]<<"\n";
    }
}

int main()
{
    PQ p(3);

    p.Insert(6);
        p.Insert(2);
            p.Insert(19);
                p.Insert(20);
                  p.Insert(10);
                    p.Insert(144);
                      p.Insert(11);
                        p.Insert(67);
                          p.Insert(111);
                            p.Insert(909);
                              p.Insert(15);
                                p.Insert(13);
                                p.DeleteMin();
                                 p.DeleteMin();
                                   p.DeleteMin();
                                   p.DeleteMin();
                                                                      p.DeleteMin();

                p.Read();



}
