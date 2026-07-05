#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

class Email_validator {
private:
    std::regex name_pattern;
    std::regex domain_pattern;

public:
    Email_validator() {
        name_pattern = std::regex("^[a-zA-Z0-9!#$'*+\\-/=?^_`{|}~.]+$");
        domain_pattern = std::regex("^[a-zA-Z0-9.-]+$");
    }

    bool validate(const std::string& email) {
        if (email.empty() || email.length() > 254) return false;
        if (std::count(email.begin(), email.end(), '@') != 1) return false;
        
        size_t spliting_the_whole_mail = email.find('@');

        std::string name_part = email.substr(0, spliting_the_whole_mail);
        std::string domain_part = email.substr(spliting_the_whole_mail + 1);

        if (name_part.empty() || name_part.length() > 64) return false;
        if (name_part.front() == '.' || name_part.back() == '.') return false;
        if (domain_part.front() == '.' || domain_part.back() == '.') return false;
        if (name_part.find("..") != std::string::npos) return false;
        if (domain_part.find("..") != std::string::npos) return false;

        bool is_quoted = false;
        if (name_part.length() >= 2 && name_part.front() == '"' && name_part.back() == '"') {
            is_quoted = true;
        }
        
        std::string name_test = is_quoted ? name_part.substr(1, name_part.length() - 2) : name_part;

        if (!is_quoted && !std::regex_match(name_test, name_pattern)) return false;
        if (!std::regex_match(domain_part, domain_pattern)) return false;
        if (domain_part.find('.') == std::string::npos) return false;

        return true;
    }
};

int main(int argc, char* argv[]) {
    // Check if an email was passed as an argument
    if (argc < 2) {
        std::cerr << "[-] Usage: ./validator <email_address>\n";
        return 1;
    }

    Email_validator validator;
    
    // Grab the exact string passed in the terminal
    std::string email = argv[1];
    
    bool isValid = validator.validate(email);
    
    if (isValid) {
        std::cout << "\033[92m[Valid]\033[0m " << email << "\n";
    } else {
        std::cout << "\033[91m[Invalid]\033[0m " << email << "\n";
    }

    return 0;
}