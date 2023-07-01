#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Player {
  int age;
  int score;
  Player(int age, int score) : age(age), score(score) {}
};

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
  const int n = scores.size();
  vector<Player> players;
  // dp[i] := max score of choosing players[0..i] w/ players[i] being selected
  vector<int> dp(n);

  for (int i = 0; i < n; ++i)
    players.emplace_back(ages[i], scores[i]);

  sort(begin(players), end(players), [](const auto& a, const auto& b) {
    return a.age == b.age ? a.score > b.score : a.age > b.age;
  });

  for (int i = 0; i < n; ++i) {
    // For each player, we choose it first
    dp[i] = players[i].score;
    // players[j].age >= players[i].age since we sort in descending order
    // So we only have to check that
    // players[j].score >= players[i].score
    for (int j = 0; j < i; ++j)
      if (players[j].score >= players[i].score)
        dp[i] = max(dp[i], dp[j] + players[i].score);
  }

  return *max_element(begin(dp), end(dp));
}

int main() {
  vector<int> scores = {4,5,4,5};
  vector<int> ages = {2,1,2,1};
  cout << bestTeamScore(scores, ages) << endl;
  return 0;
}







