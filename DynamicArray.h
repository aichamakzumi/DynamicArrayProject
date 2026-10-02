#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray
{
private:
    int* ptr;
    int size;

public:
    DynamicArray();
    explicit DynamicArray(int S);
    DynamicArray(int S, int defaultValue);
    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept;
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    int GetSize() const;
    int* GetPointer() const;

    void Input(int minVal = 0, int maxVal = 99);
    void Output() const;

    void ReSize(int newSize);          
    void Sort();                       
    void Sort(bool direction);         
    int Search(int a) const;           
    void Reverse();                    
};

#endif 
