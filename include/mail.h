#ifndef MAIL_H
#define MAIL_H

#include <string>

struct Mail {
    std::string id;
    std::string from;
    std::string to;
    std::string subject;
    std::string body;
};

std::string generate_message_id();
std::string mail_to_string(const Mail& mail);
Mail string_to_mail(const std::string& data);

#endif