#ifndef ___MEDIA_MODULE_CONERTER_WRAPPER_HPP___
#define ___MEDIA_MODULE_CONERTER_WRAPPER_HPP___

#include <napi.h>
#include "converter.module.hpp"

namespace Media
{
    class ConverterWrapper : public Napi::ObjectWrap<Media::ConverterWrapper>
    {
    private:
        static Napi::FunctionReference constructor;
        Napi::Value start(const Napi::CallbackInfo &info);
        Napi::Value set_source(const Napi::CallbackInfo &info);
        Napi::Value set_destination(const Napi::CallbackInfo &info);
        Media::Converter *m_converter;

    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        ConverterWrapper(const Napi::CallbackInfo &info);

    protected:
    };
};

#endif // !___MEDIA_MODULE_CONERTER_WRAPPER_HPP___