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
  //! We need to operate signed operations in the bresenham algorithm
  //! However, polygrid should be generic enough to handle any type of points, including unsigned ones
  //! This means that we need to convert from unsigned to signed
  typedef typename std::conditional<std::is_unsigned<PointType>::value, std::make_signed<PointType>, PointType>::type SignedPointType;

private:
  //! Octants
  //!      y
  //!    \2|1/
  //!    3\|/0
  //! x ---+--- x
  //!    4/|\7
  //!    /5|6\
  //!      y
  enum class octant { octant_0, octant_1, octant_2, octant_3, octant_4, octant_5, octant_6, octant_7 };

  //! determine the octant associated to the 2 given points (x0, y0) and (x1, y1)
  octant determine_octant(PointType x0, PointType y0, PointType x1, PointType y1) const;

  //! functions to switch from an octant to another
  //! this is very useful because bresenham algorithm is only intended to work for octant 0
  //! so we have to switch our input from any octant to octant 0 and to switch our output from octant 0 to the original octant
  void switch_to_octant_zero_from(octant octant, SignedPointType& x, SignedPointType& y) const;
  void switch_from_octant_zero_to(octant octant, SignedPointType& x, SignedPointType& y) const;

private:
  unsigned int m_step_x;
  unsigned int m_step_y;
};

} //! utils

} //! polygrid

#include <polygrid/utils/impl/bresenham.ipp>
