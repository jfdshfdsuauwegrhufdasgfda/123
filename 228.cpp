
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Перевірка коректності введення дійсного числа
double inputDouble()
{
    double value;

    while (!(cin >> value) || !isfinite(value))
    {
        cout << "Помилка! Введіть коректне число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}

// Перевірка коректності введення цілого числа
int inputInt()
{
    int value;

    while (!(cin >> value))
    {
        cout << "Помилка! Введіть ціле число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}

// Завдання 1. If12
// Знаходження найменшого з трьох чисел
void task1()
{
    double a, b, c;

    cout << "\nЗавдання 1. Знаходження найменшого числа\n";

    cout << "Введіть три числа:\n";
    cout << "a = ";
    a = inputDouble();

    cout << "b = ";
    b = inputDouble();

    cout << "c = ";
    c = inputDouble();

    double minNumber = a;

    if (b < minNumber)
        minNumber = b;

    if (c < minNumber)
        minNumber = c;

    cout << "Найменше число: " << minNumber << endl;
}

// Завдання 2. If23
// Знаходження четвертої вершини прямокутника
void task2()
{
    int x1, y1, x2, y2, x3, y3;
    int x4, y4;

    cout << "\nЗавдання 2. Четверта вершина прямокутника\n";

    cout << "Введіть координати трьох вершин:\n";

    cout << "x1 = ";
    x1 = inputInt();
    cout << "y1 = ";
    y1 = inputInt();

    cout << "x2 = ";
    x2 = inputInt();
    cout << "y2 = ";
    y2 = inputInt();

    cout << "x3 = ";
    x3 = inputInt();
    cout << "y3 = ";
    y3 = inputInt();

    // Перевірка, що точки є різними
    if ((x1 == x2 && y1 == y2) ||
        (x1 == x3 && y1 == y3) ||
        (x2 == x3 && y2 == y3))
    {
        cout << "Помилка! Вершини повинні бути різними.\n";
        return;
    }

    // Визначення координат четвертої вершини
    // Для прямокутника з координатними осями
    if (x1 == x2)
    {
        if (y1 == y3)
        {
            x4 = x3;
            y4 = y2;
        }
        else if (y2 == y3)
        {
            x4 = x3;
            y4 = y1;
        }
        else
        {
            cout << "Неможливо утворити прямокутник.\n";
            return;
        }
    }
    else if (x1 == x3)
    {
        if (y1 == y2)
        {
            x4 = x2;
            y4 = y3;
        }
        else if (y2 == y3)
        {
            x4 = x2;
            y4 = y1;
        }
        else
        {
            cout << "Неможливо утворити прямокутник.\n";
            return;
        }
    }
    else if (x2 == x3)
    {
        if (y1 == y2)
        {
            x4 = x1;
            y4 = y3;
        }
        else if (y1 == y3)
        {
            x4 = x1;
            y4 = y2;
        }
        else
        {
            cout << "Неможливо утворити прямокутник.\n";
            return;
        }
    }
    else
    {
        cout << "Неможливо утворити прямокутник.\n";
        return;
    }

    cout << "Четверта вершина прямокутника:\n";
    cout << "x4 = " << x4 << endl;
    cout << "y4 = " << y4 << endl;
}

// Завдання 3. If32
// Обчислення кусочної функції h(x)
void task3()
{
    double x;
    int h;

    cout << "\nЗавдання 3. Обчислення функції h(x)\n";

    cout << "Введіть дійсне число x: ";
    x = inputDouble();

    // Вибір формули залежно від значення x
    if (x < 0)
    {
        h = static_cast<int>(2 * x);
    }
    else if (x < 7)
    {
        h = static_cast<int>(x);
    }
    else
    {
        h = static_cast<int>(x - 6);
    }

    cout << "Значення h(x) = " << h << endl;
}

// Головна функція програми
// Організація меню за допомогою switch
int main()
{
    int choice;

    do
    {
        cout << "\n========== ГОЛОВНЕ МЕНЮ ==========\n";
        cout << "1 - Знайти найменше з трьох чисел\n";
        cout << "2 - Знайти четверту вершину прямокутника\n";
        cout << "3 - Обчислити значення функції h(x)\n";
        cout << "0 - Вихід із програми\n";
        cout << "Ваш вибір: ";

        choice = inputInt();

        switch (choice)
        {
            case 1:
                task1();
                break;

            case 2:
                task2();
                break;

            case 3:
                task3();
                break;

            case 0:
                cout << "Завершення програми.\n";
                break;

            default:
                cout << "Помилка! Такого пункту меню немає.\n";
        }

    } while (choice != 0);

    return 0;
}
