using namespace std;
 
#include <string>
#include <vector>
#include <iostream>
#include <map>
 
struct Node {
    Node* left;
    Node* right;
    int freq = 0;
    char letter = '\0';
};
 
void dFS (Node* node, map<char, string> &m, string path) {
    if (node == nullptr){
        return;
    }
 
    if (node->letter != '\0'){
        m[node->letter] = path;
        return;
    }
 
    dFS(node->left, m , path + "0");
    dFS(node->right, m , path + "1");
}
 
 
Node* extractMin(vector<Node*> &Q) {
    Node *min = new Node ();
    int num = 2147483647;
    int pos = 0;
 
    for (int i = 0; i < Q.size(); i++) {
        if (Q[i]->freq < num) {
            min = Q[i];
            num = Q[i]->freq;
            pos = i;
        }
    }
 
    Q.erase(Q.begin() + pos);
    return min;     //Return node with the smallest frequency
}
 
Node* huffMan(vector<Node*> C) {
    int n = 6; //Size of C, 6 letters
    vector<Node*> Q = C;
 
    for (int i = 1; i <= n-1; i++) {
        Node *z = new Node();
        z->left = extractMin(Q);
        z->right = extractMin(Q);
        z->freq = z->left->freq + z->right->freq;
        z->letter = '\0';
        Q.push_back(z);
    }
    
    return extractMin(Q);; //return the root of the tree
}
 
int main () {
 
    vector<Node *> vector;
 
    for (int i = 0; i < 6; i++) {
        int freq;
        cin >> freq;
        Node *temp = new Node ();
        temp->freq = freq;
        temp->letter = (char)('A' + i);
        vector.push_back(temp);
       
    }
 
    map<char, string> m;
    m['A'] = "";
    m['B'] = "";
    m['C'] = "";
    m['D'] = "";
    m['E'] = "";
    m['F'] = "";
 
    dFS(huffMan(vector), m, "");  //Create the tree, and DFS to search path
 
    for (int i = 0; i < 6; i++) {
        cout << (char)('A' + i) << ":" << m[(char)('A' + i)] << endl;
    }
 
    return 0;
}
 
 
 
