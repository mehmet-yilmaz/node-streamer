#ifndef ___MEDIA_MODULE_CONVERTER_HPP___
#define ___MEDIA_MODULE_CONVERTER_HPP___
#include <napi.h>
#include <gstreamer-1.0/gst/gst.h>
#include <string>
namespace Media
{
    class Converter
    {
    private:
        std::string m_source_path;
        std::string m_destination_path;
        GstElement *m_gst_pipeline;
        GstBus *m_gst_bus;
        GstMessage *m_gst_message;

    public:
        Converter();
        Converter(const std::string &source_path, const std::string &destination_path);
        bool set_source(const std::string &source_path);
        bool set_destination(const std::string &destination_path);
        void start();
        void stop();

    protected:
    };
};
#endif // !___MEDIA_MODULE_CONVERTER_HPP___