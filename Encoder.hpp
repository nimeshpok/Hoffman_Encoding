//
//  Encoder.hpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/25/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#ifndef Encoder_hpp
#define Encoder_hpp

#include <stdio.h>

#include "DataTable.hpp"
#include "Huffman.hpp"

class Encoder {
    int dataLength;
    DataTable* freqTable;
    Node** leafNode;
    
    Huffman_BinaryHeap* huffmanBH;
public:
    Encoder();
    ~Encoder();
    
    void ImportData();
    void CreateDataTree();
    
    void GenerateCodeTable();
    void EncodeData();
};

#endif /* Encoder_hpp */
