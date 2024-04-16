#pragma once
#include "Task2.h"

//Базовий клас ітератора на базі Ітератора
template <typename T>
class BaseDoublyLinkedListIterator : public Iterator<T> 
{
protected:
    DoublyLinkedListItem<T>* first;
    DoublyLinkedListItem<T>* current;
    bool firstItemReached = false;
public:
    //Конструктор
    explicit BaseDoublyLinkedListIterator(DoublyLinkedListItem<T>* first) : first(first), current(first) {};
    //Дестр.
    ~BaseDoublyLinkedListIterator() {}
    //Перехід на наступний елемент списку
    T next() override 
    {
        if (!this->hasNext()) 
        {
            throw std::logic_error("The next() invoked on a iterator when hasNext() is false");
        }

        if (!firstItemReached)
        {
            firstItemReached = true;
            return current->item;
        }

        current = current->next;
        return current->item;
    }
    //Перевизначаємо елемент як початок
    void reset() override 
    {
        current = first;
        firstItemReached = false;
    }
};

//Наслідувані класи ітераторів для звичайного і циклічного двозв. списків:
template <typename T>
class CyclicDoublyLinkedListIterator : public BaseDoublyLinkedListIterator<T> {
public:
    using BaseDoublyLinkedListIterator<T>::BaseDoublyLinkedListIterator;

    bool hasNext() override {
        return this->current != nullptr && (this->current->next != this->first || !this->firstItemReached);
    }
};

template <typename T>
class DoublyLinkedListIterator : public BaseDoublyLinkedListIterator<T> {
public:
    using BaseDoublyLinkedListIterator<T>::BaseDoublyLinkedListIterator;

    bool hasNext() override {
        return this->current != nullptr && (this->current->next != nullptr || !this->firstItemReached);
    }
};
