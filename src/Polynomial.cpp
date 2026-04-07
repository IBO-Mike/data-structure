// 一元多项式类实现

#include "Polynomial.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// 构造函数
Polynomial::Polynomial() : head(nullptr), length(0) {}

// 析构函数
Polynomial::~Polynomial() {
    clear();
}

// 拷贝构造函数
Polynomial::Polynomial(const Polynomial& other) : head(nullptr), length(0) {
    PolyNode* current = other.head;
    while (current != nullptr) {
        addTerm(current->coefficient, current->exponent);
        current = current->next;
    }
}

// 赋值运算符重载
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) return *this;
    
    clear();
    PolyNode* current = other.head;
    while (current != nullptr) {
        addTerm(current->coefficient, current->exponent);
        current = current->next;
    }
    
    return *this;
}

// 添加项（按指数降序排列）
void Polynomial::addTerm(int coefficient, int exponent) {
    if (coefficient == 0) return;  // 不添加系数为 0 的项
    
    // 查找是否已有相同指数的项
    PolyNode* current = head;
    while (current != nullptr) {
        if (current->exponent == exponent) {
            // 合并同类项
            current->coefficient += coefficient;
            // 如果系数变为 0，需要通过复杂的方式删除该项
            if (current->coefficient == 0) {
                // 删除当前节点
                if (head == current) {
                    // 删除头节点
                    head = current->next;
                    delete current;
                } else {
                    // 找到前一个节点
                    PolyNode* prev = head;
                    while (prev != nullptr && prev->next != current) {
                        prev = prev->next;
                    }
                    if (prev != nullptr) {
                        prev->next = current->next;
                        delete current;
                    }
                }
                length--;
            }
            return;
        }
        current = current->next;
    }
    
    // 创建新节点
    PolyNode* newNode = new PolyNode(coefficient, exponent);
    
    // 如果链表为空或新项指数更大，插入到头部
    if (head == nullptr || exponent > head->exponent) {
        newNode->next = head;
        head = newNode;
    } else {
        // 找到合适的插入位置（按指数降序）
        current = head;
        while (current->next != nullptr && current->next->exponent > exponent) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    length++;
}

// 多项式加法
Polynomial Polynomial::add(const Polynomial& other) const {
    Polynomial result;
    
    PolyNode* p1 = head;
    PolyNode* p2 = other.head;
    
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exponent > p2->exponent) {
            result.addTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            result.addTerm(p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            int sum = p1->coefficient + p2->coefficient;
            if (sum != 0) {
                result.addTerm(sum, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // 处理剩余项
    while (p1 != nullptr) {
        result.addTerm(p1->coefficient, p1->exponent);
        p1 = p1->next;
    }
    
    while (p2 != nullptr) {
        result.addTerm(p2->coefficient, p2->exponent);
        p2 = p2->next;
    }
    
    return result;
}

// 多项式减法
Polynomial Polynomial::subtract(const Polynomial& other) const {
    Polynomial result;
    
    PolyNode* p1 = head;
    PolyNode* p2 = other.head;
    
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exponent > p2->exponent) {
            result.addTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            result.addTerm(-p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            int diff = p1->coefficient - p2->coefficient;
            if (diff != 0) {
                result.addTerm(diff, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // 处理剩余项
    while (p1 != nullptr) {
        result.addTerm(p1->coefficient, p1->exponent);
        p1 = p1->next;
    }
    
    while (p2 != nullptr) {
        result.addTerm(-p2->coefficient, p2->exponent);
        p2 = p2->next;
    }
    
    return result;
}

// 多项式乘法
Polynomial Polynomial::multiply(const Polynomial& other) const {
    Polynomial result;
    
    PolyNode* p1 = head;
    while (p1 != nullptr) {
        PolyNode* p2 = other.head;
        while (p2 != nullptr) {
            result.addTerm(p1->coefficient * p2->coefficient, 
                          p1->exponent + p2->exponent);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    
    return result;
}

// 显示多项式
void Polynomial::print() const {
    if (head == nullptr) {
        std::cout << "0" << std::endl;
        return;
    }
    
    PolyNode* current = head;
    bool first = true;
    
    while (current != nullptr) {
        int coef = current->coefficient;
        int exp = current->exponent;
        
        // 处理符号
        if (!first) {
            std::cout << (coef > 0 ? " + " : " - ");
        } else if (coef < 0) {
            std::cout << "-";
        }
        
        // 处理系数（绝对值）
        int absCoef = std::abs(coef);
        if (absCoef != 1 || exp == 0) {
            std::cout << absCoef;
        }
        
        // 处理指数部分
        if (exp > 0) {
            std::cout << "x";
            if (exp > 1) {
                std::cout << "^" << exp;
            }
        }
        
        current = current->next;
        first = false;
    }
    
    std::cout << std::endl;
}

// 获取项数
int Polynomial::size() const {
    return length;
}

// 判断是否为空
bool Polynomial::isEmpty() const {
    return length == 0;
}

// 清空多项式
void Polynomial::clear() {
    while (head != nullptr) {
        PolyNode* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

// 求值（给定 x 的值）
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    PolyNode* current = head;
    
    while (current != nullptr) {
        result += current->coefficient * std::pow(x, current->exponent);
        current = current->next;
    }
    
    return result;
}
