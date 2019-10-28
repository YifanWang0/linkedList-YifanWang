struct node { int i; struct node *next; };

void print_list(struct node *p);
struct node * insert_front(struct node *p, int);
struct node * free_list(struct node *p);
struct node * remove_node(struct node *front, int data);
