//
// Created by Aaron Kampmeier on 5/30/20.
// ASU ID: 1217750807
// For Codeforces 1352B
//

#include <iostream>
using namespace std;

/*
 * Problem: Add up k (all even or odd) integers to get n. If possible print "YES\n" + ints + "\n", else "NO\n".
 *
 * Impossible Cases
 * - Odd n with even k. (Odds can only be created by adding an odd number of ints together)
 * - k > n
 * -
 *
 * Examples:
 * - 5, 3 -> YES, 3 1 1
 * - 10, 3 -> 10/3 = 3.333
 * 3.333 % 2 =
 * - 8, 8 -> YES 1 1 1 1 1 1 1 1
 * - 10, 7 ->
 */

void answer(int, int*, int*, int*);

int main() {

    // Following tree outlined in flowchart

    int testSize = 0;
//    scanf("%d", &testSize);
    cin >> testSize;

    int inputs [testSize][2];

    for (int testC = 0; testC < testSize; testC++) {
        scanf(" %d %d", &(inputs[testC][0]), &(inputs[testC][1]));

    }

//    cout << "Input: " << endl;
//    for (int testC = 0; testC < testSize; testC++) {
//        cout << "Row " << testC << ": " << inputs[testC][0] << " " << inputs[testC][1] << endl;
//    }

//    cout << "\n\nOUTPUT: " << endl;
    int n;
    int k;
    int r;
    for (int t=0; t < testSize; t++) {
        n = inputs[t][0];
        k = inputs[t][1];

//        cout << "n: " << n << " k: " << k << endl;
        //Now follow the actual flowchart
        //1. Check k <= n
        if (k <= n) {
            if (n % 2 == 0) {
                if (2*k <= n) {
                    //Answer
                    answer(2, &r, &n, &k);
                } else {
                    //Must use odds
                    if (k % 2 == 0) {
                        //Answer
                        answer(1, &r, &n, &k);
                    } else {
                        //NO
                        cout << "NO" << endl;
                    }
                }
            } else {
                // Must use odds
                //Check k even
                if (k % 2 == 0) {
                    //NO
                    cout << "NO" << endl;
                } else {
                    //ANSWER
                    answer(1, &r, &n, &k);
                }
            }
        } else {
            // NO
            cout << "NO" << endl;
        }

    }

    return 0;
}

void answer(int parity, int* r, int* n, int* k) {
    *r = *n - (*k * parity);
    cout << "YES" << "\n";
    for (int i=0; i<*k-1; i++) {
        cout << parity << " ";
    }
    cout << to_string(parity + *r) << endl;
}