#include<iostream>
using namespace std;
template<typename T>
struct node {
	T data;
	node<T>* next;
};
template<typename T>
class list {
	node<T>* head, * it;
	int n;
	node<T>* find_ptr(const T& val) {
		node<T>* temp;
		temp = head;
		while (temp != NULL) {
			if (temp->data == val)
				return temp;
			temp = temp->next;
		}
		return NULL;
	}
public:
	list() {
		head = NULL;
		n = 0;
		it = NULL;
	}
	~list() {
		make_empty();
	}
	void insert(const T& val) {
		node<T>* temp;
		temp = new node<T>;
		temp->data = val;
		temp->next = head;
		head = temp;
		n++;
	}
	bool find(const T& val) const {
		node<T>* temp;
		temp = head;
		while (temp != NULL) {
			if (temp->data == val)
				return true;
			temp = temp->next;
		}
		return false;
	}
	bool update(const T& old_val, const T& new_val) {
		node<T>* temp;
		temp = find_ptr(old_val);
		if (temp != NULL) {
			temp->data = new_val;
			return true;
		}
		else
			return false;
	}
	bool erase(const T& val) {
		if (head == NULL)
			return false;
		node<T>* temp;
		temp = head;
		if (temp->data == val) {
			head = temp->next;
			delete temp;
			n--;
			return true;
		}
		while (temp->next != NULL) {
			if (temp->next->data == val) {
				node<T>* to_del;
				to_del = temp->next;
				temp->next = temp->next->next;
				delete to_del;
				n--;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool empty() const {
		return head == NULL;
	}
	bool full() const {
		node<T>* temp;
		temp = new node<T>;
		if (temp == NULL)
			return true;
		else {
			delete temp;
			return false;
		}
	}
	void make_empty() {
		node<T>* temp;
		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
		n = 0;
	}
	int length()const {
		return n;
	}
	void reset() {
		it = head;
	}
	bool is_last() const {
		return it == NULL;
	}
	T get_next() {
		if (is_last()) {
			throw("Last Element Reached");
		}
		T val;
		val = it->data;
		it = it->next;
		return val;
	}
	void operator=(const list<T>& rhs) {
		make_empty();
		it = NULL;
		node<T>* temp;
		temp = rhs.head;
		while (temp != NULL) {
			insert(temp->data);
			temp = temp->next;
		}
	}
	list(const list<T>& rhs) {
		head = NULL;
		n = 0;
		it = NULL;
		operator=(rhs);
	}
};