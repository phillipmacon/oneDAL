load("@onedal//dev/bazel:cc.bzl",
    "cc_module",
    "cc_executable",
)

_FEATURES = ["dpc++", "pedantic"]

cc_module(
    name = "common",
    hdrs = glob(["*.hpp"]),
    deps = [
        "@fmt//:fmt",
    ],
    features = _FEATURES,
)

cc_module(
    name = "_zeinfo",
    srcs = [
        "zeinfo.cpp",
    ],
    deps = [
        ":common",
    ],
    features = _FEATURES,
)

cc_executable(
    name = "zeinfo",
    deps = [
        ":_zeinfo",
    ],
    user_link_flags = [ "-lze_loader" ],
    features = _FEATURES,
)
