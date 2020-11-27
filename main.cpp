//
//  main.cpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/20/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "DataTable.hpp"
#include "Huffman.hpp"
#include "Encoder.hpp"

int main() {
    
    Encoder *encode = new Encoder();
    
    encode->ImportData();
    encode->GenerateCodeTable();
    encode->EncodeData();
    
    return 0;
}
