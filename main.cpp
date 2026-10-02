#include <iostream>
#include <ctime>
#include <windows.h>
#include "DynamicArray.h"

using namespace std;

void PrintHeader(const string& title)
{
    cout << "\n==================================================\n";
    cout << "  " << title << "\n";
    cout << "==================================================\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(nullptr)));

    PrintHeader("ДЕМОНСТРАЦІЯ РОБОТИ КЛАСУ DynamicArray");

    cout << "\n1. Створення масиву з 6 елементів та заповнення випадковими числами (1..20):\n";
    DynamicArray arr(6);
    arr.Input(1, 20);
    cout << "Початковий масив:\n";
    arr.Output();

    PrintHeader("1. ТЕСТУВАННЯ МЕТОДУ ReSize()");
    cout << "ReSize(9) (збільшення розміру з 6 до 9):\n";
    arr.ReSize(9);
    arr.Output();

    cout << "ReSize(4) (зменшення розміру з 9 до 4):\n";
    arr.ReSize(4);
    arr.Output();

    arr.ReSize(7);
    arr.Input(1, 30);
    cout << "Новий масив з 7 елементів для сортування та пошуку:\n";
    arr.Output();

    PrintHeader("2. ТЕСТУВАННЯ МЕТОДІВ Sort() ТА Sort(bool)");
    cout << "Sort() - сортування за зростанням (за замовчуванням):\n";
    arr.Sort();
    arr.Output();

    cout << "Sort(false) - сортування за спаданням:\n";
    arr.Sort(false);
    arr.Output();

    cout << "Sort(true) - сортування за зростанням:\n";
    arr.Sort(true);
    arr.Output();

    PrintHeader("3. ТЕСТУВАННЯ МЕТОДУ Reverse()");
    cout << "Масив перед Reverse():\n";
    arr.Output();

    cout << "Масив після Reverse() (зворотний порядок):\n";
    arr.Reverse();
    arr.Output();

    PrintHeader("4. ТЕСТУВАННЯ МЕТОДУ Search()");
    arr.Output();

    if (arr.GetSize() > 0)
    {
        int target = arr.GetPointer()[1];
        cout << "Пошук елемента, який точно є в масиві (" << target << "):\n";
        int index = arr.Search(target);
        if (index != -1)
            cout << "-> Елемент " << target << " знайдено за індексом: [" << index << "]\n";
        else
            cout << "-> Елемент не знайдено!\n";
    }

    int notFoundTarget = 999;
    cout << "\nПошук елемента, якого немає в масиві (" << notFoundTarget << "):\n";
    int indexNotFound = arr.Search(notFoundTarget);
    if (indexNotFound != -1)
        cout << "-> Елемент знайдено за індексом: [" << indexNotFound << "]\n";
    else
        cout << "-> Елемент " << notFoundTarget << " НЕ ЗНАЙДЕНО (повернуто: " << indexNotFound << ")\n";

    PrintHeader("5. ДЕМОНСТРАЦІЯ КОНСТРУКТОРА КОПІЮВАННЯ");
    DynamicArray copyArr = arr;
    cout << "Оригінальний масив: ";
    arr.Output();
    cout << "Створена копія:     ";
    copyArr.Output();

    cout << "\nДемонстрацію успішно завершено!\n";
    return 0;
}