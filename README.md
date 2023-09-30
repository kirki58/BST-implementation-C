# Binary Search Tree
I've implemented Binary Search Tree data structure with some handy functions in C.

## What are BSTs?
A Binary Search Tree (BST) is a non-linear hierarchycal tree data structre with some special constraints like every node can have at most 2 children. BSTs are used in various fields and various jobs and can have more then one implementation.

## My functions
| name       | parameters           | returns | description                                                                                                                                                                       |
|------------|----------------------|---------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| init_node  | int val              | Node*   | allocates memory for a new node and returns a pointer to it                                                                                                                        |
| insert     | Node** root, int val | Node*   | inserts a new node with a key of `val` and returns a pointer to it                                                                                                                |
| search     | Node* root, int val  | Node*   | searchs for a specific node with value `val` starting from root node, returns a pointer to the found node on the first occurance or null pointer if there is no occurance at all. |
| isInTree   | Node* root, int val  | bool    | checks if a node with a key of `val` is existent in the tree, returns true if yes. just a shorthand of saying `search(root,val) != NULL`                                          |
| rightmost  | Node** root          | Node**  | returns a pointer to a pointer to the rightmost node in the tree.                                                                                                                  |
| leftmost   | Node** root          | Node**  | returns a pointer to a pointer to the leftmost node in the tree.                                                                                                                   |
| max        | Node* root           | int     | returns the biggest key in the tree.                                                                                                                                              |
| min        | Node* root           | int     | returns the smallest key in the tree.                                                                                                                                             |
| rm_node    | Node** root, int val | void    | removes the first occurance of a node with key `val`.                                                                                                                             |
| get_height | Node* root           | int     | returns the number of edges from root to the farthest leaf node.                                                                                                                  |
| get_depth  | Node* root, Node* nd | int     | returns the number of edges from the root node to `nd`                                                                                                                            |
