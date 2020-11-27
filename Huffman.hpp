//
//  Huffman.hpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/25/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#ifndef Huffman_hpp
#define Huffman_hpp

#include <iostream>
#include <string>

#include <stdio.h>

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

class Huffman_BinaryHeap {
    int length;
    int count;
    
    Node* root;
    Node** internalNode;
public:
    Huffman_BinaryHeap(int len);
    ~Huffman_BinaryHeap();
    
    inline Node* Root() {return this->root;};
    inline const Node* GetNode(int i) {return this->internalNode[i];}
    
    void HuffmanTree(Node** extNode);
    int HuffmanCode(Node* current, Node* target, std::string code);
};
#endif /* Huffman_hpp */
