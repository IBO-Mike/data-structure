// 由数组实现的线性表


#include "LinearListArray.h"
#include <iostream>

LinearListArray::LinearListArray(const int size) {
    capacity = size;
    length = 0;
    data = new int[capacity];
}

LinearListArray::~LinearListArray() {
    delete[] data;
}

int LinearListArray::pre(const int pos) const {
    if (pos <= 0 || pos >= length) {
        return -1;
    }
    return pos - 1;
}

int LinearListArray::next(const int pos) const {
    if (pos < 0 || pos >= length - 1) {
        return -1;
    }
    return pos + 1;
}

void LinearListArray::print() const {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int LinearListArray::begin() const {
    if (length == 0) return -1;
    return 0;
}

int LinearListArray::end() const {
    if (length == 0) return -1;
    return length - 1;
}

int LinearListArray::getValue(const int pos) const {
    if (pos < 0 || pos >= length) {
        return -1;
    }
    return data[pos];
}

int LinearListArray::indexOf(const int value) const {
    for (int i = 0; i < length; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

void LinearListArray::remove(const int pos, const int value) {
    if (pos < 0 || pos >= length) return;
    if (data[pos] != value) return;

    for (int i = pos; i < length - 1; ++i) {
        data[i] = data[i + 1];
    }
    length--;
}

// 按值删除元素
void LinearListArray::removeValue(const int value) {
    int index = indexOf(value);
    if (index == -1) return;
    remove(index, value);
}

// 判断线性表是否为空
[[nodiscard]] bool LinearListArray::isEmpty() const {
    return length == 0;
}

// 获取线性表长度
[[nodiscard]] int LinearListArray::size() const {
    return length;
}

// 扩容
void LinearListArray::expand(const int newCapacity) {
    if (newCapacity <= capacity) return;
    
    int* newData = new int[newCapacity];
    for (int i = 0; i < length; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void LinearListArray::insert(const int pos, const int value) {
    if (pos < 0 || pos > length) return;
    
    // 如果容量不足，自动扩容
    if (length >= capacity) {
        expand(capacity * 2);
    }

    for (int i = length; i > pos; --i) {
        data[i] = data[i - 1];
    }

    data[pos] = value;
    length++;
}

// 在末尾追加元素
void LinearListArray::append(const int value) {
    insert(length, value);
}

void LinearListArray::clear() {
    length = 0;
}
