"""
Transitive dependencies for fuzztest
"""

load("//third_party/bazel_skylib:direct.bzl", "load_bazel_skylib")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_fuzztest_transitive_dependencies():
    # Required by com_google_fuzztest.
    maybe(
        http_archive,
        name = "com_googlesource_code_re2",
        sha256 = "f89c61410a072e5cbcf8c27e3a778da7d6fd2f2b5b1445cd4f4508bee946ab0f",
        strip_prefix = "re2-2022-06-01",
        url = "https://github.com/google/re2/archive/refs/tags/2022-06-01.tar.gz",
    )

    maybe(
        http_archive,
        name = "com_google_absl",
        sha256 = "3ea49a7d97421b88a8c48a0de16c16048e17725c7ec0f1d3ea2683a2a75adc21",
        strip_prefix = "abseil-cpp-20230125.0",
        url = "https://github.com/abseil/abseil-cpp/archive/refs/tags/20230125.0.tar.gz",
    )
    load_bazel_skylib()