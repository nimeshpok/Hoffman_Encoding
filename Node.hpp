//
//  Node.hpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/25/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Huffman.hpp"

class Node {
    friend class Huffman_BinaryHeap;
    int key;
    int freq;
    char* HuffmanCode;
    Node* left;
    Node* right;
public:
    Node();
    ~Node();
    
    inline void SetKey(int i) {this->key = i;}
    inline void SetFreq(int i) {this->freq = i;}
    inline void SetLeftChild(Node* n) {this->left = n;}
    inline void SetRightChild(Node* n) {this->right = n;}

    inline int Key() const {return this->key;}
    inline int Freq() const {return this->freq;}
    inline char* Code() const {return this->HuffmanCode;}
    inline Node* LeftChild() const {return this->left;}
    inline Node* RightChild() const {return this->right;}
};

#endif /* Node_hpp */
