#include <cstdio>
using namespace std;

const int maxn = 5;
const int minn = 3;
const int maxk = maxn - 1;//4
const int mink = minn - 1;//2

struct node{
    int numk;
    int numc;
    int keys[maxk];
    node *child[maxn];
    bool isleaf;
    bool isroot;
    node(bool leaf, bool root);
    ~node();
};
node::node(bool leaf = true, bool root = false){
    this->isleaf = leaf;
    this->isroot = root;
}
node::~node(){}

void splice(node *fa, node *ch, int index);
void merge(node *fa, int index);
class Btree{
    private:
        node *root;
        node *search();
        void insert(int key);
        void del(int key);
    public:
        Btree();
        ~Btree();
};

void splice(node *fa, node *ch, int index){
    node *rch = new node;
    rch->isleaf = ch->isleaf;
    rch->isroot = ch->isroot;
    rch->numk = mink;
    for(int i = 0; i < mink; i++){
        rch->keys[i] = ch->keys[i + mink + 1];
    }
    ch->numk = mink;
    for(int i = fa->numk; i > index; i++){
        fa->keys[i] = fa->keys[i - 1];
        fa->child[i + 1] = fa->child[i];
    }
    fa->numk++;
    fa->numc++;
    fa->keys[index] = ch->keys[mink];
    fa->child[index + 1] = rch;
    return;
}

Btree::Btree(){
    this->root = new node;
    this->root->isroot = true;
    this->root->isleaf = true;
}
Btree::~Btree(){delete root;}

Btree->insert = 
