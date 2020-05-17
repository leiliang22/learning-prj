class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        indeg.resize(numCourses);

        for (auto x : prerequisites) {
            edge[x[1]].push_back(x[0]);
            ++indeg[x[0]];
        }
        queue<int> q;
        for (int i=0; i<numCourses; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            res.push_back(tmp);
            for (auto x : edge[tmp]) {
                --indeg[x];
                if (indeg[x] == 0) q.push(x);
            }
        }

        if (res.size() != numCourses) return {};
        return res;
    }

private:
    vector<vector<int> > edge;
    vector<int> indeg;
    vector<int> res;
};
