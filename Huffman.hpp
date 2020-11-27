//
//  Huffman.hpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/26/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#ifndef Huffman_hpp
#define Huffman_hpp

#include <stdio.h>

class Node {
    friend class Huffman_BinaryHeap;
    int key;
    int freq;
    Node* left;
    Node* right;
public:
    Node();
    ~Node();
    
    inline void SetKey(int i) {this->key = i;}
    inline void SetFreq(int i) {this->freq = i;}
    inline void SetLeftChild(Node* n) {this->left = n;}
    inline void SetRightChild(Node* n) {this->right = n;}

    inline int Key() {return this->key;}
    inline int Freq() {return this->freq;}
    inline const Node* LeftChild() {return this->left;}
    inline const Node* RightChild() {return this->left;}
};

class Huffman_BinaryHeap {
    int length;
    int count;
    Node** internalNode;
public:
    Huffman_BinaryHeap(int len);
    ~Huffman_BinaryHeap();
    
    void BuildTree(Node** extNode);
};
#endif /* Huffman_hpp */
