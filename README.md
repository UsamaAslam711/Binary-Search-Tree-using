# Binary-Search-Tree-using
A binary search tree is a data structure in which each node has at most two children, and the values in the left subtree of a node are less than the value of the node, while the values in the right subtree are greater than or equal to the value of the node.

A binary search tree (BST) is a data structure where each node in the tree has at most two children, and the values in the left subtree of a node are less than the value of the node, while the values in the right subtree are greater than or equal to the value of the node. Here's a step-by-step procedure for working with a BST:

To create a BST, start with an empty tree.

To insert a new element into the BST, start at the root node and compare the value to be inserted with the value of the current node. If the value is less than the current node, move to the left child node; if the value is greater than or equal to the current node, move to the right child node. Repeat this process until an empty child node is reached, and then insert the new element at that position.

To search for an element in the BST, start at the root node and compare the value to be searched with the value of the current node. If the value is less than the current node, move to the left child node; if the value is greater than the current node, move to the right child node. Repeat this process until the element is found or an empty child node is reached, indicating that the element is not present in the tree.

To delete an element from the BST, first search for the element using the procedure outlined in step 3. If the element is not found, there is nothing to delete. If the element is found, there are three cases to consider:

a. If the node to be deleted has no children, simply remove the node from the tree.

b. If the node to be deleted has one child, replace the node with its child.

c. If the node to be deleted has two children, find the minimum value in the right subtree (or the maximum value in the left subtree), replace the node to be deleted with that value, and then delete the node containing that value.

To traverse the elements of the BST in a particular order, there are three common algorithms: inorder, preorder, and postorder traversal. Inorder traversal visits the left subtree, the current node, and then the right subtree; preorder traversal visits the current node, the left subtree, and then the right subtree; postorder traversal visits the left subtree, the right subtree, and then the current node.
