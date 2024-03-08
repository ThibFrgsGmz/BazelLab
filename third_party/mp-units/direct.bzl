"""
Dependency to cib (compile-time-init-build), a C++ library for composing modular firmware at compile-time.
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def load_mp_unit():
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
        name = "com_mpusz_mp_units",
        build_file = Label("//third_party/mp-units:BUILD.mp-units.bazel"),
        sha256 = "a42057492f5a8e80442cf13602b97bb48b9c3a408bc91bdb60d86aadc84c95cc",
        strip_prefix = "mp-units-2.1.0",
        url = "https://github.com/mpusz/mp-units/archive/refs/tags/v2.1.0.tar.gz",
    )
