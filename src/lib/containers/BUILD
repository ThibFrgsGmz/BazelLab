load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "circular_buffer",
    srcs = ["circular_buffer.cc"],
    hdrs = ["circular_buffer.h"],
)

cc_test(
    name = "circular_buffer_test",
    srcs = ["circular_buffer_test.cc"],
    deps = [
        ":circular_buffer",
        "//src/tests:gtest_main",
        "@googletest//:gtest",
    ],
)

# cc_test(
#     name = "circular_buffer_fuzz_test",
#     srcs = ["circular_buffer_fuzz_test.cc"],
#     deps = [
#         ":circular_buffer",
#         "@com_google_fuzztest//fuzztest",
#         "@com_google_fuzztest//fuzztest:fuzztest_gtest_main",
#         "@googletest//:gtest",
#     ],
# )
