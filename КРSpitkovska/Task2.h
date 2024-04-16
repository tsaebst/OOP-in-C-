#pragma once

#include <optional>
#include <memory>
#include <stdexcept>

//Клас ітератор
template <typename T>
class Iterator 
{
public:
    virtual ~Iterator() {}
    //Наступний ел.
    virtual T next() = 0;
    //Чи не останній елемент
    virtual bool hasNext() = 0;
    //Зробити першим
    virtual void reset() = 0;
};

//Клас ітероване
template <typename T>
class Iterable
{
public:
    virtual ~Iterable() {}
    virtual Iterator<T>* iterator() = 0;
};

//Пошук елементу в масиві
template<typename T>
bool contains(Iterable<T>* iterable, T value)
{
    auto iterator = iterable->iterator();

    while (iterator->hasNext())
    {
        if (value == iterator->next())
        {
            return true;
        }
    }

    return false;
}

//template<typename T>
//bool contains(Iterable<T>* iterable, T value)
//{
//    std::unique_ptr<Iterator<T>> iterator(iterable->iterator());
//
//    while (iterator->hasNext()) 
//    {
//        if (value == iterator->next()) return true;
//    }
//
//    return false;
//}

//Структура елементу двозв'яз.масиву
template<typename T>
struct DoublyLinkedListItem
{
    T item;
    DoublyLinkedListItem<T>* previous;
    DoublyLinkedListItem<T>* next;
};

//Наш основний клас двозв'яз.мас. IDoubleList
template<typename T>
class IDoubleList : public Iterable<T> 
{
public:
    virtual ~IDoubleList() {};
    //Останній елемент
    virtual T last() = 0;
    //Додавання елементів
    virtual void append(T item) = 0;
    //Видалення ел.
    virtual T pop() = 0;
};


//
//template <typename ListElem>
//class IDoubleList {
//public:
//    virtual ~IDoubleList() {}
//
//    virtual bool empty() const = 0; // Перевіряє, чи список порожній
//    virtual size_t amount() const = 0; // Селектор кількості елементів у списку
//    virtual IDoubleList& add(const ListElem& elem) = 0; // Додати елемент у початок списку
//    virtual bool find(const ListElem& elem) const = 0; // Знайти елемент списку
//    virtual IDoubleList& del() = 0; // Видалити поточний елемент списку
//    virtual IDoubleList& del(const ListElem& elem) = 0; // Видалити заданий елемент списку
//
//    // Ітератори
//    virtual const IDoubleList& start() const = 0; // Почати ітерування списку
//    virtual const IDoubleList& next() const = 0; // Зробити крок ітерації
//
//    virtual bool stop() const = 0; // Селектор атрибута вичерпання списку
//
//    // Селектор поточного елемента списку
//    virtual const ListElem& getElem() const = 0;
//};
//
//template <typename ListElem>
//std::ostream& operator<< (std::ostream& os, const IDoubleList<ListElem>& list);

