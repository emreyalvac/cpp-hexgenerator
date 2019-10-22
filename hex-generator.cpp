//
// Created by Emre Yalvac on 20.10.2019.
//

#include <sstream>
#include <random>
#include <string>
#include <iostream>
#include <napi.h>


unsigned int random_char() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    return dis(gen);
}

std::string generate_hex(const unsigned int len) {
    std::stringstream ss;
    for (auto i = 0; i < len; i++) {
        const auto rc = random_char();
        std::stringstream hexstream;
        hexstream << std::hex << rc;
        auto hex = hexstream.str();
        ss << (hex.length() < 2 ? '0' + hex : hex);
    }
    return ss.str();
}

using namespace Napi;

String GenerateGuid(const CallbackInfo &info) {
    Env env = info.Env();
    int length = info[0].As<Number>();
    String returnValue = String::New(env, generate_hex(length));
    return returnValue;
}

Object InitAll(Env env, Object exports) {
    exports.Set("Guid", Function::New(env, GenerateGuid));
    return exports;
}

NODE_API_MODULE(Guid, InitAll);




