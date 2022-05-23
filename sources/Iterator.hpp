#ifndef EX5A_ITERATOR_H
#define EX5A_ITERATOR_H

#endif //EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Node.hpp"

namespace ariel{
    class Iterator{
    public:
        Node* data;

        Iterator(Node* root){
            this->data = root;
        }
        ~Iterator(){

        }

        string* operator->() const {
            return &(data->value);
        }

        string& operator*() const {
            return data->value;
        }

        Node* operator&() const {
            return data;
        }

        bool operator==(const Iterator& other) const {
            return data == other.data;
        }

        bool operator!=(const Iterator& other) const {
            return data != other.data;
        }
        Iterator& operator++() {
            data = data->next;
            return *this;
        }

        const Iterator operator++(int) {
            Iterator tmp= *this;
            data = data->next;
            return tmp;
        }
    };
}
