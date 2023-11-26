"""
Dependency to fuzztest, Google's fuzzer
"""

load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_fuzztest():
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

    
    # To use the latest version of FuzzTest, update this regularly to the latest
    # commit in the main branch: https://github.com/google/fuzztest/commits/main
    FUZZTEST_COMMIT = "62cf00c7341eb05d128d0a3cbce79ac31dbda032"
    maybe(
        http_archive,
        name = "com_google_fuzztest",
        strip_prefix = "fuzztest-" + FUZZTEST_COMMIT,
        url = "https://github.com/google/fuzztest/archive/" + FUZZTEST_COMMIT + ".zip",
    )
