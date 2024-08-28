/*

Prime Prime Numbers: A Simpler Explanation
Imagine you have a group of numbers.

Let's say we have the numbers from 3 to 10: 3, 4, 5, 6, 7, 8, 9, 10.

Find the special numbers in the group:

In this group, the special numbers are the ones that can only be divided by 1 and themselves. These are called prime numbers. In our example, the prime numbers are: 3, 5, and 7.

Count the special numbers:

We found 3 special numbers (3, 5, and 7).

Is the count a special number?

3 is a special number because it can only be divided by 1 and itself.

But, here's the tricky part:

Even though we found 3 special numbers, none of the original numbers (3, 4, 5, 6, 7, 8, 9, 10) is a "prime prime" number.

Why?

Because a "prime prime" number is a number where the count of prime numbers up to that number is also a prime number. In our example, the count was 3, which is a prime number, but none of the original numbers fit this rule.

Let's try another example:

Numbers from 4 to 12: 4, 5, 6, 7, 8, 9, 10, 11, 12.

Prime numbers in this group: 5, 7, 11
Count of prime numbers: 3 (which is a prime number)
Now, we need to check each number from 4 to 12 to see if it's a "prime prime" number.

We find that 6 and 7 are "prime prime" numbers because the count of prime numbers up to them is 3, which is a prime number.
So, a "prime prime" number is like a special number within a group of special numbers.

Does this explanation help? Let me know if you have any other questions.

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int arr[MAXN + 1];
int prime_count[MAXN + 1];
int prime_prime[MAXN + 1];

void sieve() {
    fill(arr, arr + MAXN + 1, 1);
    arr[0] = arr[1] = 0; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= MAXN; i++) {
        if (arr[i] == 1) {
            for (int j = i * i; j <= MAXN; j += i) {
                arr[j] = 0;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (arr[i] == 1) {
            cnt++;
        }
        prime_count[i] = cnt;
    }

    for (int i = 2; i <= MAXN; i++) {
        prime_prime[i] = (arr[prime_count[i]] == 1);
    }
}

int main() {
    sieve();
    
    int l, r;
    cout << "Enter the range (l r): ";
    cin >> l >> r;

    cout << "Prime Prime numbers in the range [" << l << " to " << r << "] are:" << endl;
    for (int i = l; i <= r; i++) {
        if (prime_prime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}


/*

Let's go through the complete explanation and visualization of the process step-by-step, ensuring everything is clear and correct.

Step-by-Step Explanation
Initialize Arrays:

arr: This array will mark the prime numbers up to MAXN.
prime_count: This array will store the count of prime numbers up to each index.
prime_prime: This array will mark "prime prime" numbers, where prime_prime[i] is 1 if i is a "prime prime" number and 0 otherwise.
Sieve of Eratosthenes:

Mark non-prime numbers in arr.
Sieve Process
Initial state:

cpp
Copy code
arr = [0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1] // up to 10
i = 2:

Mark multiples of 2 as non-prime:
cpp
Copy code
arr = [0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0] // 4, 6, 8, 10 marked as non-prime
i = 3:

Mark multiples of 3 as non-prime:
cpp
Copy code
arr = [0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0] // 9 marked as non-prime
i = 4:

Already marked as non-prime, skip.
Final state:

cpp
Copy code
arr = [0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0] // 2, 3, 5, 7 are prime
Calculate prime_count Array
Initial state:

cpp
Copy code
prime_count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] // up to 10
Iterate through arr and count primes:

i = 2: prime_count[2] = 1
i = 3: prime_count[3] = 2
i = 4: prime_count[4] = 2
i = 5: prime_count[5] = 3
i = 6: prime_count[6] = 3
i = 7: prime_count[7] = 4
i = 8: prime_count[8] = 4
i = 9: prime_count[9] = 4
i = 10: prime_count[10] = 4
Final state:

cpp
Copy code
prime_count = [0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4] // up to 10
Calculate prime_prime Array
Initial state:

cpp
Copy code
prime_prime = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] // up to 10
Check if prime_count[i] is a prime:

i = 2: prime_count[2] = 1, which is not prime. Thus, prime_prime[2] = 0.
i = 3: prime_count[3] = 2, which is prime. Thus, prime_prime[3] = 1.
i = 4: prime_count[4] = 2, which is prime. Thus, prime_prime[4] = 1.
i = 5: prime_count[5] = 3, which is prime. Thus, prime_prime[5] = 1.
i = 6: prime_count[6] = 3, which is prime. Thus, prime_prime[6] = 1.
i = 7: prime_count[7] = 4, which is not prime. Thus, prime_prime[7] = 0.
i = 8: prime_count[8] = 4, which is not prime. Thus, prime_prime[8] = 0.
i = 9: prime_count[9] = 4, which is not prime. Thus, prime_prime[9] = 0.
i = 10: prime_count[10] = 4, which is not prime. Thus, prime_prime[10] = 0.
Final state:

cpp
Copy code
prime_prime = [0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0] // up to 10
Result for Range 3 to 10
From the prime_prime array, we can see that the "prime prime" numbers between 3 and 10 are:

3
4
5
6

*/