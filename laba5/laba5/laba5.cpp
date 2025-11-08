
#include <iostream>
#include <cmath>
void isp1(int x)
{
    x = x * (-1);
    std::cout << "Испытание для 1 числа" << std::endl;
    std::cout << "Противоположное одному числу: " << x << std::endl;
    return;

}
void isp2(int x, int y) {
    int i = 0;
    int c = y;
    while (c != 0) {
        i += 1;
        c = c / 10;
    }
    int baza = 1;
    while (i != 0) {
        i = i - 1;
        baza = baza * 10;
    }
    int otvet;
    otvet = x * baza + y;
    std::cout << "Два числа скрещеных вместе: " << otvet << std::endl;
    return;
}
void trey(int x, int y, int z) {
    setlocale(LC_ALL, "RU");
    std::cout << "ЛАБ 1 вариант 6" << std::endl;
    /*std::cout << "первая сторона треугольника:" << std::endl;
    int st1;
    std::cin >> st1;
    std::cout << "вторая сторона треугольника:" << std::endl;
    int st2;
    std::cin >> st2;
    std::cout << "третья сторона треугольника:" << std::endl;
    int st3;
    std::cin >> st3;*/
    double p = (x + y + z) / 2.0;
    std::cout << "полупериметр треугольника=" << p << std::endl;
    double S = std::sqrt(p * (p - x) * (p - y) * (p - z));/*sqrt используется только если ввести библеотеку cmath
    (#include <cmath>) sqrt-корень*/
    std::cout << "int,занимает " << sizeof(int) * 8 << " бит(а,ов)" << std::endl;
    std::cout << "Min знач =" << INT_MIN << std::endl;
    std::cout << "Max знач =" << INT_MAX << std::endl;
    ; std::cout << "double занимает " << sizeof(double) << " бит(а,ов)" << std::endl;
    std::cout << "Min знач =" << DBL_MIN << std::endl;
    std::cout << "Max знач =" << DBL_MAX << std::endl;
    ; std::cout << "Площадь треугольника = " << S << std::endl << std::endl;
    return;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int a;
    int b;
    int ab;
    std::cout << "Какой пункт??(1 или 2(ввод числом(для второго пункта обязательно 3 числа(площадь треугольника))))" << std::endl;
    int vibor;
    std::cin >> vibor;
    if (vibor != 1 and vibor != 2) {
        std::cout << "Нарушение выбора пункта" << std::endl;
        return 0;
    }
    std::cout << "Числа: " << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> ab;


    if (vibor == 1) {
        if (a != 0 and b != 0 and ab != 0) {
            std::cout << "исп для 3х чисел, не возможно по условию" << std::endl;
            return 0;
        }
        if (a == 0 and b == 0 and ab == 0) {
            std::cout << "исп для 0 чисел, не возможно по условию" << std::endl;
            return 0;
        }

        if (a != 0 and b == 0 and ab == 0) {
            isp1(a);
            return 0;
        }
        if (b != 0 and a == 0 and ab == 0) {
            isp1(b);
            return 0;
        }
        if (ab != 0 and a == 0 and b == 0) {
            isp1(ab);
            return 0;
        }
        std::cout << "Испытание для 2ух чисел" << std::endl;
        if (a != 0 and b != 0 and ab == 0) {
            isp2(a, b);
            return 0;

        }
        if (a != 0 and b == 0 and ab != 0) {
            isp2(a, ab);
            return 0;

        }
        if (a == 0 and b != 0 and ab != 0) {
            isp2(b, ab);
            return 0;

        }
    }
    if (vibor == 2) {
        if (a == 0 or b == 0 or ab == 0 or (a+b<ab) or (a+ab<b) or (ab+b<a)) {
            std::cout << "такого треугольника не существует!!!!" << std::endl;
            return 0;

        }
        else {
            trey(a, b, ab);
            return 0;
        }

    }
}