#include <iostream>
#include <set>
#include <map>
#include <queue>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


class LockingTree {
public:

    LockingTree(vector<int> &parent) :
            parent(std::move(parent)),
            locks_ct(this->parent.size(), 0),
            user_lock(this->parent.size(), -1),
            desc(this->parent.size(), vector<int>(0, 0)) {
        for (int i = 1; i < this->parent.size(); i++) {
            desc[this->parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (user_lock[num] != -1)
            return false;
        user_lock[num] = user;
        while (num != -1) {
            locks_ct[num] += 1;
            num = parent[num];
        }
        return true;
    }

    bool unlock(int num, int user) {
        if (user_lock[num] != user)
            return false;
        user_lock[num] = -1;
        while (num != -1) {
            locks_ct[num] -= 1;
            num = parent[num];
        }
        return true;
    }

    bool upgrade(int num, int user) {
        if (user_lock[num] != -1 || locks_ct[num] == 0)
            return false;
        int num2 = num;
        while (num2 != -1) {
            if (user_lock[num2] != -1)
                return false;
            num2 = parent[num2];
        }
        //upgrade op (need descendants)
        user_lock[num] = user;
        int rm_ct = -1; //-1 b/c we lock the current node

        queue<int> q;
        for (int d: desc[num])
            q.push(d);
        while (!q.empty()) {
            int curr = q.front();
            rm_ct += user_lock[curr] != -1 ? 1 : 0;
            q.pop();
            user_lock[curr] = -1;
            locks_ct[curr] = 0;
            for (int d: desc[curr]) {
                q.push(d);
            }
        }
        num2 = num;
        while (num2 != -1) {
            locks_ct[num2] -= rm_ct;
            num2 = parent[num2];
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> locks_ct;
    vector<int> user_lock;
    vector<vector<int>> desc;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
int main() {
    vector<int> parent = {-1, 0, 3, 1, 0};  // Tree structure
    LockingTree* obj = new LockingTree(parent);

    // Perform operations according to the given sequence
    cout << (obj->upgrade(4, 5) ? "True" : "False") << endl;  // Attempt to upgrade node 4 by user 5
    cout << (obj->upgrade(3, 8) ? "True" : "False") << endl;  // Attempt to upgrade node 3 by user 8
    cout << (obj->unlock(0, 7) ? "True" : "False") << endl;  // Attempt to unlock node 0 by user 7
    cout << (obj->lock(2, 7) ? "True" : "False") << endl;    // Attempt to lock node 2 by user 7
    cout << (obj->upgrade(4, 6) ? "True" : "False") << endl;  // Attempt to upgrade node 4 by user 6

    delete obj;  // Clean up the created LockingTree object
    return 0;
}