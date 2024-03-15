#include <array>
#include <optional>

/// Fixed-size circular buffer for storing integers.
class CircularBuffer {
 public:
  /// Constructor initializes the circular buffer with default size.
  CircularBuffer();

  /// Pushes an element to the back of the buffer.
  /// If the buffer is full, the oldest element will be overwritten.
  /// @param value The integer value to push into the buffer.
  void push_back(int value);

  /// Pops an element from the front of the buffer.
  /// @return The integer value popped from the buffer or std::nullopt if the
  /// buffer is empty.
  std::optional<int> pop_front();

  /// Checks if the buffer is empty.
  /// @return True if the buffer is empty, false otherwise.
  bool is_empty() const;

  /// Checks if the buffer is full.
  /// @return True if the buffer is full, false otherwise.
  bool is_full() const;

 private:
  constexpr static size_t buffer_size = 10;  // Fixed buffer size
  std::array<int, buffer_size> buffer_;      // Buffer for storing integers
  size_t head_;  // Index of the first element in the buffer
  size_t tail_;  // Index of the last element in the buffer
  bool full_;    // Indicates if the buffer is full
};
