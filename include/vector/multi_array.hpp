#ifndef BENLIB_MULTIDIMVECTOR_HPP_
#define BENLIB_MULTIDIMVECTOR_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdarg>  // std::va_list, std::va_start, std::va_end
#include <cstdint>  // uint8_t, uint64_t
#include <numeric>  // std::reduce
#include <vector>  // std::vector

#include "vector/multi_array_view.hpp"
#include "vector/vector.hpp"

namespace benlib
{

template<typename T>
class multi_array_view;

template<typename T>
class multi_array
{
public:
  multi_array()
      : content()
      , dimensions()
  {
  }

  multi_array(std::vector<uint64_t> dimensions_)
      : dimensions(dimensions_)
  {
    // Multiply dimensions together.
    const auto&& size = std::reduce(
        dimensions_.begin(), dimensions_.end(), 1, std::multiplies<uint64_t>());

    content.resize(size);
  }

  multi_array(std::vector<uint64_t> dimensions_, std::vector<T> content_)
      : dimensions(dimensions_)
      , content(content_)
  {
    /*
    if (content.size() != std::reduce(dimensions_.begin(), dimensions_.end(), 1,
    std::multiplies<uint64_t>())) throw std::runtime_error("multi_array: content
    size does not match dimensions");
    */
  }

  multi_array(multi_array<T>&& other)
      : dimensions(std::move(other.dimensions))
      , content(std::move(other.content))
  {
  }

  multi_array(const multi_array<T>& other)
      : dimensions(other.dimensions)
      , content(other.content)
  {
  }

  // Variadic constructor
  multi_array(int argSize, ...)
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

  std::vector<T> GetGrid()
  {
    return content;
  }

  void SetGrid(const std::vector<T>& grid_)
  {
    // if (grid_.size() != std::reduce(dimensions.begin(),
    // dimensions.end(),1,std::multiplies<uint64_t>())) throw
    // std::runtime_error("multi_array: content size does not match
    // dimensions");
    content = grid_;
  }

  // To Remove later.
  std::vector<T>* GetGridPtr()
  {
    return &content;
  }

  std::vector<T>* data()
  {
    return &content;
  }

  uint64_t size() const
  {
    return content.size();
  }

  uint64_t ConvertTo1DCoordinate(const std::vector<uint64_t>& coordinates) const
  {
    uint64_t coordinate = 0;
    for (uint64_t i = 0; i < coordinates.size(); ++i) {
      coordinate += coordinates[i]
          * std::accumulate(dimensions.begin() + i + 1,
                            dimensions.end(),
                            1,
                            std::multiplies<uint64_t>());
    }
    return coordinate;
  }

  uint64_t ConvertTo1DCoordinate(int argSize, ...) const
  {
    va_list args;
    va_start(args, argSize);
    std::vector<uint64_t> coordinates(argSize);
    for (int i = 0; i < argSize; ++i)
      coordinates[i] = va_arg(args, int);
    va_end(args);
    return ConvertTo1DCoordinate(coordinates);
  }

  std::vector<uint64_t> GetDim()
  {
    return dimensions;
  }

  void SetDim(const std::vector<uint64_t>& dimensions_)
  {
    // if (dimensions_.size() != dimensions.size())
    //   throw std::runtime_error("multi_array: dimensions size does not
    //   match");
    dimensions = dimensions_;
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

  bool IsEqual(const multi_array<T>& other)
  {
    if (dimensions != other.dimensions) {
      return false;
    }
    if (content != other.content) {
      return false;
    }
    return true;
  }

  void swap(multi_array<T>& other)
  {
    dimensions.swap(other.dimensions);
    content.swap(other.content);
  }

  multi_array_view<T> operator[](uint64_t index)
  {
    return multi_array_view<T>(*this, index, 1);
  }

  // Overload = operator
  multi_array<T> operator=(const multi_array<T>& other)
  {
    if (this != &other) {
      content = other.content;
      dimensions = other.dimensions;
    }
    return *this;
  }

  // Overload + operator
  multi_array<T> operator+(const multi_array<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("multi_array: dimensions size does not
    //   match");
    multi_array<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] + other.content[i];
    return result;
  }

  // Overload - operator
  multi_array<T> operator-(const multi_array<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("multi_array: dimensions size does not
    //   match");
    multi_array<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] - other.content[i];
    return result;
  }

  // Overload * operator
  multi_array<T> operator*(const multi_array<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("multi_array: dimensions size does not
    //   match");
    multi_array<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] * other.content[i];
    return result;
  }

  // Overload / operator
  multi_array<T> operator/(const multi_array<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("multi_array: dimensions size does not
    //   match");
    multi_array<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] / other.content[i];
    return result;
  }

  // Overload % operator
  multi_array<T> operator%(const multi_array<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("multi_array: dimensions size does not
    //   match");
    multi_array<T> result(dimensions);
    for (uint64_t i = 0; i < content.size(); ++i)
      result.content[i] = content[i] % other.content[i];
    return result;
  }

  // Overload += operator
  multi_array<T> operator+=(const multi_array<T>& other)
  {
    // if (dimensions != other.dimensions)
    //   throw std::runtime_error("multi_array: dimensions size does not
    //   match");
    for (uint64_t i = 0; i < content.size(); ++i)
      content[i] += other.content[i];
    return *this;
  }

  // Overload == operator
  bool operator==(const multi_array<T>& other) const
  {
    return content == other.content && dimensions == other.dimensions;
  }

  // Overload != operator
  bool operator!=(const multi_array<T>& other) const
  {
    return content != other.content || dimensions != other.dimensions;
  }

  // protected:
  std::vector<uint64_t> dimensions;
  std::vector<T> content;
};

}  // namespace benlib
#endif  // BENLIB_VECTORFLAT2D_HPP_
