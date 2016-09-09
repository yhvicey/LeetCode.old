#include<vector>
#include<map>

using namespace std;

struct Node
{
	vector<Node*> Dependencies;

	int State;

	Node():
		State(0)
	{

	}
};

class Solution
{
	vector<Node*> nodes;

	void preprocess(vector<pair<int, int>>& prerequisites)
	{		
		int len = prerequisites.size();
		for (int i = 0; i < len; i++)
		{
			nodes[prerequisites[i].first]->Dependencies.push_back(nodes[prerequisites[i].second]);
		}
	}

	bool traverse(Node* start)
	{
		if (!start)
		{
			return false;
		}
		if (start->State == 0)
		{
			start->State = -1;
		}
		else if (start->State == 1)
		{
			start->State = -1;
		}
		else
		{
			return true;
		}
		
		bool result = false;
		int len = start->Dependencies.size();
		for (int i = 0; i < len; i++)
		{
			result |= traverse(start->Dependencies[i]);
		}
		start->State = 1;
		return result;
	}

public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		if (numCourses < 2)
		{
			return true;
		}
		for (int i = 0; i < numCourses; i++)
		{
			nodes.push_back(new Node());
		}
		preprocess(prerequisites);

		return traverse(nodes[0]);
	}
};

int main()
{
	auto var = Solution().canFinish(2, vector<pair<int, int>>{});
	return 0;
}