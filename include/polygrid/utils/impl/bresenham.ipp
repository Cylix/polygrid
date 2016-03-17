//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

namespace polygrid {

namespace utils {

//!
//!
//! Ctor
//!
//!

template <typename PointType>
bresenham<PointType>::bresenham(PointType x0, PointType y0,
                                PointType x1, PointType y1,
                                unsigned int step_x, unsigned int step_y)
: m_original_octant(this->determine_octant(x0, y0, x1, y1))
, m_current_point({ x0, y0 })
, m_end_point({ x1, y1 })
, m_dx(this->m_end_point.x - this->m_current_point.x)
, m_dy(this->m_end_point.y - this->m_current_point.y)
, m_D(2 * this->m_dy - this->m_dy)
, m_step_x(step_x)
, m_step_y(step_y)
{
  this->switch_to_octant_zero_from(this->m_original_octant, this->m_current_point);
  this->switch_to_octant_zero_from(this->m_original_octant, this->m_end_point);
}



//!
//!
//! Algorithm
//!
//!

template <typename PointType>
bool
bresenham<PointType>::done(void) const {
  return this->m_current_point.x < this->m_end_point.x and
         this->m_current_point.y < this->m_end_point.y;
}

template <typename PointType>
typename bresenham<PointType>::point
bresenham<PointType>::next(bool check_done) {
  if (check_done && this->done())
    return { this->m_current_point.x, this->m_current_point.y };

  if (this->m_D > 0) {
    this->m_current_point.y += this->m_step_y;
    this->m_D -= (2 * this->m_dx);
  }

  this->m_current_point.x += this->m_step_x;
  this->m_D += (2 * this->m_dy);

  return { this->m_current_point.x, this->m_current_point.y };
}



//!
//!
//! Octant Handling
//!
//!

template <typename PointType>
typename bresenham<PointType>::octant
bresenham<PointType>::determine_octant(PointType x0, PointType y0, PointType x1, PointType y1) const {
  //! Point (x0, y0) is set as the origin. Position of point (x1, y1) determine the octant that charaterizes our situation
  if (x1 >= x0 and y1 >= y0 and x1 >= y1) { return octant::octant_0; }
  if (x1 >= x0 and y1 >= y0 and x1 <= y1) { return octant::octant_1; }
  if (x1 <= x0 and y1 >= y0 and x1 <= y1) { return octant::octant_2; }
  if (x1 <= x0 and y1 >= y0 and x1 >= y1) { return octant::octant_3; }
  if (x1 <= x0 and y1 <= y0 and x1 >= y1) { return octant::octant_4; }
  if (x1 <= x0 and y1 <= y0 and x1 <= y1) { return octant::octant_5; }
  if (x1 >= x0 and y1 <= y0 and x1 <= y1) { return octant::octant_6; }
  if (x1 >= x0 and y1 <= y0 and x1 >= y1) { return octant::octant_7; }

  //! shut up the compiler warning, but it's impossible to reach that return
  return octant::octant_0;
}

template <typename PointType>
void
bresenham<PointType>::switch_to_octant_zero_from(octant octant, signed_point& p) const {
  switch(octant) {
  case octant::octant_0:
    break;

  case octant::octant_1:
    std::swap(p.x, p.y);
    break;

  case octant::octant_2:
    p.x *= -1;
    std::swap(p.x, p.y);
    break;

  case octant::octant_3:
    p.x *= -1;
    break;

  case octant::octant_4:
    p.x *= -1;
    p.y *= -1;
    break;

  case octant::octant_5:
    p.x *= -1;
    p.y *= -1;
    std::swap(p.x, p.y);
    break;

  case octant::octant_6:
    p.y *= -1;
    std::swap(p.x, p.y);
    break;

  case octant::octant_7:
    p.y *= -1;
    break;
  }
}

template <typename PointType>
void
bresenham<PointType>::switch_from_octant_zero_to(octant octant, signed_point& p) const {
  //! same as switch_to_octant_zero_from, but cases 2 and 6 are swapped in order to handle destination octants where signs of x and y are different
  switch(octant) {
  case octant::octant_0:
    break;

  case octant::octant_1:
    std::swap(p.x, p.y);
    break;

  case octant::octant_2:
    p.y *= -1;
    std::swap(p.x, p.y);
    break;

  case octant::octant_3:
    p.x *= -1;
    break;

  case octant::octant_4:
    p.x *= -1;
    p.y *= -1;
    break;

  case octant::octant_5:
    p.x *= -1;
    p.y *= -1;
    std::swap(p.x, p.y);
    break;

  case octant::octant_6:
    p.x *= -1;
    std::swap(p.x, p.y);
    break;

  case octant::octant_7:
    p.y *= -1;
    break;
  }
}

} //! utils

} //! polygrid
