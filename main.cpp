//
//  main.cpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/20/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#include <iostream>

#include "DataTable.hpp"
#include "Huffman.hpp"

int main() {
    int size = 1000000;
    
    DataTable* freqTable = new DataTable(size);
    freqTable->GenerateFreqTable();
    
    int len = freqTable->GetLength();
    
    int* index = new int[len+1];
    int* value = new int[len+1];
        
    /* Sort the keys according to their frequency value */
    freqTable->SortTable(index, value);
    
    Node** n = new Node* [len];
    for (int i=0; i<len; i++) {
        n[i] = new Node();
        n[i]->SetKey(index[i]);
        n[i]->SetFreq(value[i]);

        printf("Key: %i, Freq: %i\n", n[i]->Key(), n[i]->Freq());
    }
    
    delete[] index; delete[] value;
    
    Huffman_BinaryHeap *huffmanBH = new Huffman_BinaryHeap(len-1);
    huffmanBH->BuildTree(n);
    
    for (int i=0; i<len; i++) delete n[i];
    delete[] n;

    return 0;
}
