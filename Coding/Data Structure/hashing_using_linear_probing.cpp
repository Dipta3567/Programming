#include <iostream>
#define SIZE 8
using namespace std;

int HashTable[SIZE];
int cnt = 0;
int fn(int data)
{
    return data % SIZE;
}
bool linearProbing(int data, int idx)
{
    bool isPlaced = 0;
    for(int i = idx; i < SIZE; i++) {
        if(HashTable[i] == -1) {
            HashTable[i] = data;
            isPlaced = 1;
            break;
        }
        cnt++;
    }
    if(isPlaced == 0) {
        for(int i = 0; i < idx; i++) {
            if(HashTable[i] == -1) {
                HashTable[i] = data;
                isPlaced = 1;
                break;
            }
        }
        cnt++;
    }
    return isPlaced;
}
void insert(int data)
{
    int idx = fn(data);
    linearProbing(data, idx);
}

int search(int data) {
    int idx = fn(data);
    for(int i = idx; i < SIZE; i++) {
        if(HashTable[i] == -1) return -1;
        else if(HashTable[i] == data) return i;
    }
    for(int i = 0; i < idx; i++) {
        if(HashTable[i] == -1) return -1;
        else if(HashTable[i] == data) return i;
    }
    return -1;
}

void erase(int data) {
    int idx = search(data);
    if(idx != -1)
        HashTable[idx] = -1;
}

int main()
{
    for(int i = 0; i < SIZE; i++) {
        HashTable[i] = -1;
    }
    int arr[8] = {33, 21, 5, 13, 4, 1, 2, 13}, n = 8;
    for(int i = 0; i < n; i++) {
        insert(arr[i]);
    }
    
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", HashTable[i]);
    }
    printf("\nTotal Collision: %d\n", cnt);
    int item = 4;
    if(search(item) != -1) {
        printf("%d Found\n", item);
    } else {
        printf("%d Not Found.\n", item);
    }
    
    erase(item);
    
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", HashTable[i]);
    }
    return 0;
}