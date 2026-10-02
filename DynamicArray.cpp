#include "DynamicArray.h"
#include <cstdlib>
#include <utility>

DynamicArray::DynamicArray() : ptr(nullptr), size(0) {}

DynamicArray::DynamicArray(int S) : ptr(nullptr), size(0)
{
    if (S > 0)
    {
        size = S;
        ptr = new int[S]{ 0 };
    }
}

DynamicArray::DynamicArray(int S, int defaultValue) : ptr(nullptr), size(0)
{
    if (S > 0)
    {
        size = S;
        ptr = new int[S];
        for (int i = 0; i < size; ++i)
        {
            ptr[i] = defaultValue;
        }
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) : ptr(nullptr), size(other.size)
{
    if (size > 0)
    {
        ptr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            ptr[i] = other.ptr[i];
        }
    }
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept : ptr(other.ptr), size(other.size)
{
    other.ptr = nullptr;
    other.size = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] ptr;
    ptr = nullptr;
    size = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] ptr;
        size = other.size;
        if (size > 0)
        {
            ptr = new int[size];
            for (int i = 0; i < size; ++i)
            {
                ptr[i] = other.ptr[i];
            }
        }
        else
        {
            ptr = nullptr;
        }
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept
{
    if (this != &other)
    {
        delete[] ptr;
        ptr = other.ptr;
        size = other.size;
        other.ptr = nullptr;
        other.size = 0;
    }
    return *this;
}

int DynamicArray::GetSize() const
{
    return size;
}

int* DynamicArray::GetPointer() const
{
    return ptr;
}

void DynamicArray::Input(int minVal, int maxVal)
{
    if (minVal > maxVal)
    {
        std::swap(minVal, maxVal);
    }
    int range = maxVal - minVal + 1;
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = minVal + rand() % range;
    }
}

void DynamicArray::Output() const
{
    if (size == 0 || ptr == nullptr)
    {
        std::cout << "[ Порожній масив ]\n";
        std::cout << "--------------------------------------------------\n";
        return;
    }

    std::cout << "[ ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << ptr[i] << (i + 1 < size ? ", " : " ");
    }
    std::cout << "] (Розмір: " << size << ")\n";
    std::cout << "--------------------------------------------------\n";
}

void DynamicArray::ReSize(int newSize)
{
    if (newSize < 0 || newSize == size)
    {
        return;
    }

    if (newSize == 0)
    {
        delete[] ptr;
        ptr = nullptr;
        size = 0;
        return;
    }

    int* temp = new int[newSize]{ 0 };
    int elementsToCopy = (newSize < size) ? newSize : size;

    for (int i = 0; i < elementsToCopy; ++i)
    {
        temp[i] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
    size = newSize;
}

void DynamicArray::Sort()
{
    Sort(true);
}

void DynamicArray::Sort(bool direction)
{
    if (size <= 1 || ptr == nullptr) return;

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            bool needSwap = direction ? (ptr[j] > ptr[j + 1]) : (ptr[j] < ptr[j + 1]);
            if (needSwap)
            {
                std::swap(ptr[j], ptr[j + 1]);
            }
        }
    }
}

int DynamicArray::Search(int a) const
{
    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] == a)
        {
            return i;
        }
    }
    return -1;
}

void DynamicArray::Reverse()
{
    if (size <= 1 || ptr == nullptr) return;

    for (int i = 0; i < size / 2; ++i)
    {
        std::swap(ptr[i], ptr[size - 1 - i]);
    }
}