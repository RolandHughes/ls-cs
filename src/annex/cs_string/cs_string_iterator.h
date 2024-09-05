/***********************************************************************
*
* Copyright (c) 2017-2024 Barbara Geller
* Copyright (c) 2017-2024 Ansel Sermersheim
*
* This file is part of LsCsString.
*
* LsCsString is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* LsCsString is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#ifndef LIB_CS_STRING_ITERATOR_H
#define LIB_CS_STRING_ITERATOR_H

#include <cstddef>
#include <vector>

#include <cs_char.h>

namespace LsCsString {

class LIB_CS_STRING_EXPORT CsCharArrow
{
   public:
      CsCharArrow (CsChar c)
         : m_data(c)
      { }

      const CsChar *operator->() const {
         return &m_data;
      }

   private:
      CsChar m_data;
};

template <typename E, typename A>
class LsCsStringIterator
{
   using v_iter = typename std::vector<typename E::storage_unit, A>::const_iterator;

   public:
      using difference_type   = std::ptrdiff_t;
      using pointer           = CsChar *;
      using reference         = CsChar;
      using size_type         = std::ptrdiff_t;
      using value_type        = CsChar;
      using iterator_category = std::random_access_iterator_tag;

      LsCsStringIterator() = default;

      CsChar operator*() const;
      CsCharArrow operator->() const;

      CsChar operator[](size_type n) const;

      // comparisons
      bool operator!=(const LsCsStringIterator &other) const;
      bool operator==(const LsCsStringIterator &other) const;
      bool operator<(const LsCsStringIterator &other) const;
      bool operator<=(const LsCsStringIterator &other) const;
      bool operator>(const LsCsStringIterator &other) const;
      bool operator>=(const LsCsStringIterator &other) const;

      // math
      LsCsStringIterator &operator+=(size_type n);
      LsCsStringIterator &operator-=(size_type n);

      LsCsStringIterator operator+(size_type n) const;
      LsCsStringIterator &operator++();
      LsCsStringIterator operator++(int);

      LsCsStringIterator operator-(size_type n) const;
      size_type operator-(LsCsStringIterator other) const;
      LsCsStringIterator &operator--();
      LsCsStringIterator operator--(int);

      typename std::pair<v_iter, v_iter> codePointRange() const;

      LsCsStringIterator advance_storage(size_type n) const;
      v_iter codePointBegin() const;
      v_iter codePointEnd() const;

   private:
      explicit LsCsStringIterator(v_iter data);
      v_iter m_iter;

      friend class CsBasicString<E, A>;
};

template <typename E, typename A>
CsChar LsCsStringIterator<E,A>::operator*() const
{
   return E::getCodePoint(m_iter);
}

template <typename E, typename A>
CsCharArrow LsCsStringIterator<E,A>::operator->() const
{
   return E::getCodePoint(m_iter);
}

template <typename E, typename A>
CsChar LsCsStringIterator<E,A>:: operator[](size_type n) const
{
   // calls operator+()
   return *(*this + n);
}

// comparisons
template <typename E, typename A>
bool LsCsStringIterator <E,A>::operator!=(const LsCsStringIterator &other) const
{
   return m_iter != other.m_iter;
}

template <typename E, typename A>
bool LsCsStringIterator <E,A>::operator==(const LsCsStringIterator &other) const
{
   return m_iter == other.m_iter;
}

template <typename E, typename A>
bool LsCsStringIterator <E,A>::operator<(const LsCsStringIterator &other) const
{
   return m_iter < other.m_iter;
}

template <typename E, typename A>
bool LsCsStringIterator <E,A>::operator<=(const LsCsStringIterator &other) const
{
   return m_iter <= other.m_iter;
}

template <typename E, typename A>
bool LsCsStringIterator <E,A>::operator>(const LsCsStringIterator &other) const
{
   return m_iter > other.m_iter;
}

template <typename E, typename A>
bool LsCsStringIterator <E,A>::operator>=(const LsCsStringIterator &other) const
{
   return m_iter >= other.m_iter;
}

// math
template <typename E, typename A>
LsCsStringIterator<E,A> &LsCsStringIterator<E,A>::operator+=(size_type n)
{
   m_iter += E::walk(n, m_iter);
   return *this;
}

template <typename E, typename A>
LsCsStringIterator<E,A> &LsCsStringIterator<E,A>::operator-=(size_type n)
{
   m_iter += E::walk(-n, m_iter);
   return *this;
}

template <typename E, typename A>
LsCsStringIterator<E,A> LsCsStringIterator<E,A>::operator+(size_type n) const
{
   auto iter = m_iter + E::walk(n, m_iter);
   return LsCsStringIterator(iter);
}

template <typename E, typename A>
LsCsStringIterator<E,A> &LsCsStringIterator<E,A>::operator++()
{
   m_iter += E::walk(1, m_iter);
   return *this;
}

template <typename E, typename A>
LsCsStringIterator<E,A> LsCsStringIterator<E,A>::operator++(int)
{
   LsCsStringIterator retval = *this;
   m_iter += E::walk(1, m_iter);

   return retval;
}

template <typename E, typename A>
LsCsStringIterator<E,A> LsCsStringIterator<E,A>::operator-(size_type n) const
{
   auto iter = m_iter + E::walk(-n, m_iter);
   return LsCsStringIterator(iter);
}

template <typename E, typename A>
typename LsCsStringIterator<E, A>::size_type LsCsStringIterator <E,A>::operator-(LsCsStringIterator other) const
{
   LsCsStringIterator a = *this;
   LsCsStringIterator b = other;

   if (a < b) {
      return 0 - E::distance(a.m_iter, b.m_iter);

   } else {
      return E::distance(b.m_iter, a.m_iter);

   }
}

template <typename E, typename A>
LsCsStringIterator<E,A> &LsCsStringIterator<E,A>::operator--()
{
   m_iter+= E::walk(-1, m_iter);
   return *this;
}

template <typename E, typename A>
LsCsStringIterator<E,A> LsCsStringIterator<E,A>::operator--(int)
{
   LsCsStringIterator retval = *this;
   m_iter += E::walk(-1, m_iter);

   return retval;
}

// private methods
template <typename E, typename A>
LsCsStringIterator<E,A>::LsCsStringIterator(v_iter data)
{
   m_iter = data;
}

template <typename E, typename A>
auto LsCsStringIterator<E,A>::codePointRange() const -> typename std::pair<v_iter, v_iter>
{
   return std::make_pair(m_iter, m_iter + E::walk(1, m_iter));
}

template <typename E, typename A>
LsCsStringIterator<E,A> LsCsStringIterator<E,A>::advance_storage(size_type n) const
{
   LsCsStringIterator retval = LsCsStringIterator(m_iter + n);
   return retval;
}

template <typename E, typename A>
auto LsCsStringIterator<E,A>::codePointBegin() const -> v_iter
{
   return m_iter;
}

template <typename E, typename A>
auto LsCsStringIterator<E,A>::codePointEnd() const -> v_iter
{
   return m_iter + E::walk(1, m_iter);
}

// reverse iterator dereference needs to return by value
template <typename T>
class LsCsStringReverseIterator : public std::reverse_iterator<T>
{
   public:
      LsCsStringReverseIterator() = default;

      LsCsStringReverseIterator(T iter)
         : std::reverse_iterator<T>(iter)
      {
      }

      template <typename U>
      LsCsStringReverseIterator(LsCsStringReverseIterator<U> iter)
         : std::reverse_iterator<T>(iter.base())
      {
      }

      decltype(std::declval<T>().operator*())  operator*() const;
      decltype(std::declval<T>().operator->()) operator->() const;
};

template <typename T>
decltype(std::declval<T>().operator*()) LsCsStringReverseIterator<T>::operator*() const
{
   auto tmp = this->base();
   return (--tmp).operator*();
}

template <typename T>
decltype(std::declval<T>().operator->()) LsCsStringReverseIterator<T>::operator->() const
{
   auto tmp = this->base();
   return (--tmp).operator->();
}

}

#endif
