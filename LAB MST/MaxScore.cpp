#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> cards = {200, 100};
    int energy = 150;

    sort(cards.begin(), cards.end());

    int score = 0;
    int best = 0;

    int left = 0;
    int right = cards.size() - 1;

    while (left <= right) {
        if (cards[left] <= energy) {
            energy = energy - cards[left];
            score++;
            best = max(best, score);
            left++;
        }
        else if (score > 0) {
            energy = energy + cards[right];
            score--;
            right--;
        }
        else {
            break;
        }
    }

    cout << best << endl;
}
