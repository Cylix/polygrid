//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

namespace polygrid {

namespace utils {

template <typename PointType>
bresenham<PointType>::bresenham(PointType x0, PointType y0,
                                PointType x1, PointType y1,
                                unsigned int step_x, unsigned int step_y)
: m_step_x(step_x)
, m_step_y(step_y)
{}

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

} //! utils

} //! polygrid
