# String Library (C++)

A simple dynamic string class implemented in C++, built from scratch as a learning project covering core string operations: case conversion, character/identifier checks, comparison, and searching, with attention to memory management and edge cases.

## Files

- `string.hpp` — class declaration (`MyString`)
- `string.cpp` — function definitions
- `main.cpp` — example usage / entry point
- `Makefile` — build automation

## Features

| Function | Description | Time Complexity |
|---|---|---|
| `MyString(const char *s)` | Constructor — allocates and copies from C-string | O(n) |
| `MyString(const MyString &other)` | Copy constructor — deep copy | O(n) |
| `~MyString()` | Destructor — frees allocated memory | O(1) |
| `display()` | Prints the string | O(n) |
| `length()` | Returns number of characters | O(1) |
| `isFull()` | Checks if size equals capacity | O(1) |
| `isEmpty()` | Checks if string has no characters | O(1) |
| `ToLowerCase()` | Converts all letters to lowercase, prints result | O(n) |
| `ToUpperCase()` | Converts all letters to uppercase, prints result | O(n) |
| `ToggleCase()` | Flips case of every letter, prints result | O(n) |
| `isAlphabetic()` | Checks if every character is a letter | O(n) |
| `hasAtleastOneChar()` | Checks if at least one letter exists | O(n) |
| `isNumeric()` | Checks if every character is a digit | O(n) |
| `hasLeastOneNum()` | Checks if at least one digit exists | O(n) |
| `isValidIdentifier()` | Checks if string is a valid identifier (letter/underscore start, alnum/underscore body) | O(n) |
| `compareStrings(MyString S1, MyString S2)` | Lexicographically compares two strings, prints result | O(n) |

## Requirements

- A C++ compiler supporting C++17 (e.g. `g++`)
- `make` (GNU Make)
- VS Code (optional, recommended) with the **C/C++** extension (by Microsoft)

## Usage in VS Code

1. **Clone or download** this repository and open the folder in VS Code:
```bash
   git clone <https://github.com/jawidolmas/DSA-with-cpp>
   cd libraries
   code .
```

2. **Install the C/C++ extension** (ms-vscode.cpptools) from the Extensions panel if you don't already have it — this gives you IntelliSense, debugging, and syntax support.

3. **Open a terminal inside VS Code** (`` Ctrl+` `` or Terminal → New Terminal). Make sure your terminal shell has access to `g++` and `make` (e.g. via MSYS2/MinGW on Windows, or your system's default compiler on macOS/Linux).

4. **Build the project** by running:
```bash
   make
```
   This compiles `string.cpp` and `main.cpp` together and produces `main.exe` (or `main` on Linux/macOS, depending on your Makefile).

5. **Run the program:**
```bash
   ./main.exe
```
   (On Windows Git Bash / PowerShell you can also just type `main.exe` or `.\main.exe`.)

6. **Clean up build artifacts** any time with:
```bash
   make clean
```

### Editing the code

- Add or modify class functions in `string.cpp`, and update the declaration in `string.hpp` if you add a new function.
- Write your test/demo code in `main.cpp`.
- Re-run `make` after any change — it only recompiles what's needed.

## Example

```cpp
#include "string.hpp"

int main(){
    MyString s1("Hello");
    MyString s2("World");
    s1.display();               // Hello
    std::cout << s1.length();   // 5
    s1.compareStrings(s1, s2);  // Second string is bigger
}
```

## Status

Work in progress. Several declared methods (`clear`, `isAlphanumeric`, `equalityCheck`, `linearSearchChar`, `countVowels`, `countConstants`, `countWords`, `duplicateCharDetect`) are declared in the header but not yet implemented.

## License

This project is open source under the [MIT License](LICENSE) — free to use, modify, and distribute for anyone, including for learning purposes.

## Contributing

This is primarily a personal learning project, but suggestions and pull requests are welcome if you spot bugs or improvements.