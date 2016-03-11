//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

#pragma once

#include <polygrid/polycell.hpp>
#include <polygrid/polybounds.hpp>

#include <vector>

namespace polygrid {

template <unsigned int COL_SIZE, unsigned int ROW_SIZE>
class polygrid {
public:
  //! ctor & dtor
  //! ctor calls build member function
  template <template <class, class> class Container, typename Point, typename Allocator>
  explicit polygrid(const Container<Point, Allocator>& polygon);
  ~polygrid(void) = default;

  //! copy ctor & assignment operator
  polygrid(const polygrid<COL_SIZE, ROW_SIZE>& polygrid) = default;
  polygrid<COL_SIZE, ROW_SIZE>& operator=(const polygrid<COL_SIZE, ROW_SIZE>&) = default;

  //! move operator
  polygrid(polygrid<COL_SIZE, ROW_SIZE>&& polygrid) = default;
  polygrid<COL_SIZE, ROW_SIZE>& operator=(polygrid<COL_SIZE, ROW_SIZE>&&) = default;

private:
  //! build the internal grid reprensatation from the input polygon (collection of points)
  template <template <class, class> class Container, typename Point, typename Allocator>
  void build(const Container<Point, Allocator>& polygon);

private:
  polybounds m_bounds;
  std::vector<std::vector<polycell>> m_grid;
};

} //! polygrid

#include <polygrid/impl/polygrid.ipp>
