package(default_visibility = ["//visibility:public"])

cc_test(
    name = "first_fuzz_test",
    srcs = ["first_fuzz_test.cc"],
    deps = [
        "@com_google_fuzztest//fuzztest",
        "@com_google_fuzztest//fuzztest:fuzztest_gtest_main",
        "@com_google_googletest//:gtest",
    ],
)

cc_library(
    name = "gtest_main",
    testonly = True,
    srcs = ["gtest_main.cc"],
    deps = [
        "@com_google_googletest//:gtest",
    ],
)
