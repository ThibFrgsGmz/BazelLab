"""
File with all 3rd party dependencies needed for the project

They are loaded but without loading the transitive dependencies, this is done in
a separated file extra_dependencies.bzl
"""

load("//third_party/gtest:direct.bzl", "load_gtest")
load("//third_party/fuzztest:direct.bzl", "load_fuzztest")

def load_third_party_libraries():
    """Load all third party dependencies"""
    load_gtest()
    load_fuzztest()
