#pragma once

#include "PhoneBook.hpp"

#include <string>

bool getInput(const std::string& prompt, std::string& input);
void addContactRoutine(PhoneBook& phoneBook);
void searchContactRoutine(PhoneBook& phoneBook);
bool validateStrictNumberFormat(const std::string& str);
bool validatePhoneNumberFormat(const std::string& str);
