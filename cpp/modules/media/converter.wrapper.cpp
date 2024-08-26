#include "converter.wrapper.hpp"

Napi::FunctionReference Media::ConverterWrapper::constructor;

Napi::Object Media::ConverterWrapper::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "Converter", {InstanceMethod("set_source", &Media::ConverterWrapper::set_source), InstanceMethod("set_destination", &Media::ConverterWrapper::set_destination), InstanceMethod("start", &Media::ConverterWrapper::start)});

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("Converter", func);
    return exports;
};

Media::ConverterWrapper::ConverterWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Media::ConverterWrapper>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();
    if (length == 2)
    {
        Napi::String src = info[0].As<Napi::String>();
        Napi::String dest = info[1].As<Napi::String>();
        this->m_converter = new Media::Converter(src, dest);
    }
    else if (length != 0 || length != 2)
        Napi::TypeError::New(env, "Wrong Parameter!\nConstructor expects 2 parameters (source and destination) or no parameters.").ThrowAsJavaScriptException();
    else
        this->m_converter = new Media::Converter();
};

Napi::Value Media::ConverterWrapper::set_source(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() != 1 && !info[0].IsString())
        Napi::TypeError::New(env, "String source path expected").ThrowAsJavaScriptException();

    Napi::String src = info[0].As<Napi::String>();
    bool result = this->m_converter->set_source(src);
    return Napi::Boolean::New(info.Env(), result);
};

Napi::Value Media::ConverterWrapper::set_destination(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() != 1 && !info[0].IsString())
        Napi::TypeError::New(env, "String destination path expected").ThrowAsJavaScriptException();

    Napi::String dest = info[0].As<Napi::String>();
    bool result = this->m_converter->set_destination(dest);
    return Napi::Boolean::New(info.Env(), result);
};

Napi::Value Media::ConverterWrapper::start(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    this->m_converter->start();
    // return Napi::Function::Callback::New(info.Env());
    return Napi::Number::New(info.Env(), 0);
};