// 一元多项式类 - 使用链表实现
// 只存储系数非零的项

#ifndef DATA_STRUCTURE_POLYNOMIAL_H
#define DATA_STRUCTURE_POLYNOMIAL_H

struct PolyNode {
    int coefficient;  // 系数
    int exponent;     // 指数
    PolyNode* next;   // 指针域
    
    PolyNode(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    PolyNode* head;   // 头指针
    int length;       // 项数

public:
    // 构造函数
    Polynomial();
    
    // 析构函数
    ~Polynomial();
    
    // 拷贝构造函数
    Polynomial(const Polynomial& other);
    
    // 赋值运算符重载
    Polynomial& operator=(const Polynomial& other);
    
    // 添加项（按指数降序排列）
    void addTerm(int coefficient, int exponent);
    
    // 多项式加法
    [[nodiscard]] Polynomial add(const Polynomial& other) const;
    
    // 多项式减法
    [[nodiscard]] Polynomial subtract(const Polynomial& other) const;
    
    // 多项式乘法
    [[nodiscard]] Polynomial multiply(const Polynomial& other) const;
    
    // 显示多项式
    void print() const;
    
    // 获取项数
    [[nodiscard]] int size() const;
    
    // 判断是否为空
    [[nodiscard]] bool isEmpty() const;
    
    // 清空多项式
    void clear();
    
    // 求值（给定 x 的值）
    [[nodiscard]] double evaluate(double x) const;
};

#endif //DATA_STRUCTURE_POLYNOMIAL_H
