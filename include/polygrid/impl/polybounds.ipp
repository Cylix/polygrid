//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

namespace polygrid {

template <template <class, class> class Container, typename Point, typename Allocator>
polybounds::polybounds(const Container<Point, Allocator>& polygon)
: m_min_x(0)
, m_max_x(0)
, m_min_y(0)
, m_max_y(0)
{ this->build(polygon); }

template <template <class, class> class Container, typename Point, typename Allocator>
void
polybounds::build(const Container<Point, Allocator>& polygon) {
  if (polygon.empty())
    return ;

  auto curr = polygon.begin();
  this->m_min_x = curr->x;
  this->m_max_x = curr->x;
  this->m_min_y = curr->y;
  this->m_max_y = curr->y;

  for (; curr != polygon.end(); ++curr) {
    if (curr->x < this->m_min_x) { this->m_min_x = curr->x; }
    else if (curr->x > this->m_max_x) { this->m_max_x = curr->x; }

    if (curr->y < this->m_min_y) { this->m_min_x = curr->y; }
    else if (curr->y > this->m_max_y) { this->m_max_x = curr->y; }
  }
}

} //! polygrid
