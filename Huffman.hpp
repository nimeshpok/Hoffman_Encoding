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

#include "Node.hpp"

class Node;
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
