class Solution {
public:

    int frequency(string s) {

        char smallest = *min_element(s.begin(), s.end());

        int count = 0;

        for (char c : s) {
            if (c == smallest)
                count++;
        }

        return count;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {

        vector<int> wordFreq;

        // Compute frequencies for words
        for (string& w : words) {
            wordFreq.push_back(frequency(w));
        }

        sort(wordFreq.begin(), wordFreq.end());

        vector<int> result;

        // Process queries
        for (string& q : queries) {

            int fq = frequency(q);

            // First element > fq
            int idx = upper_bound(wordFreq.begin(),
                                  wordFreq.end(),
                                  fq) - wordFreq.begin();

            result.push_back(wordFreq.size() - idx);
        }

        return result;
    }
};