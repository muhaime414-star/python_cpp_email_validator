#!/bin/bash

# Check if the user provided an email address
if [ -z "$1" ]; then
    echo -e "\033[93m[-] Usage: ./run_both_validator.sh <email_address>\033[0m"
    exit 1
fi

EMAIL=$1

echo -e "\033[96m=======================================\033[0m"
echo -e "\033[96m    Cross-Validating Email Address     \033[0m"
echo -e "\033[96m=======================================\033[0m\n"

# Run the Python Script, passing the email directly
echo -e "\033[93m[-->] Python3 Implementation:\033[0m"
python3 email_validator.py "$EMAIL"

echo ""

# Run the C++ Binary, passing the email directly
echo -e "\033[93m[-->] C++ Implementation:\033[0m"
./validator "$EMAIL"

echo ""
echo -e "\033[96m=======================================\033[0m"