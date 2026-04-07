#include <iostream>
#include "LinearListArray.h"
#include "LinearListLinked.h"
#include "Polynomial.h"
#include "BigInt.h"

void testLinearListArray() {
    std::cout << "========== 顺序表测试 ==========" << std::endl;

    // 创建顺序表
    LinearListArray list(5);

    // 测试插入操作
    std::cout << "\n1. 插入元素:" << std::endl;
    list.append(10);
    list.append(20);
    list.append(30);
    list.insert(1, 15); // 在位置 1 插入 15
    list.print();
    std::cout << "长度：" << list.size() << std::endl;

    // 测试获取元素
    std::cout << "\n2. 获取元素:" << std::endl;
    std::cout << "第 0 个元素：" << list.getValue(0) << std::endl;
    std::cout << "第 2 个元素：" << list.getValue(2) << std::endl;

    // 测试查找
    std::cout << "\n3. 查找元素:" << std::endl;
    std::cout << "元素 15 的位置：" << list.indexOf(15) << std::endl;
    std::cout << "元素 20 的位置：" << list.indexOf(20) << std::endl;

    // 测试前驱后继
    std::cout << "\n4. 前驱和后继:" << std::endl;
    std::cout << "位置 2 的前驱：" << list.pre(2) << std::endl;
    std::cout << "位置 2 的后继：" << list.next(2) << std::endl;

    // 测试删除
    std::cout << "\n5. 删除元素:" << std::endl;
    list.remove(1, 15); // 删除位置 1 的 15
    std::cout << "删除位置 1 的 15 后：";
    list.print();

    list.append(25);
    list.append(35);
    std::cout << "追加 25, 35 后：";
    list.print();

    list.removeValue(20); // 按值删除
    std::cout << "删除值 20 后：";
    list.print();

    // 测试首尾位置
    std::cout << "\n6. 首尾位置:" << std::endl;
    std::cout << "第一个元素位置：" << list.begin() << std::endl;
    std::cout << "最后一个元素位置：" << list.end() << std::endl;

    // 测试清空
    std::cout << "\n7. 清空和判空:" << std::endl;
    std::cout << "清空前是否为空：" << (list.isEmpty() ? "是" : "否") << std::endl;
    list.clear();
    std::cout << "清空后是否为空：" << (list.isEmpty() ? "是" : "否") << std::endl;

    std::cout << "\n================================\n" << std::endl;
}

void testLinearListLinked() {
    std::cout << "========== 链表测试 ==========" << std::endl;

    // 创建链表
    LinearListLinked list;

    // 测试插入操作
    std::cout << "\n1. 插入元素:" << std::endl;
    list.append(10);
    list.append(20);
    list.append(30);
    list.insert(1, 15); // 在位置 1 插入 15
    list.print();
    std::cout << "长度：" << list.size() << std::endl;

    // 测试获取元素
    std::cout << "\n2. 获取元素:" << std::endl;
    std::cout << "第 0 个元素：" << list.getValue(0) << std::endl;
    std::cout << "第 2 个元素：" << list.getValue(2) << std::endl;

    // 测试查找
    std::cout << "\n3. 查找元素:" << std::endl;
    std::cout << "元素 15 的位置：" << list.indexOf(15) << std::endl;
    std::cout << "元素 20 的位置：" << list.indexOf(20) << std::endl;

    // 测试前驱后继
    std::cout << "\n4. 前驱和后继:" << std::endl;
    std::cout << "位置 2 的前驱：" << list.pre(2) << std::endl;
    std::cout << "位置 2 的后继：" << list.next(2) << std::endl;

    // 测试删除
    std::cout << "\n5. 删除元素:" << std::endl;
    list.remove(1, 15); // 删除位置 1 的 15
    std::cout << "删除位置 1 的 15 后：";
    list.print();

    list.append(25);
    list.append(35);
    std::cout << "追加 25, 35 后：";
    list.print();

    list.removeValue(20); // 按值删除
    std::cout << "删除值 20 后：";
    list.print();

    // 测试首尾位置
    std::cout << "\n6. 首尾位置:" << std::endl;
    std::cout << "第一个元素位置：" << list.begin() << std::endl;
    std::cout << "最后一个元素位置：" << list.end() << std::endl;

    // 测试清空
    std::cout << "\n7. 清空和判空:" << std::endl;
    std::cout << "清空前是否为空：" << (list.isEmpty() ? "是" : "否") << std::endl;
    list.clear();
    std::cout << "清空后是否为空：" << (list.isEmpty() ? "是" : "否") << std::endl;

    std::cout << "\n================================\n" << std::endl;
}

