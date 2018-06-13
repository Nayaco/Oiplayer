#include <cstdio>
using namespace std;

const int   MAXN = 6,
            MINN = 3,
            MAXK = MAXN -1,
            MINK = MINN -1;  

struct node{
    int kn;
    int keys[MAXK];
    node *child[MAXN];
    bool isleaf;
    bool isroot;
    node(bool leaf = true, bool root = false):isleaf(leaf),isroot(root){kn = 0;}
    ~node(){}
};

node *root;

void init(){
    root = new node(true, true);return;
}

void splice(node *n, node *ch, int index){
    node *rch = new node();
    rch->isleaf = ch->isleaf;
    rch->isroot = ch->isroot;
    rch->kn = MINK;
    for(int i = 0; i < MINK; i++){
        rch->keys[i] = ch->keys[MINK + 1 + i];
    }
    if(!rch->isleaf){
        for(int i = 0; i < MINN; i++){
            rch->child[i] = ch->child[MINK + 1 + i];
        }
    }
    ch->kn = MINK;

    for(int i = n->kn; i > index; i--){
        n->child[i + 1] = n->child[i];
        n->keys[i] = n->keys[i-1];
    }
    n->kn++;
    n->keys[index] = ch->keys[MINK];
    n->child[index + 1] = rch;
    return;
}

void merge(node *n, int index){
    node *lc = n->child[index];
    node *rc = n->child[index + 1];
    for(int i = 0; i < MINK; i++){
        lc->keys[i + MINK + 1] = rc->keys[i];
    }
    if(!rc->isleaf){
        for(int i = 0; i < MINN; i++){
            lc->child[i + MINN] = rc->child[i];
        }
    }
    lc->kn = MAXK;
    lc->keys[MINK] = n->keys[index];
    n->kn--;
    for(int i = index; i < n->kn; i++){
        n->keys[i] = n->keys[i + 1];
        n->child[i + 1] = n->child[i + 2];
    }
    delete rc;
}

void ins(node *n, int key){
    int index = n->kn;
    while(index > 0 && key < n->keys[index - 1])index--;
    
    if(n->isleaf){
        for(int i = n->kn; i > index; i--){
            n->keys[i] = n->keys[i-1];
        }
        n->keys[index] = key;
        n->kn++;
    }else{
        node *c = n->child[index];
        if(c->kn == MAXK){
            splice(n, c, index);
            if(key > n->keys[index])c = n->child[index + 1]; 
        }
        ins(c, key);
    }
    return;
}

int getpre(node *n){
    while(!n->isleaf){
        n = n->child[0];
    }
    return n->keys[0];
}
int getnext(node *n){
    while(!n->isleaf){
        n = n->child[n->kn];
    }
    return n->keys[n->kn - 1];
}


bool search(node *n, int key){
    int index = n->kn;
    while(index > 0 && key < n->keys[index - 1])index--;
    if(n->isleaf){
        if(n->keys[index] == key)return true;
            else return false;
    }else{
        if(n->keys[index] == key)return true;
            else return search(n->child[index], key);
    }
    return false;
}
void insert(int key){
    if(search(root, key))return;
    if(root->kn == MAXK){
        node *newroot = new node(false, true);
        newroot->child[0] = root;
        root->isroot = false;
        splice(newroot, root, 0);
        root = newroot;
    }
    ins(root, key);
    return;
}

void del(node *n, int key){
    int index = n->kn;
    while(index > 0 && key < n->keys[index - 1])index--;
    if(n->keys[index] == key && index < n->kn){
        if(n->isleaf){
            for(int i = index; i < n->kn - 1; i++){
                n->keys[i] = n->keys[i + 1];
                n->kn--;
                return;
            }
        }
        node *pre = n->child[index];
        node *next = n->child[index + 1];
        if(pre->kn > MINK){
            int prek = getnext(pre);
            del(pre, prek);
            n->keys[index] = prek;
        }else if(next->kn > MINK){
            int nextk = getpre(next);
            del(next, nextk);
            n->keys[index] = nextk;
        }else{
            merge(n, index);
            del(pre, key);
        }
    }else{
        node *c = n->child[index];
        if(c->kn == MINK){
            node *lc = index > 0? n->child[index - 1] : NULL; 
            node *rc = index < n->kn ? n->child[index + 1] : NULL; 
            if(lc && lc->kn > MINK){
                for(int i = c->kn; i > 0; i--)c->keys[i] = c->keys[i - 1];
                c->kn++;
                c->keys[0] = n->keys[index - 1];
                if(!c->isleaf){
                    for(int i = c->kn + 1; i > 0; i--)c->child[i] = c->child[i - 1];    
                    c->child[0] = lc->child[lc->kn];
                }
                n->keys[index - 1] = lc->keys[lc->kn - 1];
                lc->kn--;
            }else if(rc && rc->kn > MINK){
                c->keys[c->kn] = n->keys[index];
                c->kn++;
                n->keys[index] = rc->keys[0];
                for(int i = 0; i < rc->kn - 1; i++){
                    rc->keys[i] = rc->keys[i + 1];
                }
                if(!c->isleaf){
                    c->child[c->kn] = rc->child[0];
                    for(int i = 0; i < rc->kn; i++){
                        rc->child[i] = rc->child[i + 1];
                    }
                }
                rc->kn--;
            }else if(lc){
                merge(n, index - 1);
                c = n->child[index-1];
            }else if(rc){
                merge(n, index);
            }
        }
        del(c, key);
    }
    return;
}

void delkey(int key){
    if(search(root, key)){
        return;
    }
    del()
}

void show(node *){

}


int main(int argc, char const *argv[])
{
    
    return 0;
}

