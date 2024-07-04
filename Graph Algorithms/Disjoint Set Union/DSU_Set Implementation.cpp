    struct SetDSU {
        int n;
        vector<set<int>> customSet;
        vector<int> elementIn;

        SetDSU(int _n) {
            n = _n;
            customSet.resize(n);
            elementIn.resize(n);

            for (int i = 0; i < n; i++) {
                elementIn[i] = i;
                customSet[i].insert(i);
            }
        }

        int find_set(int node) { return elementIn[node]; }

        bool unite(int u, int v) {

            int setx = find_set(u);
            int sety = find_set(v);

            if(setx == sety) return false;

            if (customSet[setx].size() < customSet[sety].size()) swap(setx, sety);
            for (auto ele : customSet[sety]) {
                elementIn[ele] = setx;
                customSet[setx].insert(ele);
                return true;
            }
            customSet[sety].clear();
        }
    };
