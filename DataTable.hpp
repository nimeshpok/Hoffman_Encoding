//
//  DataTable.hpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/22/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#ifndef DataTable_hpp
#define DataTable_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

class DataTable {
    int DEFAULT_SIZE = 100;
    int size;
    int length;
    int* data;
    int* code;

public:
    DataTable();
    DataTable(int s);
    ~DataTable();
    
    inline int GetSize() const {return this->size;}
    inline int GetLength() const {return this->length;}

    inline void Insert(int key) {
        if (data[key] == 0) length++;
        data[key]++;
    }
    inline int Retrieve(int key) const {return data[key];}
    
    void GenerateFreqTable();
    void SortTable(int* index, int* value) const;
    int Partition(int* index, int* value, int low, int high) const;
    void SortData(int* index, int* value, int low, int high) const;    
};

/* ************************************************* DATA VALUE CLASS FOR STORAGE ************************************************* */

class DataValue : public DataTable {
    int key;
    int value;
    int length;
    int i;
public:
    DataValue();
    ~DataValue();
    
    int CheckOpenSlot(int i);
    int Insert(int index);
    void HashInsert(int index);
    void HashMapKey(int index);
};

#endif /* DataTable_hpp */
