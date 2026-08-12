/*  
        note for myself


========================================
BINARY TREE TERMINOLOGY
========================================

A binary tree is a hierarchical data structure in which each node has
at most two children, called the left child and the right child.

----------------------------------------
BASIC TERMS
----------------------------------------

Node
    Basic element that stores data.

Edge
    Connection between a parent and a child.

Root
    Top-most node having no parent.

Parent
    Node directly above another node.

Child
    Node directly below another node.

Left Child
    Child connected through the left link.

Right Child
    Child connected through the right link.

Sibling
    Nodes sharing the same parent.

Leaf / External Node
    Node with no children.

Internal / Non-leaf Node
    Node having at least one child.

Ancestor
    Any node on the path from the root to a node.

Descendant
    Any node reachable downward from a node.

Subtree
    Tree formed by a node and all of its descendants.

Left Subtree
    Subtree rooted at the left child.

Right Subtree
    Subtree rooted at the right child.

----------------------------------------
DEGREE
----------------------------------------

Degree of a Node
    Number of children of that node.

Possible degrees in a binary tree:
    0, 1, or 2

Degree of a Binary Tree
    Maximum degree among all nodes.
    Always <= 2.

----------------------------------------
LEVEL, DEPTH, HEIGHT
----------------------------------------

Level of Root
    Usually 0.

Level of a Node
    Number of edges from root to the node.

Depth of a Node
    Same as level when root level is 0.

Height of a Node
    Number of edges in the longest path from that node to a leaf.

Height of Tree
    Height of the root.

Maximum Depth
    Same as tree height.

----------------------------------------
PATH TERMS
----------------------------------------

Path
    Sequence of connected nodes.

Path Length
    Number of edges in the path.

Distance(u, v)
    Number of edges in the shortest path between u and v.

----------------------------------------
STRUCTURAL TYPES
----------------------------------------

Binary Tree
    Each node has at most two children.

Strict Binary Tree
    Every node has either 0 or 2 children.
    No node has exactly one child.

Full Binary Tree
    Same as strict binary tree.

Proper Binary Tree
    Same as strict/full binary tree.

Perfect Binary Tree
    All internal nodes have exactly two children and all leaves are at
    the same level.

Complete Binary Tree
    Every level is completely filled except possibly the last level,
    and the last level is filled from left to right.

Balanced Binary Tree
    Height is approximately logarithmic in the number of nodes.

Height-Balanced Tree
    For every node, the height difference between left and right
    subtrees is within an allowed limit.

AVL Tree
    Height-balanced binary search tree with balance factor -1, 0, or 1.

Red-Black Tree
    Self-balancing binary search tree with color properties ensuring
    logarithmic height.

Degenerate Tree
    Every node has only one child.

Skewed Tree
    Special degenerate tree.

Left Skewed Tree
    Every node has only a left child.

Right Skewed Tree
    Every node has only a right child.

Extended Binary Tree
    NULL children are replaced by special external nodes.

Threaded Binary Tree
    NULL pointers are replaced with traversal links.

----------------------------------------
POSITIONAL TERMS
----------------------------------------

Root Position
    Top-most position.

Leaf Position
    Position with no children.

Internal Position
    Position occupied by an internal node.

Leftmost Node
    Node reached by repeatedly moving left.

Rightmost Node
    Node reached by repeatedly moving right.

----------------------------------------
SIZE RELATIONSHIPS
----------------------------------------

Let:
    N = total nodes
    I = internal nodes
    L = leaf nodes
    h = height

For any non-empty binary tree:
    N = I + L

For a full/strict binary tree:
    L = I + 1
    N = 2I + 1
    I = (N - 1) / 2
    L = (N + 1) / 2

For a perfect binary tree:
    Total Nodes = 2^(h + 1) - 1
    Leaves      = 2^h
    Internal    = 2^h - 1

Maximum nodes at level l:
    2^l

Maximum nodes in a binary tree of height h:
    2^(h + 1) - 1

Minimum possible height for N nodes:
    ceil(log2(N + 1)) - 1

Maximum possible height for N nodes:
    N - 1

----------------------------------------
ARRAY REPRESENTATION
----------------------------------------

For 0-based indexing:
    Parent(i)      = (i - 1) / 2
    LeftChild(i)   = 2i + 1
    RightChild(i)  = 2i + 2

Efficient for complete binary trees.

----------------------------------------
TRAVERSALS
----------------------------------------

Traversal
    Visiting every node exactly once.

----------------------------------------
DEPTH-FIRST TRAVERSALS
----------------------------------------

Preorder Traversal
    Visit Root
    Traverse Left Subtree
    Traverse Right Subtree

Order:
    Root -> Left -> Right

Example:
    A B D E C F G

Used for:
    Copying tree, prefix expression.

----------------------------------------

Inorder Traversal
    Traverse Left Subtree
    Visit Root
    Traverse Right Subtree

Order:
    Left -> Root -> Right

Example:
    D B E A F C G

In a Binary Search Tree, inorder gives sorted order.

----------------------------------------

Postorder Traversal
    Traverse Left Subtree
    Traverse Right Subtree
    Visit Root

Order:
    Left -> Right -> Root

Example:
    D E B F G C A

Used for:
    Deleting tree, postfix expression.

----------------------------------------
BREADTH-FIRST TRAVERSAL
----------------------------------------

Level Order Traversal
    Visit nodes level by level from top to bottom and left to right.

Example:
    A B C D E F G

Implemented using a queue.

----------------------------------------
TRAVERSAL IMPLEMENTATION TERMS
----------------------------------------

Recursive Traversal
    Uses function call stack.

Iterative Traversal
    Uses explicit stack or queue.

DFS
    Preorder, inorder, postorder.

BFS
    Level order traversal.

----------------------------------------
EXPRESSION TREE TERMS
----------------------------------------

Operand Node
    Leaf containing a value.

Operator Node
    Internal node containing an operator.

Prefix Expression
    Obtained by preorder traversal.

Infix Expression
    Obtained by inorder traversal.

Postfix Expression
    Obtained by postorder traversal.

----------------------------------------
BINARY SEARCH TREE (BST) TERMS
----------------------------------------

BST Property
    Left subtree keys < root key < right subtree keys.

Search Path
    Path followed during searching.

Successor
    Smallest node greater than a given node.

Predecessor
    Largest node smaller than a given node.

Minimum Node
    Leftmost node.

Maximum Node
    Rightmost node.

----------------------------------------
BALANCING TERMS
----------------------------------------

Balance Factor
    height(left) - height(right)

Left Heavy
    Balance factor > 0.

Right Heavy
    Balance factor < 0.

Rotation
    Local restructuring operation.

LL Rotation
RR Rotation
LR Rotation
RL Rotation

----------------------------------------
MEMORY TERMS
----------------------------------------

NULL Link
    Missing child pointer.

Pointer / Reference
    Address of another node.

Root Pointer
    Pointer to the root node.

----------------------------------------
IMPORTANT OBSERVATIONS
----------------------------------------

Perfect => Full and Complete.
Complete does not necessarily imply Full.
Full does not necessarily imply Complete.
Balanced does not necessarily imply Complete.
A skewed tree has height N - 1.
A complete binary tree is ideal for heap implementation.
Inorder traversal of a BST produces keys in sorted order.

----------------------------------------
ONE-LINE SUMMARY
----------------------------------------

Binary tree terminology covers node relationships, measurements
(level/depth/height), structural classes (strict/full/perfect/complete/
balanced/skewed), storage methods, traversal methods (preorder, inorder,
postorder, level order), BST properties, and balancing concepts such as
balance factor and rotations.
*/