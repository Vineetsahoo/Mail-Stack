#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "mail.h"

void save_mail(const Mail& mail, const std::string& folder);
std::vector<Mail> load_mails(const std::string& folder);
Mail load_mail_by_id(const std::string& folder, const std::string& id);
bool delete_mail(const std::string& folder, const std::string& id);

#endif