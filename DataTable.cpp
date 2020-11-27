//
//  DataTable.cpp
//  NimeshPok_Project1
//
//  Created by Nimesh Pokhrel on 11/22/20.
//  Copyright © 2020 Nimesh Pokhrel. All rights reserved.
//

#include "DataTable.hpp"

DataTable::DataTable() {
    size = DEFAULT_SIZE;
    data = new int [size];
    for (int i=0; i<size; i++) data[i] = 0;
    length = 0;
}

DataTable::DataTable(int s) {
    size = s;
    data = new int [size];
    for (int i=0; i<size; i++) data[i] = 0;
    length = 0;
}

DataTable::~DataTable() {
    delete[] data;
};

void DataTable::SortTable(int* index, int* value) const {
    int count = 0;
    
    for (int i=0; i<size; i++) {
        if (data[i] == 0) continue;
        index[count] = i;
        value[count] = data[i];
        count++;
    }
    value[count] = 1e10;
    SortData(index, value, 0, count);
}

void DataTable::SortData(int* index, int* value, int low, int high) const {
    if (low<high) {
        int x = Partition(index, value, low, high);
        SortData(index, value, low, x);
        SortData(index, value, x+1, high);
    }
}

int DataTable::Partition(int* index, int* value, int low, int high) const {
    int pivot = value[low];
    int i=low, j=high;
    
    while (j>i) {
        do i++;
        while (value[i] <= pivot);
        do j--;
        while (value[j] > pivot);
        
        if (j>i) {
            int temp = value[i];
            value[i] = value[j];
            value[j] = temp;
            
            int tempInd = index[i];
            index[i] = index[j];
            index[j] = tempInd;
        }
    }
    int temp = value[low];
    value[low] = value[j];
    value[j] = temp;
    
    int tempInd = index[low];
    index[low] = index[j];
    index[j] = tempInd;

    return j;
}

DataValue::DataValue() {
    key = 0;
    value = 0;
}


