#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
    struct tree_node *left, *right; // *parent;
    int val;
    int height;
    tree_node(int v) : val(v), left(NULL), right(NULL), height(1) {}
};

struct tree_root
{
    struct tree_node * root_node;
};


void printTreeValue(tree_node * node)
{
    printf("tree_node's value : %d \n", node->val);
}

void insert(tree_node * _root, tree_node * _node)
{
    if (_root->val > _node->val)
    {
        if (_root->left == NULL)
        {
            _root->left = _node;
        }
        else
        {
            insert(_root->left, _node);
        }
    }
    else
    {
        if (_root->val < _node->val)
        {
            if (_root->right == NULL)
            {
                _root->right = _node;
            }
            else
            {
                insert(_root->right, _node);
                //_root->height += 1;
            }
        }
    }
    //_root->height = std::max((_root->left == NULL ? 0 : _root->left->height), (_root->right == NULL ? 0 : _root->right->height) + 1);
    int left_tree_height = _root->left == NULL ? 0 : _root->left->height;
    int right_tree_height = _root->right == NULL ? 0 : _root->right->height;
    _root->height = std::max(left_tree_height, right_tree_height) + 1;
}

// Recursive tranverse all values pre-order.
void pre_order_tranverse(tree_node * root_node)
{
    if (root_node == NULL)
        return;
    else
    {
        printf("current root's value: %d, height : %d , balance_factor %d\n", root_node->val, root_node->height, 
        (-(root_node->left==NULL?0:root_node->left->height)+(root_node->right==NULL?:root_node->right->height)));
        pre_order_tranverse(root_node->left);
        pre_order_tranverse(root_node->right);
    }
}

/* left rotate 
         c  (-2)                      
        /
       b  (-1)    =>           b (0)
      /                      /   \
     a   (0)                a (0) c (0) 
* 
* Make the parent point to the balanced tree at the last step. 
* At first, the parent points to the c node, and b node
*/
void left_rotate(tree_node ** parent, tree_node * root)
{
    tree_node * new_root = root->left;
    new_root->right = root;
    root->left = NULL;
    root->height = 0;
    new_root->height = 0;
    *parent = new_root;
}

/**
 *  Right rotatation is the symmetric with the left rotatation.
 */
void right_rotate(tree_node ** parent, tree_node * root)
{
    tree_node * new_root = root->right;
    new_root->left = root;
    root->right = NULL;
    root->height = 0;
    new_root->height = 0;
    *parent = new_root;
}

/**
 * 
 *  Left-Right rotation 
 *          c  (-2)                 c  (-2)            
 *         /                       /                 
 *        a  (+1)       =>        b (-1)    =>      b (0)
 *          \                    /                 /  \
 *            b  (0)            a  (0)           a(0)  c (0)
 */

void left_right_rotate(tree_node ** parent, tree_node * root)
{
    tree_node * current_mid_node = root->left;
    tree_node * new_mid_node = current_mid_node->right;
    root->left = new_mid_node;
    new_mid_node->left = current_mid_node;
    new_mid_node->height = -1;
    current_mid_node->right = NULL;
    current_mid_node->height = 0;
    left_rotate(parent, root);
}

void right_left_rotate(tree_node ** parent, tree_node * root)
{
    tree_node * current_mid_node = root->right;
    tree_node * new_mid_node = current_mid_node->left;
    root->right = new_mid_node;
    new_mid_node->right = current_mid_node;
    new_mid_node->height = -1;
    current_mid_node->left = NULL;
    current_mid_node->height = 0;
    right_rotate(parent, root);
}

void delete_node(tree_node ** root, int value)
{
    if ((*root) == NULL)
    {
        return;
    }
    if ((*root)->val == value)
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            (*root) = NULL;
        }
        else
        {
            if ((*root)->left != NULL)
            {
                tree_node * new_root = (*root)->left;
                // Process the right child.
                if ((*root)->right == NULL)
                {
                    //new_root->parent = (*root)->parent;
                    (*root) = new_root;
                }
                else
                {
                    if (new_root->right == NULL)
                    {
                        new_root->right = (*root)->right;
                        // if ((*root)->right != NULL)
                        // {
                        //     (*root)->right->parent = new_root;
                        // }
                        *root = new_root;
                    } // We need to find the node which contains the least val now.
                    else
                    {
                        //new_root->right = (*root)->right;
                        tree_node * explorer_node = (*root)->right;
                        while (explorer_node->left != NULL)
                        {
                            explorer_node = explorer_node->left;
                        }
                        explorer_node->left = new_root->right;
                        //new_root->right->parent = explorer_node;
                        new_root->right = (*root)->right;
                        (*root) = new_root;
                    }
                }
            }
            else
            {
                (*root) = (*root)->right;
            }
        }
    }
    else
    {
        if ((*root)->val > value)
            delete_node(&((*root)->left), value);
        else
            delete_node(&(*root)->right, value);
    }
}


int main()
{
    tree_root * r = (tree_root *)malloc(sizeof(tree_root));
    int x;
    while (scanf("%d", &x) != -1)
    {
        tree_node * node = (tree_node *)malloc(sizeof(tree_node));
        node->val = x;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        //tree_node *t = new tree_node(x);
        if (r->root_node == NULL)
        {
            r->root_node = node;
        }
        else
        {
            insert(r->root_node, node);
        }
    }
    pre_order_tranverse(r->root_node);
    return 0;
}