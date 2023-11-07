#include <iostream>
#include <vector>
#include <limits>

class ZeroOneKnapsack {
public:
    void solve(std::vector<int>& wt, std::vector<int>& val, int W, int N) {
        int NEGATIVE_INFINITY = std::numeric_limits<int>::min();
        std::vector<std::vector<int>> m(N + 1, std::vector<int>(W + 1, 0));
        std::vector<std::vector<int>> sol(N + 1, std::vector<int>(W + 1, 0));

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= W; j++) {
                int m1 = m[i - 1][j];
                int m2 = NEGATIVE_INFINITY;
                if (j >= wt[i])
                    m2 = m[i - 1][j - wt[i]] + val[i];
                m[i][j] = std::max(m1, m2);
                sol[i][j] = (m2 > m1) ? 1 : 0;
            }
        }

        std::vector<int> selected(N + 1, 0);
        for (int n = N, w = W; n > 0; n--) {
            if (sol[n][w] != 0) {
                selected[n] = 1;
                w = w - wt[n];
            } else {
                selected[n] = 0;
            }
        }

        std::cout << "\nItems with weight ";
        for (int i = 1; i < N + 1; i++) {
            if (selected[i] == 1) {
                std::cout << val[i] << " ";
            }
        }
        std::cout << "are selected by knapsack algorithm." << std::endl;
    }
};

int main() {
    ZeroOneKnapsack ks;
    std::cout << "Enter number of elements: ";
    int n;
    std::cin >> n;

    std::vector<int> wt(n + 1);
    std::vector<int> val(n + 1);

    std::cout << "Enter weight for " << n << " elements" << std::endl;
    for (int i = 1; i <= n; i++)
        std::cin >> wt[i];

    std::cout << "Enter value for " << n << " elements" << std::endl;
    for (int i = 1; i <= n; i++)
        std::cin >> val[i];

    std::cout << "Enter knapsack weight: ";
    int W;
    std::cin >> W;

    ks.solve(wt, val, W, n);

    return 0;
}
