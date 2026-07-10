# Tower of Hanoi (TOH)

## Overview

The **Tower of Hanoi** is a classic mathematical puzzle and one of the most famous examples used to teach **recursion**, **algorithmic thinking**, and **problem decomposition**. [web:36][web:41][web:46]

It consists of:
- **Three rods (pegs)**: usually labeled A (Source), B (Auxiliary), and C (Destination).
- **n disks** of different sizes, initially stacked on rod A in decreasing order of size (largest at the bottom, smallest at the top).

**Goal:** Move the entire stack from rod A to rod C.

**Rules:**
1. Only **one disk** can be moved at a time.
2. Only the **top disk** of any rod can be moved.
3. A **larger disk cannot be placed on top of a smaller disk**.

---

## History

- Invented in **1883** by the French mathematician **Édouard Lucas**. [web:41][web:46][web:49]
- First published under the pseudonym **Professor N. Claus de Siam** (an anagram of “Lucas d’Amiens”). [web:46]
- Lucas created a **legendary backstory**: monks in a temple in **Benares (Varanasi), India**, are moving a tower of **64 golden disks** (the “Tower of Brahma”). When they finish, the temple will crumble and the world will end. [web:46][web:48]
- With 64 disks, the minimum number of moves is:
  \[
  2^{64} - 1 \approx 1.84 \times 10^{19}
  \]
  At one move per second, this would take hundreds of billions of years—far longer than the current age of the universe. [web:46][web:48]

Despite the myth, there is **no known record** of the puzzle or legend before 1883; it was essentially invented along with its story. [web:49]

---

## Recursive Solution

The Tower of Hanoi is a textbook example of a **recursive divide-and-conquer** algorithm. [web:42][web:44][web:45]

### Idea

To move **n disks** from source rod `A` to destination rod `C` using auxiliary rod `B`:

1. **Recursively** move `n-1` disks from `A` to `B` (using `C` as auxiliary).
2. Move the **largest disk** (disk `n`) from `A` to `C`.
3. **Recursively** move the `n-1` disks from `B` to `C` (using `A` as auxiliary).

### Base case

- If `n == 1`, simply move the single disk directly from the source rod to the destination rod.

### Pseudocode

```text
Hanoi(n, source, auxiliary, destination):
    if n == 1:
        move disk from source to destination
    else:
        Hanoi(n-1, source, destination, auxiliary)
        move disk n from source to destination
        Hanoi(n-1, auxiliary, source, destination)
```

In C++ this typically looks like:

```cpp
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        // Move disk 1 from 'from' to 'to'
        return;
    }
    hanoi(n - 1, from, to, aux);
    // Move disk n from 'from' to 'to'
    hanoi(n - 1, aux, from, to);
}
```

---

## Number of Moves and Complexity

### Minimum number of moves

For `n` disks, the **minimum** number of moves required is:

\[
M(n) = 2^n - 1
\]

Examples:  
- 1 disk → 1 move  
- 2 disks → 3 moves  
- 3 disks → 7 moves  
- 4 disks → 15 moves  
- 64 disks → \(2^{64} - 1\) moves [web:44][web:45][web:46]

### Time complexity

- Each call (except base cases) makes **two recursive calls**.
- The recurrence for the number of moves is:
  \[
  M(n) = 2M(n-1) + 1,\quad M(1) = 1
  \]
  which solves to \(M(n) = 2^n - 1\).

Thus, the **time complexity** of the recursive solution is:

O(2^n)

This is **optimal** in terms of number of moves; no algorithm can solve TOH with fewer moves while obeying the rules. [web:42][web:44][web:45]

### Space complexity

- The recursion depth is at most `n` (one level per disk).
- Therefore, the **space complexity** (call stack) is:

O(n)

---

## How and When to Use This Solution

Use the recursive Tower of Hanoi approach when:

- You want to **illustrate recursion** and **divide-and-conquer** in teaching or learning.
- You need a **clear, simple recursive algorithm** with a well-defined base case and recurrence.
- You are analyzing **exponential-time algorithms** and recurrence relations.
- You are building educational tools, visualizations, or puzzles.

It is **not practical** for large `n` in real applications due to exponential growth:
- For `n = 30`, moves ≈ \(2^{30} - 1 \approx 10^9\).
- For `n = 64`, moves ≈ \(1.84 \times 10^{19}\).

---

## Variations and Extensions

Common variations include:

- **More than 3 rods** (e.g., Frame–Stewart algorithm for 4 or more pegs).
- **Restricted moves** (e.g., only clockwise moves allowed).
- **Colored disks** or additional constraints on which disk can go where.
- **Iterative solutions** using bit manipulation or explicit stacks instead of recursion.

These variations are often used in advanced algorithm courses and research on optimal strategies. [web:36][web:47]

---

## References

- Wikipedia: Tower of Hanoi – history, rules, and mathematics. [web:36]  
- Édouard Lucas, 1883 – invention and legend of the Tower of Brahma. [web:41][web:46][web:49]  
- Recursive algorithm and complexity analysis. [web:42][web:44][web:45]
