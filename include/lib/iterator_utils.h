#ifndef ITERATOR_UTILS
#define ITERATOR_UTILS

#include <iterator>

template <typename Itr>
class CustomItr {
  public:
    using difference_type = typename std::iterator_traits<Itr>::difference_type;
    using value_type = typename std::iterator_traits<Itr>::value_type;
    using pointer = typename std::iterator_traits<Itr>::pointer;
    using reference = typename std::iterator_traits<Itr>::reference;
    using iter_category = typename std::iterator_traits<Itr>::iter_category;

    CustomItr() = default;
    
    template <typename Container>
    CustomItr(Itr iter, Container &c) :_iter(iter), _begin(c.begin()), _end(c.end()) {}

    /* Iterator overloaded operators */

    template <typename OtherItr> bool operator ==(const CustomItr<OtherItr> &rhs) const;
    template <typename OtherItr> bool operator !=(const CustomItr<OtherItr> &rhs) const;
    template <typename OtherItr> bool operator <=(const CustomItr<OtherItr> &rhs) const;
    template <typename OtherItr> bool operator <(const CustomItr<OtherItr> &rhs) const;
    template <typename OtherItr> bool operator >=(const CustomItr<OtherItr> &rhs) const;
    template <typename OtherItr> bool operator >(const CustomItr<OtherItr> &rhs) const;

    reference operator[](difference_type index) const;
    reference operator *() const;
    pointer operator ->() const;

    CustomItr& operator +=(difference_type index);
    CustomItr& operator -=(difference_type index);
    CustomItr& operator +(difference_type index) const;
    CustomItr& operator -(difference_type index) const;
    CustomItr& operator ++();
    CustomItr& operator --();

  private:
    Itr _iter;
    Itr _begin, _end;

};

#endif //ITERATOR_UTILS