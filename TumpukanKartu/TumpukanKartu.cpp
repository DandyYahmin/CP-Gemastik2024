#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void updateIndexMap(const vector<long long>& cards, unordered_map<long long, size_t>& index_map, size_t start = 0) {
    if (start >= cards.size()) return;
    index_map[cards[start]] = start;
    updateIndexMap(cards, index_map, start + 1);
}

void processQueries(vector<long long>& cards, unordered_map<long long, size_t>& index_map, long long K, size_t queryIndex = 0) {
    if (queryIndex >= K) return;

    char o;
    long long n;
    cin >> o >> n;

    if (o == 'A') {
        cards.insert(cards.begin(), n);
        index_map[n] = 0;
        updateIndexMap(cards, index_map, 1);
    } else if (o == 'G') {
        auto it = index_map.find(n);
        if (it != index_map.end()) {
            size_t pos = it->second;

            vector<long long> temp(cards.begin() + pos, cards.end());
            cards.erase(cards.begin() + pos, cards.end());
            cards.insert(cards.begin(), temp.begin(), temp.end());

            updateIndexMap(cards, index_map);
        }
    }

    processQueries(cards, index_map, K, queryIndex + 1);
}

int main() {
    long long N, K;
    cin >> N >> K;

    vector<long long> cards(N);
    unordered_map<long long, size_t> index_map;

    for (size_t i = 0; i < N; ++i) {
        cin >> cards[i];
        index_map[cards[i]] = i;
    }

    processQueries(cards, index_map, K);

    cout << cards.size() << endl;   
    for (const long long& card : cards) {
        cout << card << ' ';
    }

    return 0;
}
