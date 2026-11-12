
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

// ==========================================
// ЗАВДАННЯ PROC12
// Сортування трьох чисел за зростанням
// ==========================================

// Оголошення процедури
void SortInc3(double &A, double &B, double &C);

// Визначення процедури
void SortInc3(double &A, double &B, double &C)
{
    if (A > B)
        swap(A, B);

    if (B > C)
        swap(B, C);

    if (A > B)
        swap(A, B);
}

// Процедура виконання першого завдання
void Task12()
{
    double A1, B1, C1;
    double A2, B2, C2;

    cout << "\n--- ЗАВДАННЯ PROC12 ---\n";

    cout << "Введіть перший набір чисел (A1, B1, C1): ";

    if (!(cin >> A1 >> B1 >> C1))
    {
        cout << "Помилка введення даних!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Введіть другий набір чисел (A2, B2, C2): ";

    if (!(cin >> A2 >> B2 >> C2))
    {
        cout << "Помилка введення даних!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    SortInc3(A1, B1, C1);
    SortInc3(A2, B2, C2);

    cout << "\nПерший набір за зростанням: "
         << A1 << " " << B1 << " " << C1 << endl;

    cout << "Другий набір за зростанням: "
         << A2 << " " << B2 << " " << C2 << endl;
}

// ==========================================
// ЗАВДАННЯ PROC23
// Знаходження коренів квадратного рівняння
// ==========================================

// Оголошення процедури
void QuadraticRoots(double a, double b, double c,
                    double &x1, double &x2, bool &hasRoots);

// Визначення процедури
void QuadraticRoots(double a, double b, double c,
                    double &x1, double &x2, bool &hasRoots)
{
    double D = b * b - 4 * a * c;

    if (D < 0)
    {
        hasRoots = false;
        return;
    }

    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);

    hasRoots = true;
}

// Процедура виконання другого завдання
void Task23()
{
    double a, b, c;
    double x1, x2;
    bool hasRoots;

    cout << "\n--- ЗАВДАННЯ PROC23 ---\n";

    for (int i = 1; i <= 3; i++)
    {
        cout << "\nРівняння №" << i << endl;

        cout << "Введіть коефіцієнти a, b, c: ";

        if (!(cin >> a >> b >> c))
        {
            cout << "Помилка введення даних!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        if (a == 0)
        {
            cout << "Помилка! Коефіцієнт а не може дорівнювати нулю!\n";
            continue;
        }

        QuadraticRoots(a, b, c, x1, x2, hasRoots);

        if (hasRoots)
        {
            cout << "Перший корінь: x1 = " << x1 << endl;
            cout << "Другий корінь: x2 = " << x2 << endl;
        }
        else
        {
            cout << "Дійсних коренів немає.\n";
        }
    }
}

// ==========================================
// ЗАВДАННЯ PROC32
// Виконання арифметичних операцій
// ==========================================

// Оголошення функції
double Calc(double A, double B, int Op);

// Визначення функції
double Calc(double A, double B, int Op)
{
    switch (Op)
    {
        case 1:
            return A - B;

        case 2:
            return A * B;

        case 3:
            return A / B;

        default:
            return A + B;
    }
}

// Процедура виконання третього завдання
void Task32()
{
    double A, B;
    int N1, N2, N3;

    cout << "\n--- ЗАВДАННЯ PROC32 ---\n";

    cout << "Введіть ненульові числа A і B: ";

    if (!(cin >> A >> B))
    {
        cout << "Помилка введення даних!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (A == 0 || B == 0)
    {
        cout << "Помилка! Числа A і B повинні бути ненульовими!\n";
        return;
    }

    cout << "Введіть цілі числа N1, N2, N3: ";

    if (!(cin >> N1 >> N2 >> N3))
    {
        cout << "Помилка введення даних!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "\nРезультати обчислень:\n";

    cout << "Результат першої операції: "
         << Calc(A, B, N1) << endl;

    cout << "Результат другої операції: "
         << Calc(A, B, N2) << endl;

    cout << "Результат третьої операції: "
         << Calc(A, B, N3) << endl;
}

// ==========================================
// ГОЛОВНА ФУНКЦІЯ ТА ГОЛОВНЕ МЕНЮ
// ==========================================

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "       ЛАБОРАТОРНА РОБОТА №4\n";
        cout << "  СТРУКТУРУВАННЯ ПРОГРАМ З ФУНКЦІЯМИ\n";
        cout << "====================================\n";

        cout << "1 - Сортування трьох чисел (Proc12)\n";
        cout << "2 - Розв'язання квадратних рівнянь (Proc23)\n";
        cout << "3 - Арифметичні операції (Proc32)\n";
        cout << "0 - Вихід із програми\n";

        cout << "\nОберіть завдання: ";

        if (!(cin >> choice))
        {
            cout << "Помилка! Введіть ціле число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                Task12();
                break;

            case 2:
                Task23();
                break;

            case 3:
                Task32();
                break;

            case 0:
                cout << "Роботу програми завершено!\n";
                break;

            default:
                cout << "Неправильний пункт меню! Спробуйте ще раз.\n";
        }

    } while (choice != 0);

    return 0;
}
