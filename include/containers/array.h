#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <deque>
#include <functional>
#include <initializer_list>
#include <string>
#include <vector>

#include "iterator_utils.h"

namespace containers {

/**
 * This class is a wrapper over STL Vector providing overloaded operators and additional functions to make 
 * the implementation more flexible. 
 */
template <typename val>
class Array {
  public:
    Array() = default;
    explicit Array(int, val val = valueType());
    Array(const std::initializer_list<val>);
    virtual ~Array() = default;
    
    void add(const val);
    Array<val> addAll(const Array<val> &);
    val &back();
    const val &back() const;
    void clear();
    bool contains(const val &) const;
    bool equals(const Array<val> &) const;
    val &front();
    const val &front() const;
    const val &get(const val &) const;
    int indexOf(const val &) const;

    void insert(int, const val &);
    bool isEmpty() const;
    int lastIndexOf(const val &) const;

    void changeAll(std::function<void (const val &)>) const;
    val pop_front();
    val pop_back();
    void push_front(const val &);
    void push_back(const val &);
    void remove(int);
    
    void reverse();
    void set(int, const val &);
    int size() const;
    void shuffle();
    void sort();

    Array<val> subList(int, int) const;
    Array<val> subList(int) const;
    std::string to_string() const;
    
    /**
     * Overloaded operators
     */
    val &operator[](int);
    const val &operator[](int) const;
    Array<val> operator+(const Array<val> &);
    Array<val> operator+(const val &);
    Array<val> &operator+=(const Array<val> &);
    Array<val> &operator+=(const val &);
    Array<val> operator==(const Array<val> &) const;
    Array<val> operator!=(const Array<val> &) const;
    Array<val> operator<(const Array<val> &) const;
    Array<val> operator<=(const Array<val> &) const;
    Array<val> operator>(const Array<val> &) const;
    Array<val> operator>=(const Array<val> &) const;
  
  private:
    using ContainerType = std::conditional<std::is_same<val, bool>::value, 
                                           std::deque<bool>,
                                           std::vector<val>>::type;

    ConditionalType _elements;

  public:
    using iterator = CustomItr<typename ContainerType::iterator>;
    using const_iterator = CustomItr<typename ContainerType::const_iterator>;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

};

}


#endif