#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <deque>
#include <functional>
#include <initializer_list>
#include <string>
#include <vector>

#include "lib/iterator_utils.h"

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
    
    void add(const val input);
    Array<val> addAll(const Array<val> & input);
    val &back();
    const val &back() const;
    void clear();
    bool contains(const val &input) const;
    bool equals(const Array<val> &input) const;
    val &front();
    const val &front() const;
    const val &get(const val &input) const;
    int indexOf(const val &input) const;

    void insert(int, const val &input);
    bool isEmpty() const;
    int lastIndexOf(const val &input) const;

    void changeAll(std::function<void (const val &)> input) const;
    val pop_front();
    val pop_back();
    void push_front(const val &input);
    void push_back(const val &input);
    void remove(int index);
    
    void reverse();
    void set(int index, const val &input);
    int size() const;
    void shuffle();
    void sort();

    Array<val> subList(int index1, int index2) const;
    Array<val> subList(int index) const;
    std::string to_string() const;
    
    /**
     * Overloaded operators
     */
    val &operator[](int index);
    const val &operator[](int index) const;
    Array<val> operator+(const Array<val> &input);
    Array<val> operator+(const val &input);
    Array<val> &operator+=(const Array<val> &input);
    Array<val> &operator+=(const val &input);
    Array<val> operator==(const Array<val> &input) const;
    Array<val> operator!=(const Array<val> &input) const;
    Array<val> operator<(const Array<val> &input) const;
    Array<val> operator<=(const Array<val> &input) const;
    Array<val> operator>(const Array<val> &input) const;
    Array<val> operator>=(const Array<val> &input) const;
  
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