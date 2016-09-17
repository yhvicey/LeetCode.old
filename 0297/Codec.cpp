#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class Codec
{
	deque<TreeNode*> _serializeBuffer;

	deque<TreeNode*> _deserializeBuffer;

	stringstream converter;

	static vector<string> split(string& source, char separator)
	{
		string temp = "";
		vector<string> result;
		int len = source.size();
		for (auto i = 0; i < len; i++)
		{
			if (source[i] == separator)
			{
				if (temp == "")
				{
					continue;
				}
				result.push_back(temp);
				temp = "";
			}
			else
			{
				temp += source[i];
			}
		}
		result.push_back(temp);
		return result;
	}

	int parse(string &input)
	{
		converter << input;
		int output;
		converter >> output;
		converter.str("");
		converter.clear();
		return output;
	}

public:
	string serialize(TreeNode* root)
	{
		stringstream ss;
		ss << "[";
		_serializeBuffer.push_back(root);
		while (!_serializeBuffer.empty())
		{
			auto front = _serializeBuffer.front();
			_serializeBuffer.pop_front();
			if (front == NULL)
			{
				ss << "null,";
			}
			else
			{
				ss << front->val << ",";
				_serializeBuffer.push_back(front->left);
				_serializeBuffer.push_back(front->right);
			}
		}
		auto str = ss.str();
		return str.substr(0, str.size() - 1) + "]";
	}

	TreeNode* deserialize(string data)
	{
		data = data.substr(1, data.size() - 2);
		auto datas = split(data, ',');
		auto len = datas.size();
		TreeNode* root = NULL;
		auto leftSetted = false;
		for (auto i = 0; i < len; i++)
		{
			if (datas[i] == "null")
			{
				if (!_deserializeBuffer.empty())
				{
					auto front = _deserializeBuffer.front();
					if (leftSetted)
					{
						front->right = NULL;
						_deserializeBuffer.pop_front();
						leftSetted = false;
					}
					else
					{
						front->left = NULL;
						leftSetted = true;
					}
				}
			}
			else
			{
				auto node = new TreeNode(parse(datas[i]));
				if (root == NULL)
				{
					root = node;
				}
				if (!_deserializeBuffer.empty())
				{
					auto front = _deserializeBuffer.front();
					if (leftSetted)
					{
						front->right = node;
						_deserializeBuffer.pop_front();
						leftSetted = false;
					}
					else
					{
						front->left = node;
						leftSetted = true;
					}
				}
				_deserializeBuffer.push_back(node);
			}
		}
		return root;
	}
};

int main()
{
	auto var = Codec().serialize(Codec().deserialize("[5,2,3,null,null,2,4,null,null,null,null]"));
	return 0;
}