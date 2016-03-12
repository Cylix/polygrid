//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

#pragma once

#include <polygrid/grid/polycell.hpp>

#include <vector>

namespace polygrid {

template <unsigned int ColSize, unsigned int RowSize>
class polygrid {
public:
  //! ctor & dtor
  //! ctor calls build member function
  template <template <class, class> class Container, typename Point, typename Allocator>
  explicit polygrid(const Container<Point, Allocator>& polygon);
  ~polygrid(void) = default;

  //! copy ctor & assignment operator
  polygrid(const polygrid<ColSize, RowSize>& polygrid) = default;
  polygrid<ColSize, RowSize>& operator=(const polygrid<ColSize, RowSize>&) = default;

  //! move operator
  polygrid(polygrid<ColSize, RowSize>&& polygrid) = default;
  polygrid<ColSize, RowSize>& operator=(polygrid<ColSize, RowSize>&&) = default;

private:
  //! build the internal grid reprensatation from the input polygon (collection of points)
  template <template <class, class> class Container, typename Point, typename Allocator>
  void build(const Container<Point, Allocator>& polygon);

  //! apply bresenham algorithm on the given two points
  //! the goal is to mark all the cell that are between two points as polygon edges
  template <typename Point, typename PointType>
  void bresenham_algorithm(const Point& lhs, const Point& rhs, const std::pair<PointType, PointType>& min_bounds);

  //! return minimum x and y values in the given dataset of point
  //! use auto return type combined with decltype to be as generic as possible concerning the point abstract datatype
  template <template <class, class> class Container, typename Point, typename Allocator>
  auto get_min_bounds(const Container<Point, Allocator>& polygon) -> decltype(std::pair<decltype(polygon[0].x), decltype(polygon[0].y)>());

private:
  std::vector<std::vector<polycell>> m_grid;
};

} //! polygrid

#include <polygrid/grid/impl/polygrid.ipp>
