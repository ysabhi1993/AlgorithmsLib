#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <deque>
#include <functional>
#include <initializer_list>
#include <string>
#include <vector>

namespace containers {

/**
 * This class is a wrapper over STL Vector providing overloaded operators and additional functions to make 
 * the implementation more flexible. 
 */

template <typename ValueType>
class Array {
  public:
    Array() = default;
    explicit Array(int, ValueType val = valueType());
    Array(const std::initializer_list<ValueType>);
    virtual ~Array() = default;
    
    void add(const ValueType);
    Array<ValueType> addAll(const Array<ValueType> &);
    ValueType &back();
    const ValueType &back() const;
    void clear();
    bool contains(const ValueType &) const;
    bool equals(const Array<ValueType> &) const;
    ValueType &front();
    const ValueType &front() const;
    const ValueType &get(const ValueType &) const;
    int indexOf(const ValueType &) const;

    void insert(int, const ValueType &);
    bool isEmpty() const;
    int lastIndexOf(const ValueType &) const;

    void changeAll(std::function<void (const ValueType &)>) const;
    ValueType pop_front();
    ValueType pop_back();
    void push_front(const ValueType &);
    void push_back(const ValueType &);
    void remove(int);
    
    void reverse();
    void set(int, const ValueType &);
    int size() const;
    void shuffle();
    void sort();

    Array<ValueType> subList(int, int) const;
    Array<ValueType> subList(int) const;
    std::string to_string() const;
    
    ValueType &operator[](int);
    const ValueType &operator[](int) const;
    Array<ValueType> operator+(const Array<ValueType> &);
    Array<ValueType> operator+(const ValueType &);
    Array<ValueType> &operator+=(const Array<ValueType> &);
    Array<ValueType> &operator+=(const ValueType &);
    Array<ValueType> operator==(const Array<ValueType> &) const;
    Array<ValueType> operator!=(const Array<ValueType> &) const;
    Array<ValueType> operator<(const Array<ValueType> &) const;
    Array<ValueType> operator<=(const Array<ValueType> &) const;
    Array<ValueType> operator>(const Array<ValueType> &) const;
    Array<ValueType> operator>=(const Array<ValueType> &) const;
  
  private:
    using ContainerType = std::conditional<std::is_same<ValueType, bool>::value, 
                                           std::deque<bool>,
                                           std::vector<ValueType>>::type;

    ConditionalType _elements;
};

}


#endif