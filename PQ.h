#include <iostream>

using namespace std;

class PQ
{
private:
    PQ(PQ&);
    PQ& operator=(PQ&);

public:
    PQ(unsigned);
    ~PQ();

    void Insert(int);
    int DeleteMin();
   void Read();

private:
    void Init(unsigned);
    void Resize();


    int* arrayPntr;
    int theCapacity;
    int theSize;
};
