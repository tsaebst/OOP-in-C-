#pragma once
#include "Task2.h"
#include "Task5.h"

//Клас звичайного двозв'язного листа 
template<typename T>
class DoublyLinkedList : public IDoubleList<T>
{
private:
    DoublyLinkedListItem<T>* _first = nullptr;
    DoublyLinkedListItem<T>* _last = nullptr;
public:
    ~DoublyLinkedList(){};

    //Додавання елементу
    void append(T item) override 
    {
        if (_last == nullptr) 
        {
            _last = new DoublyLinkedListItem<T>(
                item,
                nullptr,
                nullptr
            );
            _first = _last;
        }
        else {
            _last = new DoublyLinkedListItem<T>(
                item,
                _last,
                nullptr
            );

            _last->previous->next = _last;
        }
    }

    //Видалення елементу
    T pop() override
    {
        if (_last == nullptr) 
        {
            throw std::logic_error("The pop() invoked when list is empty, no item to remove");
        }

        auto last = this->_last;
        auto lastItem = last->item;

        if (_last->previous == nullptr) {
            _last = nullptr;
            _first = nullptr;
        }
        else {
            _last = _last->previous;
            _last->next = nullptr;
        }

        delete last;
        return lastItem;
    }

    T last() override {
        return this->_last->item;
    }

    Iterator<T>* iterator() override {
        return new DoublyLinkedListIterator<T>(_first);
    }
};




//#pragma once
//
//template <typename ListElem>
//class DoubleList : public IDoubleList<ListElem>
//{
//friend std::ostream& operator<< <>(std::ostream& os, const DoubleList<ListElem>& list);
//private:
//    struct ListNode 
//    {
//        const ListElem* _elem;
//        ListNode* _prev;
//        ListNode* _next;
//        ListNode(const ListElem& elem, ListNode* next, ListNode* prev) :
//            _elem(&elem), _next(next), _prev(prev) {}
//    };
//
//    ListNode* _start;
//    ListNode* _end;
//    mutable ListNode* _current;
//    mutable bool _stop;
//    size_t _amount;
//
//public:
//    DoubleList() : _start(nullptr), _end(nullptr), _current(nullptr), _amount(0), _stop(true) {}
//    ~DoubleList() {
//        // ...
//    }
//
//    bool empty() const override { return _amount == 0; }
//    size_t amount() const override { return _amount; }
//
//    DoubleList& add(const ListElem& elem) override {
//        if (empty()) {
//            _start = _end = _current = new ListNode(elem, nullptr, nullptr);
//        }
//        else {
//            _current = new ListNode(elem, _start, nullptr);
//            _start->_prev = _current;
//            _start = _current;
//        }
//        _amount++;
//        return *this;
//    }
//
//    bool find(const ListElem& elem) const override {
//        start();
//        while (!stop()) {
//            if (*_current->_elem == elem) {
//                return true;
//            }
//            next();
//        }
//        return false;
//    }
//
//    DoubleList& del() override {
//        ListNode* aPrev = _current->_prev;
//        ListNode* aNext = _current->_next;
//        delete _current;
//        _amount--;
//        _current = aNext;
//        if (aPrev != nullptr) {
//            aPrev->_next = aNext;
//        }
//        else {
//            _start = _current;
//        }
//        if (aNext != nullptr) {
//            aNext->_prev = aPrev;
//        }
//        else {
//            _end = _current;
//        }
//        _stop = _current == nullptr;
//        return *this;
//    }
//
//    DoubleList& del(const ListElem& elem) override {
//        if (find(elem)) {
//            del();
//        }
//        return *this;
//    }
//
//    const DoubleList& start() const override {
//        _current = _start;
//        _stop = _current == nullptr;
//        return *this;
//    }
//
//    const DoubleList& next() const override {
//        _current = _current->_next;
//        _stop = _current == nullptr;
//        return *this;
//    }
//
//    bool stop() const override { return _stop; }
//
//    const ListElem& getElem() const override { return *_current->_elem; }
//
//};
//
//
//
//template <typename ListElem>
//std::ostream& operator<<(std::ostream& os, const DoubleList<ListElem>& list) {
//    typename DoubleList<ListElem>::ListNode* current = list._start; 
//    while (current != nullptr) {
//        os << *current->_elem << " ";
//        current = current->_next;
//    }
//    return os;
//}
//
//
