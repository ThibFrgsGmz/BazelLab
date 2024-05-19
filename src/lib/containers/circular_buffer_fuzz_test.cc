#include <cstddef>
#include <cstdint>

extern "C" int LLVMFuzzerTestOneInput(uint8_t const* data, size_t size) {
  if (size == 0) {
    return 0;
  }
  int k = 0x7fffffff;
  k += data[0];
  // Use k.
  return k & 0;
}
