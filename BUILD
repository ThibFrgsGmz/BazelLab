load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

filegroup(
    name = "clang_tidy_config",
    srcs = [".clang-tidy"],
    visibility = ["//visibility:public"],
)

# Note: run `bazel run :refresh_compile_commands` to set up clangd.
refresh_compile_commands(
    name = "refresh_compile_commands",
    exclude_external_sources = True,
    exclude_headers = "external",
    # Specify the targets of interest.
    # For example, specify a dict of targets and any flags required to build.
    targets = {
        "//src/...": "--compilation_mode=dbg",
    },

    # No need to add flags already in .bazelrc. They're automatically picked up.
    # If you don't need flags, a list of targets is also okay, as is a single target string.
    # Wildcard patterns, like //... for everything, *are* allowed here, just like a build.
    # As are additional targets (+) and subtractions (-), like in bazel query https://docs.bazel.build/versions/main/query.html#expressions
    # And if you're working on a header-only library, specify a test or binary target that compiles it.
)
