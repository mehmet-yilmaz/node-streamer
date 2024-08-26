#include <napi.h>
#include "../modules/media/converter.wrapper.hpp"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return Media::ConverterWrapper::Init(env, exports);
};

NODE_API_MODULE(nodestreamer, InitAll)