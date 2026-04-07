// 由数组实现的线性表

#ifndef DATA_STRUCTURE_LINEARLISTARRAY_H
#define DATA_STRUCTURE_LINEARLISTARRAY_H


class LinearListArray {
private:
    int *data; // 存储数据的数组
    int length; // 当前线性表长度
    int capacity; // 最大容量

public:
    // 构造函数
    explicit LinearListArray(int size = 10);

    // 析构函数
    ~LinearListArray();

    // 查找表中第pos个元素的前驱
    [[nodiscard]] int pre(int pos) const;

    // 查找表中第pos个元素的后继
    [[nodiscard]] int next(int pos) const;

    // 显示表中的数据
    void print() const;

    // 定位线性表第一个元素
    [[nodiscard]] int begin() const;

    // 定位线性表最后一个元素
    [[nodiscard]] int end() const;

    // 求线性表第pos个元素
    [[nodiscard]] int getValue(int pos) const;

    // 查找满足给定条件的数据元素
    [[nodiscard]] int indexOf(int value) const;

    // 删除线性表中的第 pos 个值为 value 的数据元素
    void remove(int pos, int value);

    // 按值删除元素
    void removeValue(int value);

    // 在线性表的第 pos 个位置之前插入一个新的值为 value 的数据元素
    void insert(int pos, int value);

    // 在末尾追加元素
    void append(int value);

    // 清空线性表
    void clear();

    // 判断线性表是否为空
    [[nodiscard]] bool isEmpty() const;

    // 获取线性表长度
    [[nodiscard]] int size() const;

private:
    // 扩容
    void expand(int newCapacity);
};


#endif //DATA_STRUCTURE_LINEARLISTARRAY_H
