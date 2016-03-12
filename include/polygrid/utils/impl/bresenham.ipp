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
: m_step_x(step_x)
, m_step_y(step_y)
{}



//!
//!
//! Algorithm
//!
//!

template <typename PointType>
bool
bresenham<PointType>::done(void) const {
  return false;
}

template <typename PointType>
std::pair<PointType, PointType>
bresenham<PointType>::next(void) {
  return {};
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
}

template <typename PointType>
void
bresenham<PointType>::switch_to_octant_zero_from(octant octant, SignedPointType& x, SignedPointType& y) const {
  switch(octant) {
  case octant::octant_0:
    break;

  case octant::octant_1:
    std::swap(x, y);
    break;

  case octant::octant_2:
    x *= -1;
    std::swap(x, y);
    break;

  case octant::octant_3:
    x *= -1;
    break;

  case octant::octant_4:
    x *= -1;
    y *= -1;
    break;

  case octant::octant_5:
    x *= -1;
    y *= -1;
    std::swap(x, y);
    break;

  case octant::octant_6:
    y *= -1;
    std::swap(x, y);
    break;

  case octant::octant_7:
    y *= -1;
    break;
  }
}

template <typename PointType>
void
bresenham<PointType>::switch_from_octant_zero_to(octant octant, SignedPointType& x, SignedPointType& y) const {
  //! same as switch_to_octant_zero_from, but cases 2 and 6 are swapped in order to handle destination octants where signs of x and y are different
  switch(octant) {
  case octant::octant_0:
    break;

  case octant::octant_1:
    std::swap(x, y);
    break;

  case octant::octant_2:
    y *= -1;
    std::swap(x, y);
    break;

  case octant::octant_3:
    x *= -1;
    break;

  case octant::octant_4:
    x *= -1;
    y *= -1;
    break;

  case octant::octant_5:
    x *= -1;
    y *= -1;
    std::swap(x, y);
    break;

  case octant::octant_6:
    x *= -1;
    std::swap(x, y);
    break;

  case octant::octant_7:
    y *= -1;
    break;
  }
}

} //! utils

} //! polygrid
