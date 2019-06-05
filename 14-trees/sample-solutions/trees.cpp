#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;
};

template <typename T>
void add_to_tree(TreeNode<T> *& root, T element) {
    if (root == NULL) {
        root = new TreeNode<T>;
        root->data = element;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if (root->data >= element) {
      add_to_tree(root->left, element);
    } else {
      add_to_tree(root->right, element);
    }

}

template<typename T>
void delete_tree(TreeNode<T>* root) {
  if (root == NULL) {
    return;
  }
  delete_tree(root->left);
  delete_tree(root->right);
  delete root;
}

template<typename T>
void left_root_right_print(TreeNode<T>* root) {
  if (root == NULL) {
    return;
  }
  left_root_right_print(root->left);
  cout << root->data << ' ';
  left_root_right_print(root->right);
}

template<typename T>
void right_root_left_print(TreeNode<T>* root) {
  if (root == NULL) {
    return;
  }
  right_root_left_print(root->right);
  cout << root->data << ' ';
  right_root_left_print(root->left);
  delete root;
}

template<typename T>
TreeNode<T>*& find_node(TreeNode<T> *& root, T element) {
  if (root == NULL || root->data == element) {
    return root;
  }

  if (root->data >= element) {
     return find_node(root->left);
  } else {
    return find_node(root->right);
  }
}

template <typename T>
bool contains(TreeNode<T>* root, T element) {
  return find_node(root, element) != NULL;
}

template <typename T>
TreeNode<T> *& get_smallest(TreeNode<T>*& root) {
  if (root->left == NULL) {
    return root;
  }
  return get_smallest(root->left);
}

template <typename T>
void delete_element(TreeNode<T>* root, T element) {
  TreeNode<T> *& node = find_node(root, element);
  if (node == NULL) {
      return;
  }
  TreeNode<T>*& smallest = get_smallest(node->right); 
  node->data = smallest->element;
  if (smallest->right) {
    delete_element(smallest, smallest->element);
  }
  else {
    delete smallest;
  }
}

int main() {
  TreeNode<int> * t = NULL;
  add_to_tree(t, 5);
  add_to_tree(t, 3);
  add_to_tree(t, -1);
  add_to_tree(t, 7);
  add_to_tree(t, 6);
  add_to_tree(t, 10);
  add_to_tree(t, 8);
  
  left_root_right_print(t);
  return 0;
}
