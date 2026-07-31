# Linked List Library (C++)

A simple singly linked list class implemented in C++, built from scratch as a learning project covering core data structure operations: insertion, deletion, searching, and reversal, with careful attention to time complexity and edge cases (empty list, single-node list, out-of-bounds access).

## Files

- `linkedlist.hpp` — class declaration (`linkedlist`)
- `linkedlist.cpp` — function definitions
- `main.cpp` — example usage / entry point
- `Makefile` — build automation

## Features

| Function | Description | Time Complexity |
|---|---|---|
| `linkedlist()` | Constructor — initializes empty list | O(1) |
| `~linkedlist()` | Destructor — frees all allocated nodes | O(n) |
| `length()` | Returns number of nodes currently stored | O(n) |
| `isEmpty()` | Checks if the list has no nodes | O(1) |
| `display()` | Prints all elements | O(n) |
| `clearList()` | Deletes all nodes, resets list to empty | O(n) |
| `prepend(int value)` | Adds a value at the beginning | O(1) |
| `append(int value)` | Adds a value at the end | O(n) |
| `insert(int index, int value)` | Inserts a value at a given 0-based index, shifting others right | O(n) |
| `removeFirst()` | Removes and returns the first element | O(1) |
| `removeLast()` | Removes and returns the last element | O(n) |
| `removeIndex(int index)` | Removes and returns the value at a given 1-based index | O(n) |
| `linearSearch(int key)` | Searches for a value, returns whether it exists | O(n) |
| `getElement(int index)` | Returns the value at a given 0-based index | O(n) |
| `setElement(int index, int value)` | Replaces a value at a given 0-based index with new value | O(n) |
| `reverse()` | Reverses the list in place | O(n) |

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
   This compiles `linkedlist.cpp` and `main.cpp` together and produces `main.exe` (or `main` on Linux/macOS, depending on your Makefile).

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

- Add or modify class functions in `linkedlist.cpp`, and update the declaration in `linkedlist.hpp` if you add a new function.
- Write your test/demo code in `main.cpp`.
- Re-run `make` after any change — it only recompiles what's needed.

## Example

```cpp
#include "linkedlist.hpp"

int main(){
    linkedlist lin;
    lin.append(10);
    lin.append(20);
    lin.prepend(5);
    lin.display();          // 5 10 20
    lin.removeFirst();
    lin.display();          // 10 20
    std::cout << lin.getElement(1) << "\n";   // 20
    lin.reverse();
    lin.display();          // 20 10
}
```

## Known Issues

- `getElement` / `setElement` bounds check has an off-by-one at the upper limit
  (`index > length()` instead of `index >= length()`), allowing `index == length()`
  to slip through and dereference a null pointer.
- No copy constructor / copy assignment operator defined — copying a `linkedlist`
  by value shallow-copies `head` and will double-free on destruction.

## License

This project is open source under the [MIT License](LICENSE) — free to use, modify, and distribute for anyone, including for learning purposes.

## Contributing

This is primarily a personal learning project, but suggestions and pull requests are welcome if you spot bugs or improvements.
