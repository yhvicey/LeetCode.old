#include <vector>
#include <string>
#include <deque>

using namespace std;

class Node
{
public:
	char Character;

	int Index;

	Node* Children[26];

	Node(char ch) :
		Character(ch),
		Index(-1)
	{
		memset(Children, 0, sizeof(Node*) * 26);
	}

	void AddWord(const string &word, int index)
	{
		if (word.size() == 0)
		{
			Index = index;
			return;
		}
		char first = word[0];
		if (Children[first - 'a'])
		{
			Children[first - 'a']->AddWord(word.substr(1), index);
		}
		else
		{
			Children[first - 'a'] = new Node(first);
			Children[first - 'a']->AddWord(word.substr(1), index);
		}
	}

	void PushWord(const string &word,deque<char> &rightQueue)
	{
		int len = word.size();
		if (len == 0)
		{
			return;
		}
		else
		{
			char first = word[len - 1];
			if (Children[first - 'a'])
			{
				rightQueue.push_front(Character);
				Children[first - 'a']->PushWord(word.substr(0, len - 1), rightQueue);
			}
			else
			{
				return;
			}
		}
	}
};

class Solution
{
	deque<char> left;

	deque<char> right;

	int Compare()
	{

	}

public:
	vector<vector<int>> palindromePairs(vector<string>& words)
	{
		Node root('\0');
		int len = words.size();
		for (int i = 0; i < len; i++)
		{
			root.AddWord(words[i], i);
		}

		vector<vector<int>> result;
		for (int i = 0; i < len; i++)
		{
			root.PushWord(words[i], right);
		}
		return result;
	}
};

