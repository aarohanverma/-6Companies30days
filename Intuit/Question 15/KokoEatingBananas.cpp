class Solution {
private:
    int evaluateCeils(std::vector<int>& piles, int& x) {
        int answer = 0;
        for (auto &i : piles) answer += ceil((double)i/x);
        return answer;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *std::max_element(piles.begin(), piles.end()), answer = end, answerCeiled = evaluateCeils(piles, answer);
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int potentialAnswer = evaluateCeils(piles, mid);
            if (potentialAnswer < h) {
                if (answerCeiled <= potentialAnswer) {
                    answer = mid;
                    answerCeiled = potentialAnswer;
                }
                end = mid - 1;
            }
            else if (h < potentialAnswer)  start = mid + 1;
            else {
                answer = mid;
                end = mid - 1;
            }
        }
        return answer;
    }
};
