import re
import sys

class Email_Validator:
    def __init__(self):
        self.name_pattern = re.compile(r"^[a-zA-Z0-9!#$%&'*+\-/=?^_`{|}~.]+$")
        self.domain_pattern = re.compile(r"^[a-zA-Z0-9.-]+$")

    def validate(self, email: str) -> bool:
        if email == "" or len(email) > 254:
            return False, "Failed: Length exceeds 254 characters or is empty."

        if email.count('@') != 1: 
            return False
        name_part, domain_part = email.rsplit('@', 1)

        if name_part == "" or len(name_part) > 64:
            return False

        if name_part.startswith('.') or name_part.endswith('.'):
            return False

        if domain_part.startswith('.') or domain_part.endswith('.'):
            return False

        if ".." in name_part:
            return False

        if ".." in domain_part:
            return False

        is_quoted = (
            name_part.startswith('"') and 
            name_part.endswith('"')
        )
        name_test = name_part[1:-1] if is_quoted else name_part

        if not is_quoted and not self.name_pattern.fullmatch(name_test):
            return False

        if not self.domain_pattern.fullmatch(domain_part):
            return False

        if '.' not in domain_part:
            return False

        return True, "Valid email format."


if __name__ == "__main__":
    # Check if an email was passed as an argument
    if len(sys.argv) < 2:
        print("[-] Usage: python3 email_validator.py <email_address>")
        sys.exit(1)
        
    validator = Email_Validator()
    
    # Grab the exact string passed in the terminal
    email = sys.argv[1]
    
    is_valid = validator.validate(email)
    status = "\033[92m[Valid]\033[0m" if is_valid else "\033[91m[Invalid]\033[0m"
    print(f"{status} {email}")