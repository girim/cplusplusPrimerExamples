#include <iostream>

class MessageConverter
{
    public:
        MessageConverter() = default;
        virtual ~MessageConverter() = default;

        virtual std::string convert(std::string msg)
        {
            return "[START] " + msg + " [END]";
        }
};

class NewMessageConverter : public MessageConverter
{
    public:
        NewMessageConverter() = default;
        virtual ~NewMessageConverter() = default;

        virtual std::string convert(std::string msg)
        {
            return "<START> " + msg + " <END>";
        }
};

class LatestMessageConverter : public MessageConverter
{
    public:
        LatestMessageConverter() = default;
        virtual ~LatestMessageConverter() = default;

        virtual std::string convert(std::string msg)
        {
            return "#START# " + msg + " #END#";
        }
};

class MessageSender
{
    public:
        MessageSender() : msgConverter_(nullptr){};
        virtual ~MessageSender(){};

        void setMessageConverter(MessageConverter& msgConverter)
        {
            msgConverter_ = &msgConverter;
        }

        void sendMessage(std::string msg)
        {
            std::string sentMsg =  msgConverter_->convert(msg);
            std::cout << "Message sent: " << sentMsg << "\n";
        }

    private:
        MessageConverter *msgConverter_;
};

int main(int argc, char const *argv[])
{
    MessageSender msgSender{};
    MessageConverter msgConverter{};
    NewMessageConverter newMsgConverter{};
    LatestMessageConverter latestMessageConverter{};

    msgSender.setMessageConverter(msgConverter);
    msgSender.sendMessage("Hello C++!");

    msgSender.setMessageConverter(newMsgConverter);
    msgSender.sendMessage("Hello C++!");


    msgSender.setMessageConverter(latestMessageConverter);
    msgSender.sendMessage("Hello C++!");

    return 0;
}
