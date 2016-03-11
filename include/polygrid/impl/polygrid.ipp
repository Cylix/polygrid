//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

namespace  polygrid {

template <unsigned int COL_SIZE, unsigned int ROW_SIZE>
template <template <class, class> class Container, typename Point, typename Allocator>
polygrid<COL_SIZE, ROW_SIZE>::polygrid(const Container<Point, Allocator>& polygon)
: m_bounds(polygon)
, m_grid({ this->m_bounds.width() / COL_SIZE + 1, { this->m_bounds.height() / ROW_SIZE + 1, {} } })
{ this->build(polygon); }

template <unsigned int COL_SIZE, unsigned int ROW_SIZE>
template <template <class, class> class Container, typename Point, typename Allocator>
void
polygrid<COL_SIZE, ROW_SIZE>::build(const Container<Point, Allocator>& polygon) {
  for (auto prev_it = polygon.end(), curr_it = polygon.begin(); curr_it != polygon.end(); prev_it = curr_it, ++curr_it) {
    const auto& curr = *curr_it;

    int col = curr.x - this->m_bounds.min_x() / COL_SIZE;
    int row = curr.y - this->m_bounds.min_y() / ROW_SIZE;

    this->m_grid[row][col].set_state(polycell::state::edge);

    // if (prev_it != polygon.end()) {
    //   const auto& prev = *curr_it;
    // }
  }
}

} //! polygrid
