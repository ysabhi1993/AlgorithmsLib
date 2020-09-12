#ifndef DEQUE_H
#define DEQUE_H

#include <deque>
#include <initializer_list>

#include "lib/iterator_utils.h"

namespace container {


template <typename val>
class Deque {
  public:
    Deque() = default;
    Deque(std::initializer_list<val> list);
    virtual ~Deque() = default;

    /**
     * Adds element  
     */
    void add(const val& input);
    void addFront(const val& input);
    void addBack(const val& input);
    void enqueue(const val &input);
    void enqueueFront(const val &input);
    void enqueueBack(const val &input);

    const val& front() const;
    const val& back() const;
    void clear();
    bool isEmpty() const;
    int size() const;
    bool equal(const Deque<val> &deque) const;

    /**
     * Removes and returns element
     */
    val remove();
    val removeFront();
    val removeBack();
    val dequeue();
    val dequeueFront();
    val dequeueBack();

    /**
     * Returns without removing values; 
     */
    val& peek() const;
    val& peekFront() const;
    val& peekBack() const;

    /**
     * Overloaded operators
     */
    bool operator==(const Deque<val>& deque) const;
    bool operator!=(const Deque<val>& deque) const;
    bool operator<=(const Deque<val>& deque) const;
    bool operator<(const Deque<val>& deque) const;
    bool operator>=(const Deque<val>& deque) const;
    bool operator>(const Deque<val>& deque) const;

  private:
    std::deque<val> _elements;

  public:
    using iterator = CustomItr<typename std::deque<val>::iterator>;
    using const_iterator = CustomItr<typename std::deque<val>::const_iterator>;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

};


}

#endif