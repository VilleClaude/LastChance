#include <bits/stdc++.h>
using namespace std;

int main() {
    const string oath[5] = {
        "Uphold integrity and ethics throughout the contest.",
        "Do not seek or receive external help from people, platforms, tools or AI.",
        "Follow all ICPC rules and guidelines, accept decisions made by organizers and judges as final.",
        "Show good sportsmanship and treat competitors, volunteers, staff and judges with respect.",
        "Compete with creativity and teamwork, honor the contest spirit and pursue excellence."
    };
    int p;
    cin >> p;
    cout << oath[p - 1] << "\n";
    return 0;
}