void testPolynomial() {
    std::cout << "========== 多项式测试 ==========" << std::endl;
    
    // 创建多项式 P1(x) = 3x^4 + 2x^2 + 5
    std::cout << "\n1. 创建多项式 P1(x) = 3x^4 + 2x^2 + 5" << std::endl;
    Polynomial p1;
    p1.addTerm(5, 0);   // 5
    p1.addTerm(2, 2);   // 2x^2
    p1.addTerm(3, 4);   // 3x^4
    std::cout << "P1(x) = ";
    p1.print();
    std::cout << "项数：" << p1.size() << std::endl;
    
    // 创建多项式 P2(x) = 4x^3 - x^2 + 2
    std::cout << "\n2. 创建多项式 P2(x) = 4x^3 - x^2 + 2" << std::endl;
    Polynomial p2;
    p2.addTerm(2, 0);   // 2
    p2.addTerm(-1, 2);  // -x^2
    p2.addTerm(4, 3);   // 4x^3
    std::cout << "P2(x) = ";
    p2.print();
    std::cout << "项数：" << p2.size() << std::endl;
    
    // 多项式加法
    std::cout << "\n3. 多项式加法 P1(x) + P2(x):" << std::endl;
    Polynomial p3 = p1.add(p2);
    std::cout << "P1(x) + P2(x) = ";
    p3.print();
    
    // 多项式减法
    std::cout << "\n4. 多项式减法 P1(x) - P2(x):" << std::endl;
    Polynomial p4 = p1.subtract(p2);
    std::cout << "P1(x) - P2(x) = ";
    p4.print();
    
    // 多项式乘法
    std::cout << "\n5. 多项式乘法 P1(x) * P2(x):" << std::endl;
    Polynomial p5 = p1.multiply(p2);
    std::cout << "P1(x) * P2(x) = ";
    p5.print();
    
    // 多项式求值
    std::cout << "\n6. 多项式求值:" << std::endl;
    double x = 2.0;
    std::cout << "P1(" << x << ") = " << p1.evaluate(x) << std::endl;
    std::cout << "P2(" << x << ") = " << p2.evaluate(x) << std::endl;
    
    // 清空测试
    std::cout << "\n7. 清空和判空:" << std::endl;
    std::cout << "清空前是否为空：" << (p1.isEmpty() ? "是" : "否") << std::endl;
    p1.clear();
    std::cout << "清空后是否为空：" << (p1.isEmpty() ? "是" : "否") << std::endl;
    
    std::cout << "\n================================\n" << std::endl;
}

void testBigInt() {
    std::cout << "========== 长整数测试 ==========" << std::endl;
    
    // 创建长整数
    std::cout << "\n1. 创建长整数:" << std::endl;
    BigInt num1("123456789012345678901234567890");
    std::cout << "num1 = ";
    num1.print();
    std::cout << "，位数：" << num1.size() << std::endl;
    
    BigInt num2("987654321098765432109876543210");
    std::cout << "num2 = ";
    num2.print();
    std::cout << "，位数：" << num2.size() << std::endl;
    
    // 长整数加法
    std::cout << "\n2. 长整数加法 num1 + num2:" << std::endl;
    BigInt sum = num1.add(num2);
    std::cout << "结果 = ";
    sum.print();
    std::cout << std::endl;
    
    // 长整数减法
    std::cout << "\n3. 长整数减法 num2 - num1:" << std::endl;
    BigInt diff = num2.subtract(num1);
    std::cout << "结果 = ";
    diff.print();
    std::cout << std::endl;
    
    // 负数测试
    std::cout << "\n4. 负数测试:" << std::endl;
    BigInt neg1("-999999999999999999999999999999");
    std::cout << "neg1 = ";
    neg1.print();
    std::cout << std::endl;
    
    BigInt neg2("111111111111111111111111111111");
    std::cout << "neg2 = ";
    neg2.print();
    std::cout << std::endl;
    
    std::cout << "neg1 + neg2 = ";
    BigInt sum2 = neg1.add(neg2);
    sum2.print();
    std::cout << std::endl;
    
    // 比较大小
    std::cout << "\n5. 比较大小:" << std::endl;
    std::cout << "num1 > num2: " << (num1 > num2 ? "true" : "false") << std::endl;
    std::cout << "num1 < num2: " << (num1 < num2 ? "true" : "false") << std::endl;
    std::cout << "num1 == num2: " << (num1 == num2 ? "true" : "false") << std::endl;
    
    // 超大数测试（接近 100 位）
    std::cout << "\n6. 超大数测试（100 位）:" << std::endl;
    BigInt big1("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    BigInt big2("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
    std::cout << "big1 = ";
    big1.print();
    std::cout << "\nbig2 = ";
    big2.print();
    std::cout << "\nbig1 + big2 = ";
    BigInt bigSum = big1.add(big2);
    bigSum.print();
    std::cout << std::endl;
    
    std::cout << "\n================================\n" << std::endl;
}

int main() {
    std::cout << "线性表基本操作实现与测试" << std::endl;
    std::cout << "========================\n" << std::endl;

    // 测试顺序表
    testLinearListArray();

    // 测试链表
    testLinearListLinked();
    
    // 测试多项式
    testPolynomial();
    
    // 测试长整数
    testBigInt();

    return 0;
}
