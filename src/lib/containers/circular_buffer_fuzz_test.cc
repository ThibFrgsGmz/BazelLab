#include "circular_buffer.h"
#include "fuzztest/fuzztest.h"
#include "gtest/gtest.h"

/// Fuzz test for CircularBuffer class.
void fuzz_circular_buffer(std::vector<int> const& inputs) {
  CircularBuffer buffer;
  for (auto value : inputs) {
    // Simulate some operations based on value
    if (value % 3 == 0) {
      buffer.push_back(value);
    } else if (value % 3 == 1) {
      buffer.pop_front();
    } else if (value % 3 == 2) {
      buffer.is_empty();
    }
  }
}

FUZZ_TEST(CircularBufferTestSuite, fuzz_circular_buffer);
