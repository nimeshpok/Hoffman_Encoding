//
//  Encoder.cpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/25/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#include "Encoder.hpp"

Encoder::Encoder() {
    dataLength = 0;
    freqTable = NULL;
    leafNode = NULL;
    huffmanBH = NULL;
}

Encoder::~Encoder() {
    if (freqTable != NULL) delete freqTable;
    if (leafNode != NULL) {
        for (int i=0; i<dataLength; i++) delete leafNode[i];
        delete[] leafNode;
    }
    if (huffmanBH != NULL) delete huffmanBH;
}

void DataTable::GenerateFreqTable() {
    std::ifstream fh;
    fh.open("/Users/nimesh/Documents/Classes/FALL20/Project/sample_input_small.txt");
    //fh.open("/Users/nimesh/Documents/Classes/FALL20/Project/input.txt");
    while (fh.is_open() && !fh.eof()) {
        int key;
        fh >> key;
        this->Insert(key);
    }
    fh.close();
}

void Encoder::ImportData() {
    int size = 1000000;
    
    freqTable = new DataTable(size);
    freqTable->GenerateFreqTable();
    
    dataLength = freqTable->GetLength();
    CreateDataTree();
}

void Encoder::CreateDataTree() {
    int debug = 0;
    if (debug) {
        for (int i=0; i<freqTable->GetSize(); i++) {
            if (freqTable->Retrieve(i) == 0) continue;
            printf("Num: %i, Freq: %i\n", i, freqTable->Retrieve(i));
        }
        printf("\n");
    }
        
    int* index = new int[dataLength+1];
    int* value = new int[dataLength+1];
        
    freqTable->SortTable(index, value);
    
    leafNode = new Node* [dataLength];
    for (int i=0; i<dataLength; i++) {
        leafNode[i] = new Node();
        leafNode[i]->SetKey(index[i]);
        leafNode[i]->SetFreq(value[i]);

        if (debug) printf("Key: %i, Freq: %i\n", leafNode[i]->Key(), leafNode[i]->Freq());
    }
    
    delete[] index; delete[] value;
    delete freqTable;
}

void Encoder::GenerateCodeTable() {
    huffmanBH = new Huffman_BinaryHeap(dataLength-1);
    
    huffmanBH->HuffmanTree(leafNode);
    huffmanBH->HuffmanCode(huffmanBH->Root(), leafNode[0], "");
    
    int debug = 0;
    if (debug) {
        printf("Root: %i\n", huffmanBH->Root()->Freq());
        printf("Root: %i\n", huffmanBH->Root()->LeftChild()->Freq());
    }
    
    std::ofstream fh;
    
    fh.open ("/Users/nimesh/Documents/Classes/FALL20/Project/NimeshPok_Project1/code_table.txt");
    for (int i=0; i<dataLength; i++) fh << leafNode[i]->Key() << " " << leafNode[i]->Code() << std::endl;
    fh.close();
}

void Encoder::EncodeData() {
    
}


