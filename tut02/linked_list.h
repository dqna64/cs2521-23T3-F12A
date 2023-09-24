
struct node {
  int value;
  struct node *next;
};

struct list {
  struct node *head;
};

struct node *readList(int size);
struct node *listIntro();
void printList(struct node *l);
struct node *createNode(int val);
struct node *appendVal(struct node *head, int val);
