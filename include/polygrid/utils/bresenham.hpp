//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

#pragma once

namespace polygrid {

namespace utils {

template <typename PointType>
class bresenham {
public:
  //! ctor & dtor
  bresenham(PointType x0, PointType y0,
            PointType x1, PointType y1,
            unsigned int step_x, unsigned int step_y);
  ~bresenham(void) = default;

  //! copy ctor & assignment operator
  bresenham(const bresenham&) = default;
  bresenham& operator=(const bresenham&) = default;

  //! move operator
  bresenham(bresenham&&) = default;
  bresenham& operator=(bresenham&&) = default;

public:
  //! return whether the algorithm has finished to return all the cells on the way from point A to B
  bool done(void) const;

  //! return the coordinate of the next cell that is on the way from point A to point B
  std::pair<PointType, PointType> next(void);

private:
  unsigned int m_step_x;
  unsigned int m_step_y;
};

} //! utils

} //! polygrid

#include <polygrid/utils/impl/bresenham.ipp>
