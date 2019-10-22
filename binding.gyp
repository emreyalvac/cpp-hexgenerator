{
    "targets": [{
        "target_name": "hex-generator",
        "cflags!": [ "-fno-exceptions" ],
        "cflags": [ "-std=c++11" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "main.cc"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
        ],
        "libraries": [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")",
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}