#include <cib/cib.hpp>
#include <iostream>

struct say_message : public cib::callback_meta<> {};

// the 'core' component exposes the 'say_message' service for others to extend
struct core {
  constexpr static auto config = cib::exports<say_message>;
};

// the 'say_hello_world' component extends 'say_message' with its own
// functionality
struct say_hello_world {
  constexpr static auto config = cib::extend<say_message>(
      []() { std::cout << "Hello, world!" << std::endl; });
};

// the 'hello_world' project composes 'core' and 'say_hello_world'
struct hello_world {
  constexpr static auto config = cib::components<core, say_hello_world>;
};

// the nexus instantiates the project
cib::nexus<hello_world> nexus{};

int main() {
  // the fully extended and built services are ready to be used
  nexus.service<say_message>();
  return 0;
}
