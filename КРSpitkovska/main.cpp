#include <iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

#include "Task6.h"
#include "Task8.h"
using namespace std;

int Segment::_freeID = 0;


int main() {
    //Task 1
    constexpr int exponent = 10;
    std::cout << "Power = " << exponent << "; ";
    print_powers<exponent>();

    //Task 3
    // // cтворення об'єкта класу DoubleList для зберігання int values
    ////DoubleList<int> myList;

    //// add елементів до списку
    //myList.add(5).add(10).add(15).add(20);
    //// Перегляд елементів у списку
    //cout << "Element's amout: " << myList.amount() << endl;
    //cout << "Let's output elements: ";
    //cout << myList <<  '\n';
    //// search елемента у списку
    //int searchValue = 10;
    //if (myList.find(searchValue)) 
    //{
    //    cout << "Element " << searchValue << " is in List" << endl;
    //}
    //else {
    //    cout << "Element " << searchValue << "  is NOT in List" << endl;
    //}

    //// del елемента зі списку
    //myList.del(15);

    //// check кількості елементів у списку
    //cout << "Element's amout: " << myList.amount() << endl;

    //cout << "Let's output elements: ";
    //cout << myList <<  '\n';
   
    ////Task 4
    //CyclicDoubleList<int> myCycList;

    //// Додаємо елементи у список
    //myCycList.add(10).add(20).add(30).add(40);

    //// Виконуємо пошук елементів у списку
    //std::cout << "Element 10 is " << (myCycList.find(10) ? "present" : "absent") << " in CycList\n";
    //std::cout << "Element 25 " << (myCycList.find(25) ? "present" : "absent") << " in CycList\n";

    //cout << myCycList << endl;

    //Task 5

    //Task 6
        // Створюємо точки для піраміди
    Point a(0, 0,0);
    Point b(1, 0, 0);
    Point c(1, -1, 0);
    Point s(1, -1, 1); // Вершина піраміди

    // Створюємо піраміду з правильними точками
    Pyramide validPyramid(a, b, c, s);
    Pyramide invertedPyr(s, c, b, a);
    // Виводимо піраміду з правильними точками
    std::cout << "Pyr 1:" << validPyramid << std::endl;
    std::cout <<"Pyr 2: " << invertedPyr << std::endl;
    validPyramid = invertedPyr;
    std::cout << "Pyr 1 after redefinition with Pyr 2:" << validPyramid << std::endl;
    // Зайвою точкою буде точка, що збігається з вершиною піраміди
    //Point invalidPoint(0, 0, 1); // Зайва точка

    
    // Спробуємо створити піраміду з неможливими точками
    //Pyramide invalidPyramid(a, b, c, invalidPoint);

    // Змінюємо вершину правильної піраміди
    Point newA(0, -1, 0);
    validPyramid.setVertexA(newA);
    // Виводимо змінену правильну піраміду
    std::cout << "Valid Pyramid (after vertex change):" << std::endl;
    std::cout << validPyramid << std::endl;
    std::cout << "Volume of Pyr 1:" << validPyramid.volume() << std::endl;
    //std::cout << validPyramid << std::endl;
    //Task 7
    
    //Task 8
    //// Створення об'єктів класу ShortString різних довжин
    //ShortString<5> shortStr1("Hello, world!"); // В об'єкті буде збережено лише перші 5 символів
    //ShortString<10> shortStr2("Short String"); // Рядок коротший за 10 символів, тому буде збережено весь рядок
    //ShortString<3> shortStr3("Long String"); // Рядок довший за 3 символи, тому буде обрізано до перших 3 символів

    //// Виведення об'єктів на екран
    //std::cout << "Short String 1: " << shortStr1 <<  '\n'; // Виведе "Hello"
    //std::cout << "Short String 2: " << shortStr2 <<  '\n'; // Виведе "Short String"
    //std::cout << "Short String 3: " << shortStr3 <<  '\n'; // Виведе "Lon"

    return 0;
}



 