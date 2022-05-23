#include <iostream>
#include <queue>
#include <stack>
#include "OrgChart.hpp"

using namespace std;

namespace ariel{

    OrgChart::OrgChart(){
        this->root = NULL;
        this->curr = NULL;
        this->start = new Iterator(root);
        this->over = new Iterator(root);
    }
    OrgChart::OrgChart(const OrgChart &other){
        for (unsigned int i = 0; i < other.allNodes.size(); ++i) {
            this->allNodes.push_back(new Node(other.allNodes.at(i)->value));
        }
        if(other.root == NULL){
            this->root = NULL;
        }
        else{
            this->root = this->allNodes.at(0);
        }
        this->curr = NULL;
        this->start = new Iterator(root);
        this->over = new Iterator(root);
    }

    OrgChart::~OrgChart() {
        for (int i = (int)allNodes.size() - 1; i >= 0; --i) {
            delete allNodes.at((unsigned int)i);
        }
        delete over;
        delete start;
    }

//    OrgChart& OrgChart::operator=(const OrgChart& other){
//        this->root = other.root;
//        this->allNodes = other.allNodes;
//        this->curr = other.root;
//        this->start = other.start;
//        this->over = other.over;
//        return *this;
//    }

    OrgChart& OrgChart::add_root(const string& curr) {
        if(this->root == NULL){
            this->root = new Node(curr);
            this->allNodes.push_back(this->root);
        }
        else{
            this->root->value = curr;
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub(const string& curr, const string& child) {
        Node* addTo = NULL;
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            if(this->allNodes.at(i)->value == curr){
                addTo = this->allNodes.at(i);
                break;
            }
        }
        if(addTo == NULL){
            throw invalid_argument("Parent is not in the organization\n");
        }
        Node* newChild = new Node(child);
        addTo->children.push_back(newChild);
        this->allNodes.push_back(newChild);
        return *this;
    }

    ostream& operator<<(ostream &out, const OrgChart &Orgchart) {
        return out;
    }

    Iterator OrgChart::begin_preorder(){
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        this->DFS();
        return *this->start;
    }

    Iterator OrgChart::begin_level_order(){
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        this->BFS();
        return *this->start;
    }

    Iterator OrgChart::begin_reverse_order(){
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        this->revBFS();
        return *this->start;
    }

    Iterator OrgChart::end_preorder() const{
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        return NULL;}
    Iterator OrgChart::end_level_order() const{
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        return NULL;}
    Iterator OrgChart::reverse_order() const{
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        return NULL;}

    Iterator OrgChart::begin(){
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        this->BFS();
        return *this->start;
    }
    Iterator OrgChart::end() const{
        if(root == NULL){
            throw("Chart is empty!\n");
        }
        return NULL;}

    void OrgChart::BFS() {
        this->start->data = root;
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i)->visited = false;
        }
        queue<Node*> q;
        this->root->visited = true;
        q.push(this->root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->children.empty() && q.empty()){
                curr->next = NULL;
                this->over->data= curr;
            }
            else if(q.empty()){
                curr->next = curr->children.at(0);
            }
            else{curr->next = q.front();}
            for (unsigned int i = 0; i < curr->children.size(); ++i){
                if (!curr->children.at(i)->visited){
                    curr->children.at(i)->visited = true;
                    q.push(curr->children.at(i));
                }
            }
        }
    }
    void OrgChart::revBFS() {
        vector<Node*> nextFix;
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i)->visited = false;
        }
        queue<Node*> q;
        this->root->visited = true;
        q.push(this->root);
        while(!q.empty()){
            Node* curr = q.front();
            nextFix.push_back(curr);
            q.pop();
            for (int i =(int) curr->children.size()-1; i >= 0 ; --i){
                if (!curr->children.at((unsigned int)i)->visited){
                    curr->children.at((unsigned int)i)->visited = true;
                    q.push(curr->children.at((unsigned int)i));
                }
            }
        }
        for (int i =(int) nextFix.size() - 1; i >= 0; --i) {
            if(i!=0){
                nextFix.at((unsigned int) i)->next = nextFix.at((unsigned int) i-1);
            }
            else{
                nextFix.at(0)->next = NULL;
            }
        }
        this->start->data = nextFix.at(nextFix.size()-1);
    }
    void OrgChart::DFS() {
        this->start->data = root;
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i)->visited = false;
        }
        stack<Node*> stack;
        stack.push(this->root);
        while (!stack.empty()){
            Node* curr = stack.top();
            stack.pop();
            if(curr->children.empty() && stack.empty()){
                curr->next = NULL;
                this->over->data = curr;
            }
            else if(curr->children.empty()){
                curr->next = stack.top();
            }
            else{
                curr->next = curr->children.at(0);
            }
            for (int i =(int) curr->children.size() - 1; i >= 0; --i){
                if (!curr->children.at((unsigned) i)->visited){
                    curr->children.at((unsigned) i)->visited = true;
                    stack.push(curr->children.at((unsigned) i));
                }
            }
        }
    }
}