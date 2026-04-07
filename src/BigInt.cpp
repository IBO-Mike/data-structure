// 长整数类实现

#include "BigInt.h"
#include <cctype>


// 默认构造函数
BigInt::BigInt() : head(nullptr), isNegative(false), length(0) {
}

// 从字符串构造
BigInt::BigInt(const std::string &numStr) : head(nullptr), isNegative(false), length(0) {

    // 如果字符串为空，直接返回
    if (numStr.empty()) return;

    size_t start = 0;
    if (numStr[0] == '-') {
        isNegative = true;
        start = 1;
    } else if (numStr[0] == '+') {
        start = 1;
    }

    // 反转存储，低位在前
    for (int i = numStr.length() - 1; i >= (int) start; --i) {
        if (std::isdigit(numStr[i])) {
            BigIntNode *newNode = new BigIntNode(numStr[i] - '0');
            if (head == nullptr) {
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
    }

    // 处理结果为 0 的情况
    if (length == 0) {
        isNegative = false;
    }
}

// 从整数构造
BigInt::BigInt(long long num) : head(nullptr), isNegative(false), length(0) {
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    if (num == 0) {
        BigIntNode *newNode = new BigIntNode(0);
        head = newNode;
        length = 1;
        return;
    }

    while (num > 0) {
        BigIntNode *newNode = new BigIntNode(num % 10);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        num /= 10;
        length++;
    }
}

// 析构函数
BigInt::~BigInt() {
    clear();
}

// 拷贝构造函数
BigInt::BigInt(const BigInt &other) : head(nullptr), isNegative(other.isNegative), length(0) {
    BigIntNode *current = other.head;
    while (current != nullptr) {
        BigIntNode *newNode = new BigIntNode(current->digit);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
        current = current->next;
    }
}

// 赋值运算符重载
BigInt &BigInt::operator=(const BigInt &other) {
    if (this == &other) return *this;

    clear();
    isNegative = other.isNegative;

    BigIntNode *current = other.head;
    while (current != nullptr) {
        BigIntNode *newNode = new BigIntNode(current->digit);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
        current = current->next;
    }

    return *this;
}

// 比较大小：返回 1 (大于), 0 (等于), -1 (小于)
int BigInt::compare(const BigInt &other) const {
    // 先比较符号
    if (isNegative && !other.isNegative) return -1;
    if (!isNegative && other.isNegative) return 1;

    // 同符号时比较绝对值
    bool bothNegative = isNegative && other.isNegative;

    // 比较位数
    if (length > other.length) return bothNegative ? -1 : 1;
    if (length < other.length) return bothNegative ? 1 : -1;

    // 位数相同，从高位开始比较
    BigIntNode *p1 = head;
    BigIntNode *p2 = other.head;

    // 找到尾节点
    while (p1->next != nullptr) p1 = p1->next;
    while (p2->next != nullptr) p2 = p2->next;

    // 从高位（尾部）向前比较
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->digit > p2->digit) return bothNegative ? -1 : 1;
        if (p1->digit < p2->digit) return bothNegative ? 1 : -1;

        // 向前移动
        BigIntNode *temp1 = head;
        BigIntNode *temp2 = head;

        // 找到 p1 的前一个节点
        while (temp1 != nullptr && temp1->next != p1) temp1 = temp1->next;
        while (temp2 != nullptr && temp2->next != p2) temp2 = temp2->next;

        p1 = temp1;
        p2 = temp2;
    }

    return 0;
}

