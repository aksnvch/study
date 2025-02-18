﻿// Упрощенную о рюкзаке (веса предметов и их стоимость сгенерировать случайным образом: вместимость рюкзака 300 кг, веса предметов 10 – 300 кг, стоимость предметов 5 – 55 у.е.; 

// Main 
#include <iostream>
#include "Combi1.h"
#include <tchar.h>
#include "Knapsack.h"
#define NN 20
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int V = 300,    // вместимость рюкзака              
        v[NN],      // размер предмета каждого типа  
        c[NN];      // стоимость предмета каждого типа 
    short m[NN];    // количество предметов каждого типа  {0,1}

    clock_t t1, t2; // таймер

    for (int i = 12; i <= NN; i++)
    {
        t1 = clock();

        RandomFilling(v, i, 10, 300);      // заполнение массива с размерами каждого предмета
        RandomFilling(c, i, 5, 55);        // заполнение массива со стоимостями каждого предмета

        int maxcc = knapsack_s(
            V,   // [in]  вместимость рюкзака 
            i,   // [in]  количество типов предметов 
            v,   // [in]  размер предмета каждого типа  
            c,   // [in]  стоимость предмета каждого типа     
            m    // [out] количество предметов каждого типа  
        );

        t2 = clock();
        std::cout << t2 - t1 << std::endl;
    }

    /*std::cout << std::endl << "-------- Задача о рюкзаке ---------";
    std::cout << std::endl << "- количество предметов : " << NN;
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "- размеры предметов    : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] << " ";
    std::cout << std::endl << "- стоимости предмета   : ";
    for (int i = 0; i < NN; i++) std::cout << c[i] << " ";
    std::cout << std::endl << "- стоимости предметов  : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] * c[i] << " ";
    std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc;
    std::cout << std::endl << "- вес рюкзака: ";
    int s = 0; for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы: ";
    for (int i = 0; i < NN; i++) std::cout << " " << m[i];
    std::cout << std::endl << std::endl;*/
    return 0;
}
