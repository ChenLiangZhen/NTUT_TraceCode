#include <cstdio>
#include <cstdlib>
#include <memory>

#ifndef BUILD_TREE
#define BUILD_TREE

typedef struct tree_node {
   int data;
   struct tree_node *left;
   struct tree_node *right;
} node_t;

typedef node_t *nodep_t;

class BuildTree{
public:

   nodep_t createNode(int value) {
      nodep_t p = (nodep_t) malloc(sizeof(node_t));
      p->data = value;
      p->left = nullptr;
      p->right = nullptr;
      return p;
   }

   void freeNode(nodep_t node){
      free(node);
   }

   void build(nodep_t current, nodep_t newNode, int value) {
      nodep_t parent;
      while (true) {
         parent = current;
         if (value < parent->data) {
            current = current->left;
            if (current == nullptr) {
               parent->left = newNode;
               return;
            }
         } else {
            current = current->right;
            if (current == nullptr) {
               parent->right = newNode;
               return;
            }
         }
      }
   }

   nodep_t insert(nodep_t root, int value) {
      nodep_t current, parent, newNode;
      newNode = createNode(value);
      if (root == nullptr) {
         root = newNode;
      } else {
         parent = current = root;
         build(current, newNode, value);
      }
      return root;
   }

   void inorder_transversal(nodep_t root) {
      if (root != nullptr) {
         inorder_transversal(root->left);
         printf("%d ", root->data);
         inorder_transversal(root->right);
      }
   }

   void preorder_traversal(nodep_t root) {
      if (root != nullptr) {
         printf("%d ", root->data);
         preorder_traversal(root->left);
         preorder_traversal(root->right);
      }
   }

   void postorder_traversal(nodep_t root) {
      if (root != nullptr) {
         postorder_traversal(root->left);
         postorder_traversal(root->right);
         printf("%d ", root->data);
         free(root);
      }
   }
};


#endif

//
//
//
//
//int main() {
//
//   nodep_t root = nullptr;
//   auto* bt = new BuildTree();
//
//   int array[] = {23, 12, 43, 21,65,3,2};
//   for (int i : array) {
//      root = bt->insert(root, i);
//   }
//
//   bt->inorder_transversal(root);
//   printf("\n");
//   bt->postorder_traversal(root);
//   printf("\n");
//   bt->preorder_traversal(root);
//
//   return EXIT_SUCCESS;
//}