#ifndef EX5_PARTA_ORGCHART_H
#define EX5_PARTA_ORGCHART_H

#endif //EX5_PARTA_ORGCHART_H
#pragma once
#include <iostream>
#include <vector>
#include "Node.hpp"
#include "Iterator.hpp"

using namespace std;


namespace ariel {

    class OrgChart {
    public:
        Iterator* start;
        Iterator* over;
        Node* root;
        Node* curr;
        vector<Node*> allNodes;
        OrgChart();
        OrgChart(const OrgChart &other);

        ~OrgChart();

//        OrgChart& operator=(const OrgChart& other);

        OrgChart& add_root(const string& curr);

        OrgChart& add_sub(const string& curr, const string& child);

        friend ostream& operator<<(ostream &out, const OrgChart &Orgchart);

        Iterator begin_preorder();
        Iterator begin_level_order();
        Iterator begin_reverse_order();
        Iterator end_preorder() const;
        Iterator end_level_order() const;
        Iterator reverse_order() const;
        Iterator begin();
        Iterator end() const;

        void BFS();
        void revBFS();
        void DFS();
    };
}