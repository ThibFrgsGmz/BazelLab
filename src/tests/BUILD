load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "gtest_main",
    testonly = True,
    srcs = ["gtest_main.cc"],
    deps = [
        "@googletest//:gtest",
    ],
)
