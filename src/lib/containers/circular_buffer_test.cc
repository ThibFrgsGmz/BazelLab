#include "circular_buffer.h"

#include <gtest/gtest.h>
#include "fixed_containers/concepts.hpp"
#include <fixed_containers/fixed_vector.hpp>


using VecType = fixed_containers::FixedVector<int, 5>;


template <class T>
concept TriviallyCopyable = std::is_trivially_copyable_v<T>;

static_assert(TriviallyCopyable<VecType>);


// Test fixture for CircularBuffer class
class CircularBufferTest : public ::testing::Test {
 protected:
  CircularBuffer buffer;
};

// Test case for default constructor
TEST_F(CircularBufferTest, DefaultConstructor) {
  ASSERT_TRUE(buffer.is_empty());
  ASSERT_FALSE(buffer.is_full());
}

// Test case for popping elements
TEST_F(CircularBufferTest, PopFront) {
  ASSERT_EQ(buffer.pop_front(), std::nullopt);  // Buffer is empty

  buffer.push_back(1);
  buffer.push_back(2);
  ASSERT_EQ(buffer.pop_front(), 1);
  ASSERT_EQ(buffer.pop_front(), 2);
  ASSERT_EQ(buffer.pop_front(), std::nullopt);  // Buffer is empty now

  buffer.push_back(3);
  buffer.push_back(4);
  ASSERT_EQ(buffer.pop_front(), 3);
  ASSERT_EQ(buffer.pop_front(), 4);
  ASSERT_EQ(buffer.pop_front(), std::nullopt);  // Buffer is empty now
}

// Test case for full buffer overwriting oldest element
TEST_F(CircularBufferTest, FullBufferOverwrite) {
  for (int i = 0; i < 10; ++i) {
    buffer.push_back(i);
  }

  ASSERT_TRUE(buffer.is_full());
  ASSERT_EQ(buffer.pop_front(), 0);  // Oldest element overwritten
}
