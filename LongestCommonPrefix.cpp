#include <iostream>
#include <vector>
#include <string>
using namespace std;

void LoCoPre(vector<string>& strs) {
        if (strs.empty()) {
        cout << "There is no common prefix among the input strings." << endl;
        return;
    }
    string prefix = "";
    for (int i = 0; i < strs[0].size(); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != c) {
                if (!prefix.empty()) {
                    cout << "Longest common prefix: " << prefix << endl;
                }
                else {
                    cout << "There is no common prefix among the input strings." << endl;
                }
                return;
            }
        }
        prefix += c;
    }
    cout << "Longest common prefix: " << prefix << endl;
}

int main() {

    vector<string> strs = { "flower", "flow", "flight" };
    LoCoPre(strs);

    vector<string> strs2 = { "dog", "racecar", "car" };
    LoCoPre(strs2);

    vector<string> strs3 = { "can", "canli", "caner" };
    LoCoPre(strs3);

    vector<string> strs4 = { };
    LoCoPre(strs4);

    return 0;

}
