#include "mail.h"
#include <random>
#include <sstream>
#include <ctime>

std::string generate_message_id() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100000, 999999);
    std::stringstream ss;
    ss << std::time(nullptr) << "-" << dis(gen);
    return ss.str();
}

std::string mail_to_string(const Mail& mail) {
    std::stringstream ss;
    ss << "From: " << mail.from << "\n"
       << "To: " << mail.to << "\n"
       << "Subject: " << mail.subject << "\n"
       << "ID: " << mail.id << "\n"
       << "\n"
       << mail.body << "\n"
       << "--END--\n";
    return ss.str();
}

Mail string_to_mail(const std::string& data) {
    Mail mail;
    std::stringstream ss(data);
    std::string line;
    std::string current_field;

    while (std::getline(ss, line) && line != "--END--") {
        if (line.substr(0, 5) == "From:") {
            mail.from = line.substr(6);
        } else if (line.substr(0, 3) == "To:") {
            mail.to = line.substr(4);
        } else if (line.substr(0, 8) == "Subject:") {
            mail.subject = line.substr(9);
        } else if (line.substr(0, 3) == "ID:") {
            mail.id = line.substr(4);
        } else if (!line.empty()) {
            mail.body += line + "\n";
        }
    }
    return mail;
}