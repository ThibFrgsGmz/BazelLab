cc_library(
    name = "circular_buffer",
    srcs = ["circular_buffer.cc"],
    hdrs = ["circular_buffer.h"],
)

cc_test(
    name = "circular_buffer_fuzz_test",
    srcs = ["circular_buffer_fuzz_test.cc"],
    deps = [
        ":circular_buffer",
        "@com_google_fuzztest//fuzztest",
        "@com_google_fuzztest//fuzztest:fuzztest_gtest_main",
        "@com_google_googletest//:gtest"
    ],
)