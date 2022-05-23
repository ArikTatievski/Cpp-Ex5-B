#ifndef EX5_PARTA_NODE_H
#define EX5_PARTA_NODE_H

#endif //EX5_PARTA_NODE_H
#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace ariel{
    class Node{
    public:
        string value;
        Node* next;
        vector<Node*> children;
        bool visited;

        Node(string val){
            this->value = val;
            this->next = NULL;
            this->visited = false;
        }
        ~Node(){}

    };
}
