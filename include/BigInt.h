// 长整数类 - 支持 100 位以内的长整数加减运算
// 使用链表实现，每个节点存储一位数字

#ifndef DATA_STRUCTURE_BIGINT_H
#define DATA_STRUCTURE_BIGINT_H

#include <iostream>
#include <string>

//长整数链表节点
struct BigIntNode {
    int digit;
    BigIntNode *next;

    explicit BigIntNode(const int d) : digit(d), next(nullptr) {
    }
};

class BigInt {
private:
    BigIntNode *head; // 头指针（指向最低位）
    bool isNegative; // 符号标志
    int length; // 位数

public:
    // 默认构造函数
    BigInt();

    // 从字符串构造
    explicit BigInt(const std::string &numStr);

    // 从整数构造
    explicit BigInt(long long num);

    // 析构函数
    ~BigInt();

    // 拷贝构造函数
    BigInt(const BigInt &other);

    // 赋值运算符重载
    BigInt &operator=(const BigInt &other);

    // 加法
    [[nodiscard]] BigInt add(const BigInt &other) const;

    // 减法
    [[nodiscard]] BigInt subtract(const BigInt &other) const;

    // 加法运算符重载
    BigInt operator+(const BigInt &other) const;

    // 减法运算符重载
    BigInt operator-(const BigInt &other) const;

    // 显示长整数
    void print() const;

    // 获取位数
    [[nodiscard]] int size() const;

    // 判断是否为空（值为 0）
    [[nodiscard]] bool isZero() const;

    // 判断正负
    [[nodiscard]] bool isPositive() const;

    // 清空
    void clear();

    // 比较大小
    [[nodiscard]] int compare(const BigInt &other) const;

    // 等于运算符
    bool operator==(const BigInt &other) const;

    // 不等于运算符
    bool operator!=(const BigInt &other) const;

    // 小于运算符
    bool operator<(const BigInt &other) const;

    // 大于运算符
    bool operator>(const BigInt &other) const;
};

#endif //DATA_STRUCTURE_BIGINT_H
