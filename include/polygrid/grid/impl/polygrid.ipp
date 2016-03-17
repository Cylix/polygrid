//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

#include <polygrid/utils/bresenham.hpp>

namespace  polygrid {

//!
//!
//! Ctor
//!
//!

template <unsigned int ColSize, unsigned int RowSize>
template <template <class, class> class Container, typename Point, typename Allocator>
polygrid<ColSize, RowSize>::polygrid(const Container<Point, Allocator>& polygon)
{ this->build(polygon); }

template <unsigned int ColSize, unsigned int RowSize>
template <template <class, class> class Container, typename Point, typename Allocator>
auto
polygrid<ColSize, RowSize>::get_min_bounds(const Container<Point, Allocator>& polygon) -> decltype(std::pair<decltype(polygon[0].x), decltype(polygon[0].y)>()) {
  if (polygon.empty()) { return {}; }

  auto curr = polygon.begin();
  auto min_x = curr->x;
  auto min_y = curr->y;

  for (; curr != polygon.end(); ++curr) {
    if (curr->x < min_x) { min_x = curr->x; }
    if (curr->y < min_y) { min_y = curr->y; }
  }

  return { min_x, min_y };
}



//!
//!
//! Build functions
//!
//!

template <unsigned int ColSize, unsigned int RowSize>
template <template <class, class> class Container, typename Point, typename Allocator>
void
polygrid<ColSize, RowSize>::build(const Container<Point, Allocator>& polygon) {
  auto min_bounds = this->get_min_bounds(polygon);
  auto curr_it = polygon.begin();

  while (curr_it != polygon.end()) {
    const auto& curr = *curr_it;

    //! Determine cell position corresponding to the current point
    unsigned int col = curr.x - min_bounds.first / ColSize;
    unsigned int row = curr.y - min_bounds.second / RowSize;

    //! Resize grid if necessary
    if (row > m_grid.size()) { m_grid.resize(row + 1); }
    if (col > m_grid[row].size()) { m_grid[row].resize(col + 1); }

    //! Mark current cell as an edge
    this->m_grid[row][col].mark_as_edge();

    //! Apply bresenham algorithm between curr and next point
    //! if std::next returns end(), then rhs is begin()
    //! this way, we handle the last link from last point to the first one
    auto next = std::next(curr_it);
    this->bresenham_algorithm(curr, next == polygon.end() ? *polygon.begin() : *next, min_bounds);

    curr_it = next;
  }
}

template <unsigned int ColSize, unsigned int RowSize>
template <typename Point, typename PointType>
void
polygrid<ColSize, RowSize>::bresenham_algorithm(const Point& lhs, const Point& rhs, const std::pair<PointType, PointType>& min_bounds) {
  auto x0 = lhs.x - min_bounds.first;
  auto y0 = lhs.y - min_bounds.second;

  auto x1 = rhs.x - min_bounds.first;
  auto y1 = rhs.y - min_bounds.second;

  utils::bresenham<PointType> finder = { x0, y0, x1, y1, ColSize, RowSize };

  while (not finder.done()) {
    auto next = finder.next();

    unsigned int col = next.x / ColSize;
    unsigned int row = next.y / RowSize;
    this->m_grid[row][col].mark_as_edge();
  }
}

} //! polygrid
