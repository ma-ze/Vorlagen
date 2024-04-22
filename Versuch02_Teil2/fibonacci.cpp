//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
// Aufgabe 2.2.1
int fib_rec(int n){ 
    if(n==0) return 0;
    if(n==1) return 1;
    return fib_rec(n-1) + fib_rec(n-2);
}

int fibonacci(int n)
{
    int previousFib = 0;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 0; i <= n-2; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

unsigned long longfib(int n)
{
    unsigned long previousFib = 0;
    unsigned long currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 0; i <= n-2; i++)
    {
        unsigned long newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 25:" << std::endl ;
    for (int i = 0; i <= 25 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fib_rec(i) << std::endl ;
    }
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 1; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    std::cout << "results for n = 47:" << std::endl ;
    std::cout << fib_rec(47) << std::endl ; //comment this in if you are patient
    std::cout << fibonacci(47) << std::endl ;
    std::cout << longfib(47) << std::endl ;
    std::cout << "fib(46):" << std::endl ;
    std::cout << fibonacci(46) << std::endl ;
    std::cout << "fib(93):" << std::endl ;
    std::cout << longfib(93) << std::endl ; //last number that can be calculated with unsigned long (64 bit)
    return 0;
}
