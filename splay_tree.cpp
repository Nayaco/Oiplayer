#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 2147483647;
typedef struct SplayNode *Tree;
typedef int elementType;
struct SplayNode{
    Tree parent;
    elementType val;
    Tree lc;
    Tree rc;
    SplayNode(int val = 0){
        parent = NULL;
        lc = rc = NULL;
        this->val = val;
    }
};

Tree l_single_rotate(Tree &root, Tree node){
    if(node == NULL)return NULL;
    Tree parent = node->parent;
    Tree grandparent = parent->parent;
    parent->rc = node->lc;
    if(node->lc)node->lc->parent = parent;
    node->lc = parent;
    parent->parent = node;
    node->parent = grandparent;
    if(grandparent){
        if(grandparent->lc==parent){
            grandparent->lc = node;
        }else{
            grandparent->rc = node;
        }
    }else{
        root = node;
    }
    return node;
}

Tree r_single_rotate(Tree root, Tree node){
    if(node == NULL)return NULL;
    Tree parent = node->parent;
    Tree grandparent = parent->parent;
    parent->lc = node->rc;
    if(node->rc)node->rc->parent = parent;
    node->rc = parent;
    parent->parent = node;
    node->parent = grandparent;
    if(grandparent){
        if(grandparent->lc==parent){
            grandparent->lc = node;
        }else{
            grandparent->rc = node;
        }
    }else{
        root = node;
    }
}

void l_double_rotate(Tree &root, Tree node){
    l_single_rotate(root, node->parent);
    l_single_rotate(root, node);
}

void r_double_rotate(Tree &root, Tree node){
    r_single_rotate(root, node->parent);
    r_single_rotate(root, node);
}

void l_r_rotate(Tree &root, Tree node){
    l_single_rotate(root, node->parent);
    r_single_rotate(root, node);
}

void r_l_rotate(Tree &root, Tree node){
    r_single_rotate(root, node);
    l_single_rotate(root, node);
}


void up(Tree &root, Tree node){
    int parent = (node->parent->lc == node)?1:-1;
    int grandparent = (node->parent->parent->lc == node->parent)?1:-1;
    if(parent && grandparent){
        r_double_rotate(root, node);
    }else if(parent && !grandparent){
        r_l_rotate(root, node);
    }else if(!parent && grandparent){
        l_r_rotate(root, node);
    }else{
        r_double_rotate(root, node);
    }
    return;
}


void splay(Tree &root, Tree node){
    while(node!=root->lc&& node!= node){
        up(root ,node);
    }
    if(root->lc == node)r_single_rotate()
    //...
}

void insert(){
    temp = search()
    if(null){
        //add node
    }
}

Tree *findmin(Tree &root){
    //find lc or return root
}
void remove(root, val){
    temp = search_val(,val,)
    if(temp){
        if(!=root)splay(root, temp)
        if(root->lc){
            r = findmin(root->lc)
            //replace
            if((*r)->lc==null){
                r2 = r
                r = r->rc
                delete r2
            }
            else if(rc == null){
                ..
                r = r->lc
                delete .. 
            }
        }else{
            r2 = root
            r = r->lc
            delete r2
        }
    }
}
int search(Tree &root, elementType val){
    Tree parent = NULL;
    Tree *temp = NULL;
    temp = search_val(root, val, parent);
    if(*temp && *temp!=root){
        splay(root, *temp);
        return 1;
    }
    return 0;
}

Tree search_val(Tree &root, elementType val, Tree &parent){
    //...nothing new
}




