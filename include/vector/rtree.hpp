//////////////////////////////////////////////////////////////
//   ____                                                   //
//  | __ )  ___ _ __  ___ _   _ _ __   ___ _ __ _ __   ___  //
//  |  _ \ / _ \ '_ \/ __| | | | '_ \ / _ \ '__| '_ \ / __| //
//  | |_) |  __/ | | \__ \ |_| | |_) |  __/ |  | |_) | (__  //
//  |____/ \___|_| |_|___/\__,_| .__/ \___|_|  | .__/ \___| //
//                             |_|             |_|          //
//////////////////////////////////////////////////////////////
//                                                          //
//  Vector, 2022                                            //
//  Created: 09, July, 2022                                 //
//  Modified: 09, July, 2022                                //
//                                                          //
//  License: MIT                                            //
//  Source:                                                 //
//  OS: ALL                                                 //
//  CPU: ALL                                                //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef BENLIB_RTREE_HPP_
#define BENLIB_RTREE_HPP_

#include <algorithm>
#include <cstddef>  // std::uint64_t
#include <iostream>  // std::cout, std::endl
#include <vector>  // std::vector

namespace benlib
{
template<typename T>
class rtree
{
public:
  rtree() {}
  rtree(uint64_t node_size, uint64_t depth)
  {
    if (depth == 0) {
      return;
    }
    depth--;
    nodes.reserve(node_size);
    for (uint64_t i = 0; i < node_size; ++i) {
      nodes.emplace_back(rtree<T>(node_size, depth));
    }
  }

  rtree(uint64_t node_size, uint64_t depth, std::vector<T> content)
  {
    if (depth == 0) {
      return;
    }
    depth--;
    nodes.reserve(node_size);
    for (uint64_t i = 0; i < node_size; ++i) {
      nodes.emplace_back(rtree<T>(node_size, depth, content));
    }
  }

  rtree(const rtree<T>& other) { nodes = other.nodes; }

  ~rtree() {}

  T* browse_ptr(const std::vector<uint64_t>& coordinates)
  {
    if (coordinates.size() == 0)
      return &nodes[0];
    else
      return nodes[coordinates[0]].browse(coordinates.begin() + 1, coordinates.end());
  }

  T browse(const std::vector<uint64_t>& coordinates)
  {
    if (coordinates.size() == 0) {
      return nodes[0];
    } else {
      return nodes[coordinates[0]].browse(coordinates.begin() + 1, coordinates.end());
    }
  }

  void insert(const std::vector<uint64_t>& coordinates, const T& value)
  {
    if (coordinates.size() == 0) {
      nodes.emplace_back(value);
    } else {
      nodes[coordinates[0]].insert(coordinates.begin() + 1, value);
    }
  }
  bool is_in(const T& key)
  {
    const auto it = std::find(nodes.begin(), nodes.end(), key);
    if (it != nodes.end()) {
      return true;
    } else {
      for (auto& b : nodes) {
        if (b.is_in(key)) {
          return true;
        }
      }
      return false;
    }
    return false;
  }

  /*
  std::vector<T> * find(const T& key, std::vector<T> * result)
  {
    const auto it = std::find(nodes.begin(), nodes.end(), key);

    if (it != node.end()) {
      result->push_back(key);
    }
    for (auto& b : nodes) {
      b.find(key, result);
    }
    return result;
  }
  */

  uint64_t tree_depth()
  {
    if (nodes.size() == 0) {
      return 0;
    } else {
      uint64_t max_depth = 0;
      for (auto& b : nodes) {
        max_depth = std::max(max_depth, b.tree_depth());
      }
      return max_depth + 1;
    }
  }

  uint64_t node_count()
  {
    uint64_t count = nodes.size();
    for (auto& b : nodes) {
      count += b.node_count();
    }
    return count;
  }

  uint64_t node_end_count()
  {
    if (nodes.size() == 0) {
      return 1;
    } else {
      uint64_t count = 0;
      for (auto& b : nodes) {
        count += b.node_end_count();
      }
      return count;
    }
  }

  uint64_t size() const { return nodes.size(); }

  void clear() { nodes.clear(); }

  void shrink_to_fit() { nodes.shrink_to_fit(); }

  std::vector<T>* data() { return &nodes; }

  typename std::vector<rtree<T>>::iterator begin() { return nodes.begin(); }
  typename std::vector<rtree<T>>::iterator end() { return nodes.end(); }

  void swap(rtree<T>& other)
  {
    using std::swap;
    swap(nodes, other.node);
  }

  void resize(uint64_t size) { nodes.resize(size); }

  rtree<T>& operator=(const rtree<T>& other)
  {
    nodes = other.nodes;
    return *this;
  }

protected:
  std::vector<rtree<T>> nodes;
  // static std::vector<*rtree<T>> all_node_ptr;
};
}  // namespace benlib
#endif  // BENLIB_RTREE_HPP_