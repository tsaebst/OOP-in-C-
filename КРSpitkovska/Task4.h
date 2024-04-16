#pragma once

#include "Task2.h"
#include "Task5.h"

//Клас циклічного двозв'язного масиву
template<typename T>
class CyclicDoublyLinkedList : public IDoubleList<T> 
{

private:
    //тут все зберігаємо
    DoublyLinkedListItem<T>* _first = nullptr;
    DoublyLinkedListItem<T>* _last = nullptr;
public:

     ~CyclicDoublyLinkedList() {};

    void append(T item) override 
    {
        if (_last == nullptr) {
            // тільки якщо  _first == nullptr також
            _last = new DoublyLinkedListItem<T>(item);
            _last->previous = _last;
            _last->next = _last;
            _first = _last;
        }
        else 
        {
            _last = new DoublyLinkedListItem<T>(item, _last,_first);
            _last->previous->next = _last;
            _first->previous = _last;
        }
    }

    T pop() override
    {
        if (_last == nullptr)
        {
            //  _first == nullptr 
            throw std::logic_error("The pop() invoked when list is empty, no item to remove");
        }

        auto last = this->_last;
        auto lastItem = last->item;

        if (_last->previous == _last)
        {
            _last = nullptr;
            _first = nullptr;
        }
        else 
        {
            _last = _last->previous;
            _last->next = _first;
            _first->previous = _last;
        }

        delete last;
        return lastItem;
    }

    //Останній елемент
    T last() override { return _last->item;}
    
    //Ітератор по масиву починаючи з прешого елемента
    Iterator<T>* iterator() override { return new CyclicDoublyLinkedListIterator<T>(_first);}

};






//#pragma once
//
//template <typename ListElem>
//class CyclicDoubleList : public IDoubleList<ListElem>
//{
//private:
//    struct ListNode {
//        const ListElem* _elem; 
//        ListNode* _prev;
//        ListNode* _next; 
//
//        // Конструктор вузла списку
//        ListNode(const ListElem& elem, ListNode* next, ListNode* prev) :
//            _elem(&elem), _next(next), _prev(prev) {}
//    };
//
//    ListNode* _start; 
//    ListNode* _end; 
//    mutable ListNode* _current; 
//    size_t _amount; 
//
//public:
//    CyclicDoubleList() : _start(nullptr), _end(nullptr), _current(nullptr), _amount(0) {}
//
//    ~CyclicDoubleList() {
//        // ...
//    }
//
//    // чи список порожній
//    bool empty() const override { return _amount == 0; }
//
//    //кількість елементів у списку
//    size_t amount() const override { return _amount; }
//
//    // додаванннчя елемента у список
//    CyclicDoubleList& add(const ListElem& elem) override {
//        if (empty()) {
//            _start = _end = _current = new ListNode(elem, nullptr, nullptr);
//            _start->_next = _start; // Встановлення зв'язку з самим собою для першого вузла
//            _start->_prev = _start; 
//        }
//        else {
//            ListNode* newNode = new ListNode(elem, _start, _end);
//            _start->_prev = newNode;
//            _end->_next = newNode;
//            _start = newNode;
//        }
//        _amount++;
//        return *this;
//    }
//
//    // сьорч елемента у списку
//    bool find(const ListElem& elem) const override
//    {
//        start();
//        ListNode* originalCurrent = _current;
//        do {
//            if (*_current->_elem == elem) {
//                return true;
//            }
//            _current = _current->_next;
//        } while (_current != originalCurrent);
//        return false;
//    }
//
//    // прибрати поточний елемент зі списку
//    CyclicDoubleList& del() override {
//        if (!empty()) {
//            ListNode* nextNode = _current->_next;
//            ListNode* prevNode = _current->_prev;
//            if (_current == _start) {
//                _start = nextNode;
//            }
//            if (_current == _end) {
//                _end = prevNode;
//            }
//            nextNode->_prev = prevNode;
//            prevNode->_next = nextNode;
//            delete _current;
//            _current = nextNode;
//            _amount--;
//        }
//        return *this;
//    }
//
//    // видалення заданого елемента зі списку
//    CyclicDoubleList& del(const ListElem& elem) override
//    {
//        if (find(elem)) {
//            del();
//        }
//        return *this;
//    }
//
//    // почвток ітерування по списку
//    const CyclicDoubleList& start() const override {
//        _current = _start;
//        return *this;
//    }
//
//    // перехід до наступного елемента у списку
//    const CyclicDoubleList& next() const override {
//        _current = _current->_next;
//        return *this;
//    }
//
//    // перевіримо чи кінець списку
//    bool stop() const override { return empty(); }
//
//    // отримання поточного елемента списку
//    const ListElem& getElem() const override { return *_current->_elem; }
//
//    // Перевантажений оператор виводу
//    friend std::ostream& operator<<(std::ostream& os, const CyclicDoubleList& list) {
//        // Початок ітерації по списку
//        const ListNode* current = list._start;
//        // Вивід елементів списку
//        while (true) {
//            os << *current->_elem << " "; // Вивід поточного елемента
//            if (current == list._end) break; // Перевірка на останній елемент списку
//            current = current->_next; // Перехід до наступного елемента
//        }
//        return os;
//    }
//};
