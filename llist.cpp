#include "llist.h"

LList::Node::Node(const int& value, Node* next) {
    this->value = value;
    this->next = next;
}

LList::Node::~Node() {
    
}

LList::LList()
    : _head(nullptr), _size(0)
{
    
}

LList::~LList() {
    forceNodeDelete(_head);
}

void LList::push_back(int val) {
    if (_size == 0) {
        push_front(val);
    }
    else {
        insert_at(_size, val);
    }
}

void LList::push_front(int val) {
    _head = new Node(val, _head);
    ++_size;
}

void LList::pop_back() {
    erase_at(_size-1);
}

void LList::pop_front() {
    delete _head;
    _head = _head->next;
    --_size;
}

size_t LList::size() const {
    return _size;
}

int& LList::operator[](size_t idx) {
    if (idx == 0) {
        return _head->value;
    }
    else {
        Node* bufNode = this->_head;
        for (size_t i = 1; i<idx; i++) {
            bufNode = bufNode->next;
        }
        return bufNode->value;
    }
}
int LList:: operator[](size_t idx) const {
    if (idx == 0) {
        return _head->value;
    }
    else {
        Node* bufNode = this->_head;
        for (size_t i = 0; i<idx; i++) {
            bufNode = bufNode->next;
        }
        return bufNode->value;
    }
}
void LList::erase_at(size_t idx) {
    if (idx == 0) {
        pop_front();
    }
    else {
        Node* bufNode = this->_head;
        for (size_t i = 0; i<idx-1; i++) {
            bufNode = bufNode->next;
        }
        delete bufNode->next;
        bufNode->next = bufNode->next->next;
    }
    --_size;
}
void LList::insert_at(size_t idx, int val) {
    if (idx == 0) {
        push_front(val);
    }
    else {
       Node* bufNode = this->_head;
        for (size_t i = 0; i<idx-1; i++) {
            bufNode = bufNode->next;
        }
        Node* insertNode = new Node(val, bufNode->next);
        bufNode->next = insertNode;
    }
    ++_size;
}
void LList::reverse() {
    Node* current = _head;
    Node* next = nullptr;
    Node* prev = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    _head = prev;
}

void LList::forceNodeDelete(Node* node) {
    if (node == nullptr) {
        return;
    }

    Node* nextDeleteNode = node->next;
    delete node;
    forceNodeDelete(nextDeleteNode);
}
