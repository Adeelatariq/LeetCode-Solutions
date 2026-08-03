#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // 1. Build Adjacency List & Indegree Array
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDegree(numCourses, 0);

        for (const auto& req : prerequisites) {
            int course = req[0];
            int prereq = req[1];
            
            // Directed edge: prereq -> course
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        // 2. Queue for nodes with 0 incoming prerequisites
        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. Process courses
        int completedCourses = 0;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            completedCourses++;

            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                // If all prerequisites for neighbor are completed
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. If we were able to process all courses, return true
        return completedCourses == numCourses;
    }
};
