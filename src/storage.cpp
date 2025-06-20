#include "storage.h"
#include "mail.h"
#include <fstream>
#include <vector>
#include <algorithm>

void save_mail(const Mail& mail, const std::string& folder) {
    std::string filename = "data/" + folder + ".mbox";
    std::ofstream out(filename, std::ios::app);
    if (out.is_open()) {
        out << mail_to_string(mail);
        out.close();
    }
}

std::vector<Mail> load_mails(const std::string& folder) {
    std::vector<Mail> mails;
    std::string filename = "data/" + folder + ".mbox";
    std::ifstream in(filename);
    std::string data, message;

    while (std::getline(in, data)) {
        if (data == "--END--") {
            mails.push_back(string_to_mail(message));
            message.clear();
        } else {
            message += data + "\n";
        }
    }
    in.close();
    return mails;
}

Mail load_mail_by_id(const std::string& folder, const std::string& id) {
    std::vector<Mail> mails = load_mails(folder);
    for (const auto& mail : mails) {
        if (mail.id == id) {
            return mail;
        }
    }
    return Mail();
}

bool delete_mail(const std::string& folder, const std::string& id) {
    std::vector<Mail> mails = load_mails(folder);
    auto it = std::find_if(mails.begin(), mails.end(),
        [&id](const Mail& mail) { return mail.id == id; });
    if (it == mails.end()) {
        return false;
    }
    mails.erase(it);
    std::string filename = "data/" + folder + ".mbox";
    std::ofstream out(filename);
    for (const auto& mail : mails) {
        out << mail_to_string(mail);
    }
    out.close();
    return true;
}