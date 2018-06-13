#include <cstdio>
#define print(x) printf("\nres : %d\n",x)
using namespace std;
const int MAXN = 6;
const int MINN = 3;
const int MAXK = MAXN - 1;
const int MINK = MINN - 1; 

struct node{
    bool isleaf;
    bool isroot;
    int cn;
    int kn;
    node* child[MAXN];
    int key[MAXK];
    node(bool leaf = true, bool root = false):isroot(root),isleaf(leaf){
        this->kn = 0;
        this->cn = 0;
    }
    ~node(){};
};
node *root;

void init(){
    root = new node(true, true);
    root->cn = 0;
    return;
}

bool search(node *n, int key){
    if(n == NULL)return false;
    int i = n->kn;
    while(i > 0 && n->key[i] > key)i--;
    if(i >= 0 && i < n->kn && n->key[i] == key)return true;
    if(n->isleaf)return false;
    return search(n->child[i], key);
}

void splice(node *fa, node* ch, int index){
    //print(index);
    node *rch = new node();
    rch->isleaf = ch->isleaf;
    rch->isroot = ch->isroot;
    rch->kn = MINK;
    for(int i = 0; i < MINK; i++){
        rch->key[i] = ch->key[MINK + 1 + i];
    }
    if(!rch->isleaf){
        for(int i = 0; i < MINN; i++){
            rch->child[i] = ch->child[MINK + 1 + i];
        }
        rch->cn = MINN;
        ch->cn = MINN;
    }
    ch->kn = MINK;

    for(int i = fa->kn; i > index; i--){
        fa->child[i + 1] = fa->child[i];
        fa->key[i] = fa->key[i-1];
    }
    fa->kn++;
    fa->cn++;
    fa->key[index] = ch->key[MINK];
    fa->child[index + 1] = rch;
    return;
}

void ins(node *n, int key){
    int i = n->kn;
    while(key < n->key[i - 1] && i > 0)i--;
    if(n->isleaf){
        for(int j = n->kn; j > i; j--){
            n->key[j] = n->key[j - 1];
        }
        n->key[i] = key;
        n->kn++;
    }else{
        node *ch = n->child[i];
        if(ch->kn == MAXK){
            splice(n, ch, i);
            if(key>n->key[i]){
                ch = n->child[i + 1];
            }
        }
        ins(ch, key);
    }
    return;
}

bool insert(int key){
    if(search(root, key))return false;
    
    if(root->kn == MAXK){
        node *n = new node(false, true);
        n->child[0] = root;
        n->cn = 1;
        root->isroot = false;
        splice(n, root, 0);
        root = n;    
    }

    ins(root, key);
    return true;
}

void merge(node *fa, int index){
    node *lch = fa->child[index];
    node *rch = fa->child[index + 1];
    for(int i = 0; i < MINK; i++){
        lch->key[MINK + 1 + i] = rch->key[i];
    }
    if(!lch->isleaf){
        for(int i = 0; i < MINN; i++){
            lch->child[MINN + i] = rch->child[i];
        }   
    }
    fa->kn--;
    for(int i = index; i < fa->kn; i++){
        fa->key[i] = fa->key[i + 1];
        fa->child[i + 1] = fa->child[i + 2];
    }
    delete rch;
}

int getpkey(node* n){
    while(!n->isleaf){
        n = n->child[0];
    }
    return n->key[0];
}
int getnkey(node *n){
    while(!n->isleaf)n = n->child[n->cn-1];
    return n->key[n->kn - 1];
}

void del(node *n, int key){
    int index = n->kn;
    while(key < n->key[index] && index > 0)index--;
    if(n->key[index] == key && index < n->kn){
        if(n->isleaf){
            for(int i = index; i < n->kn - 1; i++){
                n->key[i] = n->key[i + 1];
            }
            n->kn--;
            return;
        }
        node *pre = n->child[index];
        node *next = n->child[index + 1];
        if(pre->kn > MINK){
            int prek = getpkey(pre);
            del(pre, prek);
            n->key[index] = prek;
        }else if(next->kn > MINK){
            int nextk = getnkey(next);
            del(next, nextk);
            n->key[index + 1] = nextk;
        }else{
            merge(n, index);
            del(pre, key);
        }
    }else{
        node *c = n->child[index];
        if(c->kn == MINK){
            node *lc = index > 0? n->child[index - 1] : NULL; 
            node *rc = index < n->kn ? n->child[index + 1] : NULL; 
            if(lc && lc->kn > MINK + 1){
                for(int i = c->kn; i > 0; i--){
                    c->key[i] = c->key[i - 1];
                }
                c->kn++;
                c->key[0] = n->key[index - 1];
                if(!lc->isleaf){
                    for(int i = c->cn; i > 0; i--){
                        c->child[i] = c->child[i - 1];
                    }
                    c->cn++;
                    c->child = 
                }
            }else if(rc && rc->kn > MINK + 1){

            }else if(lc){
                
            }else if(rc){
                
            }
        }
        del(c, key);
    } 
    return;
}

void show(node *n, int dep){
    printf("%d %d | ", dep, n->cn);
    for(int i = 0; i < n->kn; i++)printf("%d ", n->key[i] );
    printf("\n");
    if(n->isleaf)return;
    for(int i = 0; i < n->cn; i++){
        show(n->child[i], dep + 1);
    }
    return;
}

int num;
int main(int argc, char const *argv[])
{
    init();
    int key;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &key);
        insert(key);
        show(root, 0);
    }
    return 0;
}


