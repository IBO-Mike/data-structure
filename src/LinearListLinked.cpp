// 由链表实现的线性表

#include "LinearListLinked.h"
#include <iostream>

// 构造函数
LinearListLinked::LinearListLinked() {
    head = nullptr;
    length = 0;
}

// 析构函数
LinearListLinked::~LinearListLinked() {
    clear();
}

// 查找表中第 pos 个元素的前驱
int LinearListLinked::pre(int pos) const {
    if (pos <= 0 || pos >= length) {
        return -1;
    }
    return pos - 1;
}

// 查找表中第 pos 个元素的后继
int LinearListLinked::next(int pos) const {
    if (pos < 0 || pos >= length - 1) {
        return -1;
    }
    return pos + 1;
}

// 显示表中的数据
void LinearListLinked::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 定位线性表第一个元素
int LinearListLinked::begin() const {
    if (length == 0) return -1;
    return 0;
}

// 定位线性表最后一个元素
int LinearListLinked::end() const {
    if (length == 0) return -1;
    return length - 1;
}

// 求线性表第 pos 个元素
int LinearListLinked::getValue(int pos) const {
    if (pos < 0 || pos >= length) {
        return -1;
    }
    
    Node* current = head;
    for (int i = 0; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

// 查找满足给定条件的数据元素
int LinearListLinked::indexOf(int value) const {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// 删除线性表中的第 pos 个值为 value 的数据元素
void LinearListLinked::remove(int pos, int value) {
    if (pos < 0 || pos >= length) return;
    if (head == nullptr) return;
    
    // 验证位置的值是否匹配
    Node* current = head;
    for (int i = 0; i < pos; ++i) {
        current = current->next;
    }
    if (current->data != value) return;
    
    // 删除第 pos 个节点
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* prev = head;
        for (int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
    length--;
}

// 按值删除元素
void LinearListLinked::removeValue(int value) {
    if (head == nullptr) return;
    
    // 如果要删除的是头节点
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
        return;
    }
    
    // 查找要删除的节点
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        length--;
    }
}

// 在线性表的第 pos 个位置之前插入一个新的值为 value 的数据元素
void LinearListLinked::insert(int pos, int value) {
    if (pos < 0 || pos > length) return;
    
    Node* newNode = new Node{value, nullptr};
    
    // 插入到头部
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        // 找到第 pos-1 个节点
        Node* prev = head;
        for (int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    length++;
}

// 在末尾追加元素
void LinearListLinked::append(int value) {
    insert(length, value);
}

// 清空线性表
void LinearListLinked::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    length = 0;
}

// 判断线性表是否为空
bool LinearListLinked::isEmpty() const {
    return length == 0;
}

// 获取线性表长度
int LinearListLinked::size() const {
    return length;
}
