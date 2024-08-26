{
    "targets": [
        {
            "target_name": "nodestreamer",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": [
                "cpp/src/main.cpp",
                "cpp/modules/media/converter.module.cpp",
                "cpp/modules/media/converter.wrapper.cpp"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "<!@(pkg-config gstreamer-1.0 --cflags-only-I | sed s/-I//g)"
            ],
            "libraries": [
                "<!@(pkg-config gstreamer-1.0 --libs)"
            ],
            "dependencies": [
                "<!@(node -p \"require('node-addon-api').gyp\")"
            ],
            "defines":[
                "NAPI_DISABLE_CPP_EXCEPTIONS"
            ]
        }
    ]
}