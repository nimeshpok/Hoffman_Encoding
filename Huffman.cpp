//
//  Huffman.cpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/25/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#include "Huffman.hpp"

Huffman_BinaryHeap::Huffman_BinaryHeap(int len) {
    length = len;
    count = 0;
    internalNode = NULL;
}

Huffman_BinaryHeap::~Huffman_BinaryHeap() {
    if (internalNode != NULL) {
        for (int i=0; i<length; i++) delete internalNode[i];
        delete[] internalNode;
    }
}

void Huffman_BinaryHeap::HuffmanTree(Node** extNode) {
    internalNode = new Node* [length];
    for (int i=0; i<length; i++) internalNode[i] = new Node();

    int i=0, j=0;
    while (i<=length) {
        if (i==0) {
            internalNode[j]->left = extNode[i];
            internalNode[j]->right = extNode[i+1];
            
            internalNode[j]->freq = extNode[i]->Freq() + extNode[i+1]->Freq();
            i = i+2;
        }
        else {
            int nodeFreq = 0;
            for (int k=0; k<2; k++) {
                Node* selNode = NULL;
                if (i <= length && extNode[i]->Freq() <= internalNode[count]->Freq()) selNode = extNode[i++];
                else selNode = internalNode[count++];
                
                if (k==0) internalNode[j]->left = selNode;
                else internalNode[j]->right = selNode;
                nodeFreq = nodeFreq + selNode->Freq();
            }
            internalNode[j]->freq = nodeFreq;
        }
        j++;
    }
    internalNode[j]->left = internalNode[count++];
    internalNode[j]->right = internalNode[count++];
    internalNode[j]->freq = internalNode[j]->left->freq + internalNode[j]->right->freq;
    
    root = internalNode[j];
}

int Huffman_BinaryHeap::HuffmanCode(Node* current, Node* target, std::string code) {
    
    current->HuffmanCode = new char[code.length()+1];
    std::size_t length = code.copy(current->HuffmanCode, code.length(), 0);
    current->HuffmanCode[length]='\0';

    if (current == target) return 1;

    if (current->LeftChild() == NULL && current->RightChild() == NULL) return -1;

    int left = HuffmanCode(current->LeftChild(), target, code + "0");
    int right = HuffmanCode(current->RightChild(), target, code + "1");

    if (left == -1) {
        code = code + "1";
        return 1;
    }
    else {
        code = code + "0";
        return 1;
    }
}


