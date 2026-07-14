# Array Library (C++)

A simple static array class implemented in C++, built from scratch as a learning project covering core data structure operations: insertion, deletion, searching, and aggregation, with careful attention to time complexity and edge cases (empty array, full array, out-of-bounds access).

## Files

- `array.h` — class declaration (`Array`)
- `array.cpp` — function definitions
- `main.cpp` — example usage / entry point
- `Makefile` — build automation

## Features

| Function | Description | Time Complexity |
|---|---|---|
| `Array(int cap)` | Constructor — allocates array with given capacity | O(1) |
| `~Array()` | Destructor — frees allocated memory | O(1) |
| `append(int n)` | Adds a value at the end | O(1) |
| `insert(int index, int n)` | Inserts a value at a given index, shifting others right | O(n) |
| `Delete(int index)` | Removes the value at a given index, shifting others left | O(n) |
| `display()` | Prints all elements | O(n) |
| `length()` | Returns number of elements currently stored | O(1) |
| `isEmpty()` | Checks if the array has no elements | O(1) |
| `isFull()` | Checks if the array has reached capacity | O(1) |
| `Max()` | Returns the largest value | O(n) |
| `Min()` | Returns the smallest value | O(n) |
| `sum()` | Returns the sum of all elements | O(n) |
| `average()` | Returns the average of all elements | O(n) |
| `linearsearch(int n)` | Searches for a value and prints all matching indices | O(n) |

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
   This compiles `array.cpp` and `main.cpp` together and produces `main.exe` (or `main` on Linux/macOS, depending on your Makefile).

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

- Add or modify class functions in `array.cpp`, and update the declaration in `array.h` if you add a new function.
- Write your test/demo code in `main.cpp`.
- Re-run `make` after any change — it only recompiles what's needed.

## Example

```cpp
#include "array.h"

int main(){
    Array arr(5);
    arr.append(10);
    arr.append(20);
    arr.insert(1, 15);
    arr.display();          // 10 15 20
    arr.Delete(0);
    arr.display();          // 15 20
    std::cout << arr.Max() << "\n";     // 20
    std::cout << arr.average() << "\n"; // 17.5
}
```

## License

This project is open source under the [MIT License](LICENSE) — free to use, modify, and distribute for anyone, including for learning purposes.

## Contributing

This is primarily a personal learning project, but suggestions and pull requests are welcome if you spot bugs or improvements.