// 加法
BigInt BigInt::add(const BigInt &other) const {
    // 如果符号不同，转换为减法
    if (isNegative != other.isNegative) {
        BigInt temp = other;
        temp.isNegative = !temp.isNegative;
        return subtract(temp);
    }

    BigInt result;
    result.isNegative = isNegative;

    // 反转链表以便从低位开始计算
    auto reverseList = [](BigIntNode *node) -> BigIntNode * {
        BigIntNode *prev = nullptr;
        BigIntNode *current = node;
        while (current != nullptr) {
            BigIntNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    };

    BigIntNode *p1 = reverseList(head);
    BigIntNode *p2 = reverseList(other.head);

    int carry = 0;
    BigIntNode *tail = nullptr;

    while (p1 != nullptr || p2 != nullptr || carry > 0) {
        int sum = carry;
        if (p1 != nullptr) {
            sum += p1->digit;
            p1 = p1->next;
        }
        if (p2 != nullptr) {
            sum += p2->digit;
            p2 = p2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        BigIntNode *newNode = new BigIntNode(digit);
        if (result.head == nullptr) {
            result.head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        result.length++;
    }

    // 恢复原链表
    reverseList(head);
    reverseList(other.head);

    // 结果链表目前是正向的，需要反转为低位在前
    result.head = reverseList(result.head);

    return result;
}

// 减法（假设 |this| >= |other|）
BigInt BigInt::subtract(const BigInt &other) const {
    // 如果符号不同
    if (isNegative != other.isNegative) {
        BigInt temp = other;
        temp.isNegative = !temp.isNegative;
        return add(temp);
    }

    // 同号时，根据绝对值大小决定运算方式
    int cmp = compare(other);
    if (cmp == 0) {
        return BigInt(0); // 相等时结果为 0
    }

    // 确定被减数和减数
    const BigInt *bigger = this;
    const BigInt *smaller = &other;
    bool resultNegative = false;

    if (cmp < 0) {
        if (isNegative) {
            // 都是负数，|this| < |other|，结果为正
            resultNegative = false;
        } else {
            // 都是正数，this < other，结果为负
            resultNegative = true;
        }
        bigger = &other;
        smaller = this;
    } else {
        resultNegative = isNegative;
    }

    BigInt result;
    result.isNegative = resultNegative;

    // 反转链表以便从低位开始计算
    auto reverseList = [](BigIntNode *node) -> BigIntNode * {
        BigIntNode *prev = nullptr;
        BigIntNode *current = node;
        while (current != nullptr) {
            BigIntNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    };

    BigIntNode *p1 = reverseList(bigger->head);
    BigIntNode *p2 = reverseList(smaller->head);

    int borrow = 0;
    BigIntNode *tail = nullptr;

    while (p1 != nullptr) {
        int diff = p1->digit - borrow;
        if (p2 != nullptr) {
            diff -= p2->digit;
            p2 = p2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        BigIntNode *newNode = new BigIntNode(diff);
        if (result.head == nullptr) {
            result.head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        result.length++;

        p1 = p1->next;
    }

    // 恢复原链表
    reverseList(bigger->head);
    reverseList(smaller->head);

    // 去除前导零
    while (result.length > 1 && result.head->next != nullptr) {
        BigIntNode *last = result.head;
        BigIntNode *secondLast = nullptr;

        while (last->next != nullptr) {
            secondLast = last;
            last = last->next;
        }

        if (last->digit != 0) break;

        if (secondLast != nullptr) {
            secondLast->next = nullptr;
        } else {
            result.head = nullptr;
        }

        delete last;
        result.length--;
    }

    // 结果链表目前是正向的，需要反转为低位在前
    result.head = reverseList(result.head);

    // 如果结果为 0，设置为正数
    if (result.length == 1 && result.head->digit == 0) {
        result.isNegative = false;
    }

    return result;
}

// 加法运算符重载
BigInt BigInt::operator+(const BigInt &other) const {
    return add(other);
}

// 减法运算符重载
BigInt BigInt::operator-(const BigInt &other) const {
    return subtract(other);
}

// 显示长整数
void BigInt::print() const {
    if (head == nullptr) {
        std::cout << "0";
        return;
    }

    if (isNegative) {
        std::cout << "-";
    }

    // 从高位到低位输出（需要反向遍历）
    // 先找到尾节点
    BigIntNode *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // 反向输出
    while (current != nullptr) {
        std::cout << current->digit;

        // 找到前一个节点
        BigIntNode *prev = head;
        while (prev != nullptr && prev->next != current) {
            prev = prev->next;
        }
        current = prev;
    }
}

// 获取位数
int BigInt::size() const {
    return length;
}

// 判断是否为空（值为 0）
bool BigInt::isZero() const {
    return length == 1 && head != nullptr && head->digit == 0;
}

// 判断正负
bool BigInt::isPositive() const {
    return !isNegative && !isZero();
}

// 清空
void BigInt::clear() {
    while (head != nullptr) {
        BigIntNode *temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
    isNegative = false;
}

// 等于运算符
bool BigInt::operator==(const BigInt &other) const {
    return compare(other) == 0;
}

// 不等于运算符
bool BigInt::operator!=(const BigInt &other) const {
    return compare(other) != 0;
}

// 小于运算符
bool BigInt::operator<(const BigInt &other) const {
    return compare(other) < 0;
}

// 大于运算符
bool BigInt::operator>(const BigInt &other) const {
    return compare(other) > 0;
}
