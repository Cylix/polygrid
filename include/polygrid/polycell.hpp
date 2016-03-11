//
// Copyright (c) 2016 by Simon Ninon. All Rights Reserved.
//

namespace polygrid {

class polycell {
public:
  //! ctor & dtor
  polycell(void) = default;
  ~polycell(void) = default;

  //! copy ctor & assignment operator
  polycell(const polycell&) = default;
  polycell& operator=(const polycell&) = default;

  //! move operator
  polycell(polycell&&) = default;
  polycell& operator=(polycell&&) = default;

public:
  //! different possible states of a grid cell
  enum class state { edge, body, empty };

public:
  //! getters
  inline state get_state(void) const { return this->m_state; }

  //! setters
  inline void set_state(state s) { this->m_state = s; }

private:
  state m_state;
};

} //! polygrid

#include <polygrid/impl/polycell.hpp>
