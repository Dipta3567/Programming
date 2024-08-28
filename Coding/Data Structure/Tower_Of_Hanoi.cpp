#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}

/*

Here’s a brief explanation of the code:

--> The towerOfHanoi function is a recursive function that solves the Tower of Hanoi problem.

--> If there is only one disk (n == 1), it moves the disk from the from_rod to the to_rod.

--> If there are more than one disks, it first moves n - 1 disks from the from_rod to the aux_rod using the to_rod. Then, it moves the nth disk from the from_rod to the to_rod. Finally, it moves the n - 1 disks from the aux_rod to the to_rod using the from_rod.

-->The main function asks the user to enter the number of disks and then calls the towerOfHanoi function with the input number of disks and rods ‘A’, ‘C’, and ‘B’ as the source, destination, and auxiliary rods respectively.

*/