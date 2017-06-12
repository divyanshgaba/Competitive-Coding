#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int binaryInsert(int[], int, long);

int main() {

    int cases;
    cin >> cases;

    for (int case_no = 0; case_no < cases; case_no++) {

        int num_of_snakes, queries;
        cin >> num_of_snakes >> queries;

        int lengths[num_of_snakes];
        int *ptr;
        ptr = lengths;

        for (int snake = 0; snake < num_of_snakes; snake++) {
            cin >> lengths[snake];
        }

        sort(lengths, lengths + sizeof(lengths)/sizeof(lengths[0]));

        for (int query = 0; query < queries; query++) {
            long min_length, max_snakes_possible = 0;
            cin >> min_length;
            int index = binaryInsert(ptr, num_of_snakes, min_length);
//            cout << index;
            int snakesLeft = index;
            max_snakes_possible += num_of_snakes - index;

            while ((min_length - lengths[index - 1]) <= snakesLeft - 1) {
                max_snakes_possible++;
                snakesLeft -= (min_length - lengths[index - 1]) + 1;
                index--;
            }

            cout << max_snakes_possible << endl;

        }

    }

    return 0;

}

int binaryInsert(int *arr, int length, long num) {

    int index = length / 2;

    if (length == 0) return 0;

    else if (arr[index-1] < num && arr[index] >= num) return index;

    else if (arr[index] < num) {
        return index + 1 + binaryInsert(&arr[length/2 + 1], length - (length/2) - 1, num);
    }

    else if (arr[index] >= num) {
        return binaryInsert(&arr[0], length/2, num);
    }

}