int main()
{
	auto var = Solution().palindromePairs(vector<string>{"bbaabaaaabbbbaaaabaaaabaabbabbbaaabbabbbabbaaababbaabbaaaabbbaabbaabaaaabaaabbaabab", "babbbbbaabbbaaaaaabbbbbbbaabbabbabbbbbaababaabbabbbabbbbbbabba", "bbbbaabbbababbabbbbabaababaabbaabbabaaaaabababbabbabbbbbabbbbaaaabbabbabbbabababbbaaa", "ababbbbbbbaaaabbaaababbbabababbaabbaababbbabbbabaabbaabaababbbabababaaabbbbabbaa", "abbbaababaaaaabababaabaaaaaabbbbbbbababaaaabaabbbaaabbaaaabbbabbbbabbaaaaaaaaaaabbaaaababbabbbabbabaaaaabbaababbabbabababaaaaabbabbababbaaaabbbababaaabbaaabbabbaaba", "aabbaaaaaaabaaabbbababbbbabababaaabbbabaabbababbaabbbbbaabbbbaabaa", "abbabaabbaaaaaababbbabbabababbababbbbaaaaabbbaaabbaababbababbbabbaaaabbabbbabbabaaaaaaabbabbbaababaaaabbaabaabababbaaaababbabbbabaabbabbbbaaaabbabbaabbaaaababbbbbbaaaaaababba", "abbabaabbabbabbbabaabbbbbabaabbbbaabaaabaabaaabbaaaaaaababbababb", "bbabbbbaaabbbbaaababbabaabbbbababaaaabbaaabbbaabbbaaabaababababaaaaabbbbaaaabbbababbabbbbaabbbbaaaaaaaaaabbabaaabaabaaa", "aabaabbabbabbaaabbbbbaabbaababbabbaabbabaaaaaababaabaabbaaaabbabbbaababaaabaabbbbbaabbbbabbbbaaaaabbbbabbbbabaabaabbaabbbabaabababaabbaaaaabbabaaabbaabbbabaaaababbabbbababaaabbaa", "bbbaaaaaaaabaababbabbabbbb", "aabbaababbbbbbbabbbababaaaababbabaaabbaaaaabbbaaababbaaabbaaaaaaabbaabbaababbbbaabbaababbabbbbbbaaabaaaabbaabaababaabaab", "aabbaabaabbabaabbbababbbaababbaaaababaaaaabaaaababbabbabababaaaabbabbbabbbbbbaababaaabbbababaabaaaabbbabaaa", "aabbbbbbaabbabababbbbabbbbbaabbabaabbaaabbbb", "ababbabaaabaaa", "babbaaaaabbaaabaaaabaabaabaaabaaaaaaabaaabba", "bababaabbaaaaababbabaaabbbabababbbbbabbbbababb", "aaababbbbaabaabaaaabaabbabbababaaaaab", "baabbbbbaabbaaaaababbabaabbabaaaabbabbbaabbabababababbaabaaabbbaabaabbbabbaaabbbbabababaabaabaabaabbbaaabaaabbbaaabaaaabbaaabbaaaababbbbabbaabbababbaabbbbbbababaaaabbbababa", "baabbabaabaababbbaababbbbbabbbabbaaaaaaaabbbaabbaabaabbbabaabaabaabbaaabaaaabaaabaababaa", "bbabbbabaababaabaaabbbbaaaaaabbbaaaaaaabababababbbbababbaaaaabbaabbabababbaaaabababbababbabbababbabbaa", "aabbaabaabbaaabaaaaaabaaabbabababaaaabbabaabaaabbbabababbaabaaabbabbbbabbaabbababbbabbaaaabaaababbabbbbbbaaabbaababbabaabaaabaaabbbabaababaa", "babaaababaabbabbabbbbbabaaabbaaabbabaabbabbabbbaabbbaaaaaabaabbaababbbbaaababbababbabbbabaababaabbabababbbabaabbbbaabaababbaa", "bbabbababaaababababaabaaaaaaaabaababaababbabbabb", "bbabbbbabbaaaabaabbbbbbabbbaaaaaaabbbbabbaaabbabaabbabaabbbbbbaabbbabaaabbabaaabbaba", "baabbbbbbaaaaabbaabbbbabaaabbaaaabbbaaabbabaaababaababbbbbbabbaabaaabaaabbabbabaaaba", "bbbaabaabbabababbaaabbaaaababaabbbbaabaaaaaaaaabbbbaabbbbabbbabababbabbbbababbaabbba", "aabbbaabaababaaaabbbbabaabaabaaabababbaabbaabbaaabaababaaabbbabaaababaabbaababbbbaababaabaabbaababbababbbbbababababaabbabbaabaaaaaabaabbaabaabaaabaabba", "abbabaababbbbbbaaaaaababbaabaabbaabbaaaababaababaabbbbbaaaabbbabbbbbaabbbbbbaaababbbaabaabababb", "bbbaabaabaaaaabaabaabbbbaaaabaabbbbbaabbaaabbbbbababbbbabbaaaaabbaababababababbbbbbbaaabaabbbaaaaababbbaabbabaabababbbbaaabaabbababbbaabbaabbbbaaaabababbabaabbaaaaaababaaaaabaababaabbabaabbabababab", "babaabaabaabbbabaaaabaabbbaaaaaaabaababbabbbaabbbabaababbabbaabbaaabaaaabaababbabbaababbabababbbabaabbbababbbbbbbaaababbaaaabaabaabbababbaaabbaabbbaaabaabaaaabaa", "abbbababaaabbaabbbbabababbaabbaaaabaabaabbbbbbbbaabbbbaaaaabbbbabaaaaabbbaaaaabbbbaaaaaababbbbbaabbabaaaaabbaabaaabaababbabaabaaabbab", "babaabaababababbbbabababbbaabbaaabbbaabbaaaabaaabbbbbaaaab", "aaaabbaabababbbaa", "bbbbabbaabaabbbbaaaaaaaabbaababaaabaaabaaabbbbaababbbaabaabbbbaaabbabaabbbbbabbbbaaabababaabbaaababbabababbbabbabaabaaaabbab", "aababaabaaaaaabbabababaaaaababbbbaabaa", "bbababaaaaaaaaabaabbaaaabaaaaaaaaabbbabaabbbbbabaabaaabbbabbbabbbaaaaaabaaabbbbbbaa", "abbaabaaaaabbaaaaaabbbbabaabbabbaabbbabbababaabaabaaabbababbaaabaababbbbbabbbabbabbaaaabbaababbaababbbabbbbbbaaabbbbbbb", "baabababbbbbaabbbabaababaababaababbbabbbbbababbaababbaaaabaaabbbbaaaababbabbbabaabaabbababaaa", "abbaabbbaabbabbabbbbbbbabbbabbaaabbaaababbaabbaababab", "bbabbabbbbbbabababbbabaabbbaaaabababbaabbbabbbbaababbaabaaabbbbabaaaabbbabbaaabaabbaabbbaaababbaaaabaabbabbbabbbaaabaaabbbbabbaabbaabaa", "aaaabbbabbaabbababbabbabaababbababaabbaaabaaaababbbabbaaaabbbbabaaabbbaaabababbbabbaabaaabbaabbbaabbbbaaabbbaabbbbababaaaaababbbabaabbbbbbabbabbbbbabaaabaaaaaabbaa", "babaaabaabbaababaaabbaaababbbbbbbaabbbbbbbbabbaabbbbbbaaaaabbaabababaabbbabaaaaaaabbaabababaaabbabbabbaababbaaabbbaaaababbbbbabbbaabbbaaaabbabbaabbbaababbaaaabbaaaababbbbbb", "abaababbaaabbbaaaaababaabbab", "aabbaaaababbbabbbaaabaabababbabbbaabaaaabaabaaaabbabaabbaaabbbaaabbaabbabbbbaaabbbababbaabbaaaabbbabaabbbabbbbbbbaab", "aabbbabbabaaaaabbabbababbbabbbbbbbbaabbbbabbbaabaabbaaababbbaaaaabbaaabbab", "baaaabababaaababbaabbbabaaabbbbabbbbaaaabbabbbbbbbbababbaaaaabaabaaabbaabbbbbabababaabbbbaabbbbbabbaabaaabaababbbabbbabaababbaaaabbaaaaaabaababbbabaabbbaaabbbabbbaabbbbbbaabbabbbbabaabbbbaba", "bbbaababaabaabbabbaabbabbaabbbbabaabbabbbbbbbabbaaaaababaaabbbaba", "baaaaababaabaabaabbbbabbbbbaabbaabbaaababaabaababaabbaaabbabbbabbbaababababbaaaab", "baabaaababbabbbaaaabbaabbaababbaababbbaabaabaaaaaabbbbababaaabaaabaababbaabbabbaababbbbbabbabbaabbaabbbabbbaabb", "bbaaaaabbbaaabbbaaaaaaaaaabaaaaa", "bbbbbbabaaaaabbbbaaabbabaababaabababbabbabaabababababbaabbabbbabbbababa", "bbaabbbaabbabababaaaaaabbaabbababbbbabaabbbaabbabaabbbabbbabbaaabbabbababaaabbbababbabbbbbbbbaaaaabbaa", "abaabbbaabbbbaabbabaabaaabaabaaaabbabbbabbaaabbbbababaabaaabaaaaaaaabaaaababbababaabbbbbaababaabbbbabbaaabbbabbabbbbabbbbaabaaa", "bababbabbaaabbabaababbbbaabaabbbbbbababaabbbbaababababbaabbaabaaaababbabbabab", "baaabbabbaaababbbbbbbaabaaabbabbaaabbabababbaaaabaabbbbaaaabbabbbbbbabaaaaabaabaaaaabababbbaabbaabbabbbbbabaababababbbbbbaabbbabbbaaabaabababaabaabbbbbbbbabaaaaabbaababab", "ababababababbbabbabbbbbabbabbbbabbaaabbbbbbbbbbabbaabaabbbababbabbbaaaababbaabbbaab", "baaaabbababbabaabbabbaabbbbabbbabbabbbbbabaaaabaabbbabbaababbabababaaaaabaaaababbbabbbaaaaabbbabbbaaaabbbbbaaaba", "baababbbaaaabbbaaababbabaababbbbbaaabaabaaabababbbbaabbaaabaaabaaaaaabbbbbaabaaaababbbaabb", "aaabaabbabaaaaaaaaaabbb", "abbbaabaabbbbbabbaababbaaaaababbaaaaabbabbbb", "ababaabababbbabbbbaaabbabbbaaaaaaabbabbbaba", "baababbaabbbaabbbbbbaaabbbbaaaabbbbabaabbaaabaaababbbaaabbaabaabaabaaabbbbbaabaaaaab", "babbabababaabbbaabababaaaaaaaaaabbbbabbababbbaaaabbaabababbbbbbbababaaaababbaaaabaabaaabaabaaaaababbbbababbaabbaaabbabaaababbbbbabbbaaabaababbaabbabbbbaaaabababaaa", "abbbbbaaaaabbaabbbabaabbabaabbbaaabbaaabaabbb", "abbababb", "aababaaabbbabbbbaaaabaababbababbbaaaaabbababbbbaaaaaababababaabaaaabbbabbaababbbabbabaabbababbbbabbabbbabaaabababaababbbbbaaabaabaaaabbabbaaababbabaaaaa", "abbbaaaaabaabbbabbbabbaaabbaababababbbaabbababaababaabbaaababbabbb", "aaabaaabaabaababbabbbbaaaaaaaaabbbabbaabbababbaabababbbbbabbabababbabaaaabbbbabbbbbbbabbabaabababbaaabbaaaaaabbababbbbbbbaabbabbaaaababbabaaabbaabaaababaabaaaabaaba", "baabbabbaabbbabbbbabbbaabbabaababaaaabaaaabbaaabaaababbabbbbbabaabbbaababaaababaababbaabaabaabababaaabbbbaabbbabbbbbba", "abaababaaabaabbaabaaababbaabbbababbbaaaaaabbbabaaababbaabbbbaaabaabbaaabaaaababbabbbbbababbbaabbaaababaaaaaaababbbbbba", "aaaabbaaaaaabbbaaaaabbaabbaabaabbababbbbbabababbababbabbaaaaabbaaabbabbaaabbbbbbaaabbbbbabbbbbabbabbaaaaaabbbbbaaaaaabbabbbbbbabbbaabbbaababbbbbabbaaabaa", "ababbaaaababababbabaaabaaaaaabbbbababaababbababaabaabababaaaabbaaabaaaaaaabbbbababbabbbbabbbbbbabbbabaabbbabbbbbabbbbbababbbbaabbbaabbbababaaaabbbbaaabbab", "bbabaababbabbbbbbaabbaaaabbaaabbabbaaabbabbaabaaabbbabbbababaabbbaaba", "bbaaabbbaabaababbbababaaabbbbababbbbbaabaaabbbaabbbaaaaabbaabbaabaaabbabaababaaabbaababaabbbbbbaaabbabaabababaabbbaaaaabbbaaaabaabbababaaababaabbaabaaaaabaaaababbabaabababababaabaaaabaaabbaaabbbbababa", "abbaaabbbaabbabb", "abbbabbaaaabaabaaababaaaaabababbbaabbbbaabbbaaa", "babaaabbbbbb", "baaabaaabbbabaabbbaabaabbaaaabbbabbabbbbbaabbabbbabaabababaabbbbabaabaabbaaabbbabaaaaaaaaaabbbbaaabbaaaaaabaababbaabbabaabbbabaaabbbbaabbaababba", "babababbbbabbaaaaaabbbbbaba", "babba", "abbbabaabbabbbbbbbbababaaaaaab", "bbabbabbbabaaabbbaaababbbbaaaaaaabab", "bbabbaabbbabaaaaaababaabbbabaaabaaababaabaaaaaaaaaaabbaababaababbababbabbababbbaaabbaaaabbaabbbbaaabbabbbabaabbbbbabababbaabaabbbabaabaaabaaababbbabbabbaababaabbbbaabaabbabbbbabbabbaababbbbba", "bbaaabaaababaaaabbaabbabbbaabbaaabaababbaaababbbaaabaabaabbabababaaaabbbbbaaaabbbbbbababbbbabbbababbaababaababbbabaaabbabaaaabababaaabababaaabbbbbaaaaababaabbbbaabaaabba", "ababaaaaaabbabbabba", "aaabababaabaaabaaaaabaaabaababbbbbababbbabbbbbbaabbaaaaaba", "baabbbab", "abbaaaaababbbaaaabbbaaabbaaababbababababaabbabaabaaabaabaaabbaaabbababbaabaaaabaabababbbbbbabaabaaabaaaababbaababbaabbbbbaabbbbbbabaa", "ababaaabbababbabbbaabbbaabaaaaaaaabbabaabaaaaaabaa"});
	return 0;
}