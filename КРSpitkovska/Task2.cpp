////#include "Task2.h"
//
//// Конструктор порожнього списку 
//template <typename ListElem> List<ListElem>::List() :
//	_start(0), _end(0), _current(0), _amount(0), _stop(true) {
//	return;
//}
//// Деструктор списку 
//template <typename ListElem> List<ListElem>::~List() 
//{
//ListNode* current = _start;
//while (current != nullptr) {
//	ListNode* next = current->_next;
//	delete current;
//	current = next;
//}
//
//// Знайти елемент списку Лістинг 6.42 
//template <typename ListElem>
//bool List<ListElem>::find(const ListElem& anElem) const {
//	start();
//	while (!stop()) {
//		if (*_current->_elem == elem) {
//			return true;
//		}
//		next();
//	}
//	return false;
//}
//
//// Видалити заданий елемент зі списку 
//template <typename ListElem>
//List<ListElem>& List<ListElem>::del(const ListElem& anElem) {
//	if (find(elem)) {
//		del();
//	}
//	return *this;
//}
//// Видалити поточний елемент списку 
//template <typename ListElem>
//List<ListElem>& List<ListElem>::del() {
//	ListNode* aPrev = _current->_prev;
//	ListNode* aNext = _current->_next;
//	delete _current;
//	_amount--;
//	_current = aNext;
//	if (aPrev != nullptr) {
//		aPrev->_next = aNext;
//	}
//	else {
//		_start = _current;
//	}
//	if (aNext != nullptr) {
//		aNext->_prev = aPrev;
//	}
//	else {
//		_end = _current;
//	}
//	_stop = _current == nullptr;
//	return *this;
//}
//// Додати елемент у початок списку 
//template <typename ListElem>
//List<ListElem>& List<ListElem>::add(const ListElem& anElem) {
//	if (empty()) {
//		_start = _end = _current = new ListNode(elem, nullptr, nullptr);
//	}
//	else {
//		_current = new ListNode(elem, _start, nullptr);
//		_start->_prev = _current;
//		_start = _current;
//	}
//	_amount++;
//	return *this;
//}
//
//// Почати ітерування списку 
//template <typename ListElem>
//const List<ListElem>& List<ListElem>::start() const {
//	_current = _start;
//	_stop = _current == nullptr;
//	return *this;
//}
//// Зробити крок ітерації 
//template <typename ListElem>
//const List<ListElem>& List<ListElem>::next() const {
//	_current = _current->_next;
//	_stop = _current == nullptr;
//	return *this;
//}
//
//
//// Утиліта виведення списку 
//template <typename ListElem>
//std::ostream& operator<< (std::ostream& os, const List<ListElem>& list) {
//	char separator = ':'; list.start();
//	while (!list.stop()) {
//		os << separator << list.getElem();
//		if (separator == ':') separator = ',';
//		list.next();
//	}
//	return os;
//}