#ifndef BENLIB_MULTIDIMVECTOR_HPP_
#define BENLIB_MULTIDIMVECTOR_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdarg>  // std::va_list, std::va_start, std::va_end
#include <cstdint>  // uint8_t, uint64_t
#include <numeric>  // std::reduce
#include <vector>  // std::vector

#include "vector/vector.hpp"

namespace benlib
{
template<typename T>
class MultiVector;

// Needed for MultiVector on [][]... notation.
template<typename T>
class MultiVectorView
{
public:
  MultiVectorView(MultiVector<T>& vec_, uint64_t index_, uint64_t dimension_)
      : vec(vec_)
      , index(index_)
      , dimension(dimension_)
  {
  }

  MultiVector<T>& vec;
  uint64_t index;
  uint64_t dimension;

  MultiVectorView& operator[](std::uint64_t n_index)
  {
    uint64_t index_multiplyer = 1;
    for (uint64_t i = 0; i < dimension; ++i)
      index_multiplyer *= vec.dimensions[i];
    index += n_index * index_multiplyer;
    dimension++;
    return *this;
  }

  operator T()
  {
    return vec.content[index];
  }

  MultiVectorView& operator=(T val)
  {
    vec.content[index] = val;
    return *this;
  }

  bool operator==(const T val) const
  {
    return vec.content[index] == val;
  }

  bool operator!=(const T val) const
  {
    return vec.content[index] != val;
  }

  ~MultiVectorView() {}
};

template<typename T>
class MultiVector
{
public:
  MultiVector() {}

  MultiVector(std::vector<uint64_t> dimensions_)
      : dimensions(dimensions_)
  {
    // Multiply dimensions together.
    const auto&& size = std::reduce(
        dimensions_.begin(), dimensions_.end(), 1, std::multiplies<uint64_t>());

    content.resize(size);
  }

  MultiVector(std::vector<uint64_t> dimensions_, std::vector<T> content_)
      : dimensions(dimensions_)
      , content(content_)
  {
    /*
    if (content.size() != std::reduce(dimensions_.begin(), dimensions_.end(), 1,
    std::multiplies<uint64_t>())) throw std::runtime_error("MultiVector: content
    size does not match dimensions");
    */
  }

  // Variadic constructor
  MultiVector(int argSize, ...)
  {
    va_list args;
    va_start(args, argSize);
    dimensions.resize(argSize);
    for (int i = 0; i < argSize; ++i)
      dimensions[i] = va_arg(args, int);
    va_end(args);

    uint64_t size = dimensions[0];
    for (uint64_t i = 1; i < dimensions.size(); ++i)
      size *= dimensions[i];

    content.resize(size);
  }

  // Resize
  void resize(std::vector<uint64_t> dimensions_)
  {
    dimensions = dimensions_;
    const auto&& size = std::reduce(
        dimensions_.begin(), dimensions_.end(), 1, std::multiplies<uint64_t>());

    content.resize(size);
  }

  void fill(const T& value)
  {
    std::fill(content.begin(), content.end(), value);
  }

  /*
  std::vector<T>::iterator begin()
  {
    return content.begin();
  }

  std::vector<T>::iterator end()
  {
    return content.end();
  }
  */

  void clear()
  {
    content.clear();
  }

  void shrink_to_fit()
  {
    content.shrink_to_fit();
  }

  std::vector<T>& GetGrid()
  {
    return content;
  }

  void SetGrid(const std::vector<T>& grid_)
  {
    // if (grid_.size() != std::reduce(dimensions.begin(),
    // dimensions.end(),1,std::multiplies<uint64_t>())) throw
    // std::runtime_error("MultiVector: content size does not match
    // dimensions");
    content = grid_;
  }

  std::vector<T>* GetGridPtr()
  {
    return &content;
  }

  std::vector<uint64_t>& GetDim()
  {
    return dimensions;
  }

  void SetDim(const std::vector<uint64_t>& dimensions_)
  {
    // if (dimensions_.size() != dimensions.size())
    //   throw std::runtime_error("MultiVector: dimensions size does not
    //   match");
    dimensions = dimensions_;
  }

  uint64_t size()
  {
    return content.size();
  }

  T GetValue(const std::vector<uint64_t>& indices)
  {
    uint64_t index = 0;
    uint64_t index_multiplyer = 1;
    for (uint64_t i = 0; i < dimensions.size(); ++i) {
      index += indices[i] * index_multiplyer;
      index_multiplyer *= dimensions[i];
    }
    return content[index];
  }

  T GetValue(const uint64_t index)
  {
    return content[index];
  }

  void SetValue(const std::vector<uint64_t>& indices, T value)
  {
    uint64_t index = 0;
    uint64_t index_multiplyer = 1;
    for (uint64_t i = 0; i < dimensions.size(); ++i) {
      index += indices[i] * index_multiplyer;
      index_multiplyer *= dimensions[i];
    }
    content[index] = value;
  }

  void SetValue(uint64_t index, T value)
  {
    content[index] = value;
  }

  bool IsEqual(const MultiVector<T>& other)
  {
    if (dimensions != other.dimensions) {
      return false;
    }
    if (content != other.content) {
      return false;
    }
    return true;
  }

  MultiVectorView<T> operator[](uint64_t index)
  {
    return MultiVectorView<T>(*this, index, 1);
  }

  // Overload = operator
  MultiVector<T>& operator=(const MultiVector<T>& other)
  {
    if (this != &other) {
      content = other.content;
      dimensions = other.dimensions;
    }
    return *this;
  }

  // Overload + operator
  MultiVector<T> operator+(const MultiVector<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("MultiVector: dimensions size does not
    //   match");
    MultiVector<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] + other.content[i];
    return result;
  }

  // Overload - operator
  MultiVector<T> operator-(const MultiVector<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("MultiVector: dimensions size does not
    //   match");
    MultiVector<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] - other.content[i];
    return result;
  }

  // Overload * operator
  MultiVector<T> operator*(const MultiVector<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("MultiVector: dimensions size does not
    //   match");
    MultiVector<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] * other.content[i];
    return result;
  }

  // Overload / operator
  MultiVector<T> operator/(const MultiVector<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("MultiVector: dimensions size does not
    //   match");
    MultiVector<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] / other.content[i];
    return result;
  }

  // Overload % operator
  MultiVector<T> operator%(const MultiVector<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("MultiVector: dimensions size does not
    //   match");
    MultiVector<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] % other.content[i];
    return result;
  }

  // Overload += operator
  MultiVector<T>& operator+=(const MultiVector<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("MultiVector: dimensions size does not
    //   match");
    for (uint64_t i = 0; i < content.size(); ++i)
      content[i] += other.content[i];
    return *this;
  }

  // Overload == operator
  bool operator==(const MultiVector<T>& other) const
  {
    return content == other.content && dimensions == other.dimensions;
  }

  // Overload != operator
  bool operator!=(const MultiVector<T>& other) const
  {
    return content != other.content || dimensions != other.dimensions;
  }

  // protected:
  std::vector<uint64_t> dimensions;
  std::vector<T> content;
};

}  // namespace benlib
#endif  // BENLIB_VECTORFLAT2D_HPP_
