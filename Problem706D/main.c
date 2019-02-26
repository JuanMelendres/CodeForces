#include <stdio.h>
#include <stdlib.h>

struct tree {
  int k, x, cnt0, cnt1;
  struct tree *c0, *c1;
} *t;

void add(struct tree *t, int x) {
  if (t->k >= 0) {
    if ((x & 1 << t->k) == 0) {
      if (t->cnt0++ == 0) {
        t->c0 = malloc(sizeof(*t->c0));
        t->c0->cnt0 = t->c0->cnt1 = 0;
        t->c0->c0 = t->c0->c1 = NULL;
      }
      t->c0->k = t->k - 1;
      add(t->c0, x);
    } 
    else {
      if (t->cnt1++ == 0) {
        t->c1 = malloc(sizeof(*t->c1));
        t->c1->cnt0 = t->c1->cnt1 = 0;
        t->c1->c0 = t->c1->c1 = NULL;
      }
      t->c1->k = t->k - 1;
      add(t->c1, x);
    }
  } 
  else {
    t->x = x;
  }
}

void delete(struct tree *t, int x) {
  if (t->k >= 0) {
    if ((x & 1 << t->k) == 0) {
      delete(t->c0, x);
      if (--t->cnt0 == 0) {
        t->c0 = NULL;
      }
    } 
    else {
      delete(t->c1, x);
      if (--t->cnt1 == 0) {
        t->c1 = NULL;
      }
    }
  }
}

int find(struct tree *t, int x) {
  if (t->k >= 0) {
    if ((x & 1 << t->k) == 0 && t->c1 != NULL) {
      return find(t->c1, x);
    }
    if ((x & 1 << t->k) != 0 && t->c0 != NULL) {
      return find(t->c0, x);
    }
    return t->c0 != NULL ? find(t->c0, x) : find(t->c1, x);
  } 
  else {
    return t->x ^ x;
  }
}

int main() {
  static char s[14];
  int x, q;
  scanf("%d\n", &q);
  t = malloc(sizeof(*t));
  t->k = 30;
  t->cnt0 = t->cnt1 = 0;
  t->c0 = t->c1 = NULL;
  add(t, 0);
  t->x = 0;
  while (q-- > 0) {
    fgets(s, 14, stdin);
    x = atoi(s + 2);
    if (s[0] == '+') {
      add(t, x);
    }
    else if (s[0] == '-') {
      delete(t, x);
    }
    else {
      printf("%d\n", find(t, x));
    }
  }
  return 0;
}