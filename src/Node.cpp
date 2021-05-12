#include "../inc/Node.h"

Node::Node(int k, long unsigned int v, int f) : key(k), value(v), freq(f), prev(nullptr), next(nullptr) {}
