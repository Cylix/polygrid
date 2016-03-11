//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

#pragma once

namespace polygrid {

  class polybounds {
  public:
    //! ctor & dtor
    template <template <class, class> class Container, typename Point, typename Allocator>
    explicit polybounds(const Container<Point, Allocator>& polygon);
    ~polybounds(void) = default;

    //! copy ctor & assignment operator
    polybounds(const polybounds& polybounds) = default;
    polybounds& operator=(const polybounds&) = default;

    //! move operator
    polybounds(polybounds&& polybounds) = default;
    polybounds& operator=(polybounds&&) = default;

  private:
    //! build the internal grid reprensatation from the input polygon (collection of points)
    template <template <class, class> class Container, typename Point, typename Allocator>
    void build(const Container<Point, Allocator>& polygon);

  public:
    //! x dimension getters
    inline int width(void) const { return this->m_max_x - this->m_min_x; }
    inline int min_x(void) const { return this->m_min_x; }
    inline int max_x(void) const { return this->m_max_x; }

    //! y dimension getters
    inline int min_y(void) const { return this->m_max_y - this->m_min_y; }
    inline int max_y(void) const { return this->m_min_y; }
    inline int height(void) const { return this->m_max_y; }

  private:
    int m_min_x;
    int m_max_x;
    int m_min_y;
    int m_max_y;
  };

} //! polygrid

#include <polygrid/impl/polybounds.ipp>
