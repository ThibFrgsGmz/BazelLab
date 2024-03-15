#include "circular_buffer.h"

#include <stdexcept>

/// Constructor initializes the circular buffer with default size.
CircularBuffer::CircularBuffer() : head_(0), tail_(0), full_(false) {}

/// Pushes an element to the back of the buffer.
/// If the buffer is full, the oldest element will be overwritten.
/// @param value The integer value to push into the buffer.
void CircularBuffer::push_back(int value) {
  buffer_[tail_] = value;
  if (full_) {
    head_ = (head_ + 1) % buffer_size;
  }
  tail_ = (tail_ + 1) % buffer_size;
  full_ = head_ == tail_;
}

/// Pops an element from the front of the buffer.
/// @return The integer value popped from the buffer or std::nullopt if the
/// buffer is empty.
std::optional<int> CircularBuffer::pop_front() {
  if (is_empty()) {
    return std::nullopt;
  }

  int value = buffer_[head_];
  full_ = false;
  head_ = (head_ + 1) % buffer_size;

  return value;
}

/// Checks if the buffer is empty.
/// @return True if the buffer is empty, false otherwise.
bool CircularBuffer::is_empty() const { return (!full_ && (head_ == tail_)); }

/// Checks if the buffer is full.
/// @return True if the buffer is full, false otherwise.
bool CircularBuffer::is_full() const { return full_; }
