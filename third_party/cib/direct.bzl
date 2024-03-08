"""
Dependency to cib (compile-time-init-build), a C++ library for composing modular firmware at compile-time.
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def load_cib():
    # It is not clear in Bazel what is the best practice for using http_archive.
    # If you call http_archive without any kind of check, you could call it two times
    # with the same name and different parameters and you would not get any warning/error.
    #
    # One option is to check if it is already available in the existing_rules and only
    # call http_archive if it is not present. In the else you could display a message in
    # case that was already present but in reality you would only want a warning/error if was
    # already called with different parameters (different library version for example).
    #
    # Another option is to wrap the http_archive in a maybe call but this will also not display
    # a warning. It behaves like the if check with the advantage that the name has not to be
    # repeated
    maybe(
        http_archive,
        name = "com_intel_cib",
        build_file = Label("//third_party/cib:BUILD.cib.bazel"),
        sha256 = "e46a155ba042241f625637bf770ff8f2b3537d9827c8537578aca7a2790bfae8",
        strip_prefix = "compile-time-init-build-1.7.0",
        url = "https://github.com/intel/compile-time-init-build/archive/refs/tags/v1.7.0.tar.gz",
    )
