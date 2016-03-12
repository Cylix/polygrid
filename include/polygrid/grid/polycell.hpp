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
  inline bool is_edge(void) const { return this->m_state == state::edge; }
  inline bool is_body(void) const { return this->m_state == state::body; }
  inline bool is_empty(void) const { return this->m_state == state::empty; }
  inline bool contains_polygon(void) const { return not this->is_empty(); }

  //! setters
  inline void set_state(state s) { this->m_state = s; }
  inline void mark_as_edge(void) { this->set_state(state::edge); }
  inline void mark_as_body(void) { this->set_state(state::body); }
  inline void mark_as_empty(void) { this->set_state(state::empty); }

private:
  state m_state;
};

} //! polygrid

#include <polygrid/grid/impl/polycell.ipp>
