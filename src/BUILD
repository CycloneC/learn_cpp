load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "template_lib",
    srcs = [
        "0301_template.cc",
    ],
    hdrs = [
        "0301_template.h",
    ],
    deps = [

    ],
)

cc_test(
    name = "template_test",
    size = "small",
    srcs = ["0301_template_unittest.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "//:template_lib",
    ],
)
