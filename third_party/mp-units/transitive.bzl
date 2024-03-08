"""
Transitive dependencies for cib
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def load_mp_unit_transitive_dependencies():
    # Leaving it empty allows that if at some point some transitive dependencies are needed
    # they can be added without modifying transitive_dependencies.bzl
    maybe(
        http_archive,
        name = "gsl_lite",
        strip_prefix = "gsl-lite-v0.41.0",
        sha256 = "2a4d07cd64b0719b39a7c12218a3e507672b82a97b98c6a89d38565894cf7c51",
        url = "https://github.com/gsl-lite/gsl-lite/archive/refs/tags/v0.41.0.tar.gz",
    )
