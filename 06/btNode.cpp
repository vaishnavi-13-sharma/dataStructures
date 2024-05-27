#include "btNode.h"

// write definition for bst_insert here
void bst_insert(btNode *&root,int insInt) {
  if (root == nullptr) {
    root = new btNode;
    root->data = insInt;
    root->left = nullptr;
    root->right = nullptr;
  } else {
    btNode *current = root;
    while (true) {
      if (insInt == current->data) {
        current->data = insInt;
        return;
      } else if (insInt < current->data) {
        if (current->left == nullptr) {
          current->left = new btNode;
          current->left->data = insInt;
          current->left->left = nullptr;
          current->left->right = nullptr;
          return;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == nullptr) {
          current->right = new btNode;
          current->right->data = insInt;
          current->right->left = nullptr;
          current->right->right = nullptr;
          return;
        } else {
          current = current->right;
        }
      }
    }
  }
}

// write definition for bst_remove here
bool bst_remove(btNode *&root, int remInt) {
  if (root == nullptr) {
    return false;
  }
  if (remInt < root->data) {
    return bst_remove(root->left, remInt);
  } else if (remInt > root->data) {
    return bst_remove(root->right, remInt);
  } else {
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr;
    } else if (root->left == nullptr) {
      btNode *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == nullptr) {
      btNode *temp = root;
      root = root->left;
      delete temp;
    } else {
      btNode *maxNode = root->left;
      while (maxNode->right != nullptr) {
        maxNode = maxNode->right;
      }
      root->data = maxNode->data;
      bst_remove_max(root->left, maxNode->data);
    }
    return true;
  }
}

// write definition for bst_remove_max here
void bst_remove_max(btNode *&root, int &removed) {
  if (root->right == nullptr) {
    removed = root->data;
    btNode *temp = root;
    root = root->left;
    delete temp;
  } else {
    bst_remove_max(root->right, removed);
  }
}

void portToArrayInOrder(btNode *bst_root, int *portArray) {
  if (bst_root == 0)
    return;
  int portIndex = 0;
  portToArrayInOrderAux(bst_root, portArray, portIndex);
}

void portToArrayInOrderAux(btNode *bst_root, int *portArray, int &portIndex) {
  if (bst_root == 0)
    return;
  portToArrayInOrderAux(bst_root->left, portArray, portIndex);
  portArray[portIndex++] = bst_root->data;
  portToArrayInOrderAux(bst_root->right, portArray, portIndex);
}

void tree_clear(btNode *&root) {
  if (root == 0)
    return;
  tree_clear(root->left);
  tree_clear(root->right);
  delete root;
  root = 0;
}

int bst_size(btNode *bst_root) {
  if (bst_root == 0)
    return 0;
  return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}
