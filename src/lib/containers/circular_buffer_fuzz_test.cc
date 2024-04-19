#include <cstddef>
#include <cstdint>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (size == 0) {
    return 0;
  }
  int k = 0x7fffffff;
  k += data[0];
  // Use k.
  return k & 0;
}