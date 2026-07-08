## ⚖️   Comparison: Python vs. C++ Implementation

This repository features two distinct implementations of the exact same RFC-inspired validation logic. Building both allows for direct cross-validation, ensuring accuracy while providing tools suited for different operational environments.

Here is a step-by-step breakdown of how the two approaches compare:

### 1. Execution & Performance
| Feature | Python 3 (`email_validator.py`) | C++ (`validator.cpp`) |
| :--- | :--- | :--- |
| **Type** | Interpreted Script | Compiled Binary |
| **Speed** | Fast (Good for standard tasks) | Ultra-fast (Good for massive datasets) |
| **Dependencies** | Python 3 runtime | Requires GCC/G++ compiler beforehand |
| **Portability** | Runs anywhere Python is installed | Highly portable once compiled |

### 2. String Manipulation
Both languages approach breaking down the email string differently:
* **Python:** Utilizes high-level built-in methods like `email.rsplit('@', 1)` to easily separate the local and domain parts in a single, safe operation.
* **C++:** Requires manual memory boundaries. It uses `email.find('@')` to locate the index, followed by `email.substr()` to slice the string into exact memory blocks.

### 3. Regular Expressions (Regex)
* **Python:** Uses the `re` module. The regex engine is highly optimized in C under the hood, making `re.fullmatch()` extremely reliable and easy to read.
* **C++:** Uses the standard `<regex>` library. Character escaping requires double backslashes (e.g., `\\-` instead of `\-`) because C++ processes string literals before the regex engine parses them. `std::regex_match` handles the full string validation.

### 4. Optimal Use Cases
Having both implementations allows you to choose the right tool for the job:

* **The Python Version:** Ideal for rapid automation, SOC analysts writing quick parsing scripts, or integrating into larger Python-based web applications (like Django/Flask).
* **The C++ Version:** Ideal for high-performance data sanitization, processing massive server traffic logs, or environments where raw execution speed and memory efficiency are critical.

> **Note on Cross-Validation:** Included in this repository is `run_both_validator.sh`, a bash wrapper that passes a single string into both programs simultaneously. This ensures both the interpreted and compiled versions yield the exact same security and validation results.
