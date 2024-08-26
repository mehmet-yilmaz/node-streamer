#include "converter.module.hpp"

Media::Converter::Converter()
{
    gst_init(NULL, NULL);
};
Media::Converter::Converter(const std::string &source_path, const std::string &destination_path) : m_source_path(source_path), m_destination_path(destination_path)
{
    gst_init(NULL, NULL);
};
bool Media::Converter::set_destination(const std::string &destination_path)
{
    this->m_destination_path = destination_path;
    return this->m_destination_path == destination_path;
}

bool Media::Converter::set_source(const std::string &source_path)
{
    this->m_source_path = source_path;
    return this->m_source_path == source_path;
}

void Media::Converter::start()
{
    if (!this->m_source_path.empty() && !this->m_destination_path.empty())
    {
        std::string command = "filesrc location=" + this->m_source_path + " !filesink location=" + this->m_destination_path;
        this->m_gst_pipeline = gst_parse_launch(command.c_str(), NULL);
        gst_element_set_state(this->m_gst_pipeline, GST_STATE_PLAYING);
        this->m_gst_bus = gst_element_get_bus(this->m_gst_pipeline);
        this->m_gst_message = gst_bus_timed_pop_filtered(this->m_gst_bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

        if (GST_MESSAGE_TYPE(this->m_gst_message) == GST_MESSAGE_ERROR)
        {
            g_error("An error occured!");
        }

        gst_message_unref(this->m_gst_message);
        gst_object_unref(this->m_gst_bus);
        gst_element_set_state(this->m_gst_pipeline, GST_STATE_NULL);
        gst_object_unref(this->m_gst_pipeline);
    }
};