/*
    Note for myself.

========================================
TREE TERMINOLOGY
========================================

A tree is a non-linear hierarchical data structure made of nodes connected by edges.
A tree with N nodes always has N - 1 edges and contains no cycles.

----------------------------------------
BASIC TERMS
----------------------------------------

Node
    Basic element that stores data.

Edge
    Connection between two nodes.

Root
    Top-most node with no parent.

Parent
    A node that has one or more children.

Child
    A node directly connected below another node.

Siblings
    Nodes having the same parent.

Leaf / External / Terminal Node
    Node with no children.

Internal / Non-leaf Node
    Node having at least one child.

Ancestor
    Any node on the path from the root to a given node.

Descendant
    Any node reachable downward from a given node.

Subtree
    A tree formed by a node and all of its descendants.

Forest
    A collection of disjoint trees.

----------------------------------------
DEGREE
----------------------------------------

Degree of a Node
    Number of children of that node (common in data structures).

Degree in Graph Sense
    Number of edges incident to the node.

Degree of a Tree
    Maximum degree among all nodes.

----------------------------------------
LEVEL, DEPTH, HEIGHT
----------------------------------------

Level of Root
    Usually 0 (sometimes 1 depending on convention).

Level of a Node
    Number of edges from the root to the node.

Depth of a Node
    Same as level when root level is 0.

Height of a Node
    Number of edges in the longest path from that node to a leaf.

Height of a Tree
    Height of the root.
    Maximum depth of any node.

----------------------------------------
PATH RELATED TERMS
----------------------------------------

Path
    Sequence of nodes connected by edges.

Path Length
    Number of edges in the path.

Simple Path
    Path with no repeated nodes.

Distance(u, v)
    Number of edges in the shortest path between u and v.

----------------------------------------
ORDERING TERMS
----------------------------------------

Ordered Tree
    Children have a fixed order.

Unordered Tree
    Children have no order.

Left Child
    First child in an ordered tree.

Right Child
    Second child in a binary tree.

----------------------------------------
BINARY TREE TERMS
----------------------------------------

Binary Tree
    Each node has at most two children.

Full Binary Tree
    Every node has either 0 or 2 children.

Perfect Binary Tree
    All internal nodes have 2 children and all leaves are at the same level.

Complete Binary Tree
    All levels are full except possibly the last, filled from left to right.

Balanced Binary Tree
    Height is approximately logarithmic in the number of nodes.

Degenerate / Skewed Tree
    Every node has only one child; behaves like a linked list.

Strict Binary Tree
    Same as full binary tree.

----------------------------------------
POSITIONAL TERMS
----------------------------------------

Left Subtree
    Subtree rooted at the left child.

Right Subtree
    Subtree rooted at the right child.

Node Position
    Relative location in the tree.

----------------------------------------
SIZE TERMS
----------------------------------------

Size of a Tree
    Total number of nodes.

Number of Leaves
    Count of leaf nodes.

Number of Internal Nodes
    Count of non-leaf nodes.

For a full binary tree:
    Leaves = Internal Nodes + 1

----------------------------------------
TRAVERSAL TERMINOLOGY
----------------------------------------

Traversal
    Visiting every node exactly once.

Depth-First Traversals
    Preorder  : Root, Left, Right
    Inorder   : Left, Root, Right
    Postorder : Left, Right, Root

Breadth-First Traversal
    Level Order : Visit level by level from top to bottom.

----------------------------------------
SPECIAL RELATIONSHIPS
----------------------------------------

Lowest Common Ancestor (LCA)
    Deepest node that is an ancestor of both given nodes.

Nearest Common Ancestor
    Same as LCA.

----------------------------------------
STRUCTURAL PROPERTIES
----------------------------------------

Connected
    Every pair of nodes has a path between them.

Acyclic
    Contains no cycles.

Unique Path Property
    Exactly one simple path exists between any two nodes.

----------------------------------------
REPRESENTATION TERMS
----------------------------------------

Linked Representation
    Nodes store pointers/references to children.

Array Representation
    Nodes stored in an array, commonly used for complete binary trees.

Adjacency List Representation
    Each node stores a list of adjacent nodes.

----------------------------------------
SEARCH / UPDATE OPERATIONS
----------------------------------------

Insertion
    Add a new node.

Deletion
    Remove a node and reconnect if necessary.

Search
    Find a node with a given key/value.

----------------------------------------
COMMON CONFUSIONS
----------------------------------------

Height vs Depth
    Height is measured downward to leaves.
    Depth is measured upward from the root.

Leaf Degree
    Degree by children = 0.
    Degree by graph edges = 1 (except a single-node tree where it is 0).

Root Height
    Equals the height of the entire tree.

----------------------------------------
IMPORTANT FORMULAS
----------------------------------------

For any tree:
    Edges = Nodes - 1

For a perfect binary tree of height h:
    Total Nodes = 2^(h + 1) - 1
    Leaves      = 2^h
    Internal    = 2^h - 1

For a complete binary tree:
    Height = floor(log2(N))

----------------------------------------
ONE-LINE SUMMARY
----------------------------------------

Tree terminology revolves around hierarchy (root, parent, child, ancestor),
structure (degree, subtree, forest), measurement (level, depth, height),
special forms (binary, full, perfect, complete, balanced), and traversal
(preorder, inorder, postorder, level order).
*/