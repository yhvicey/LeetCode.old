#include<string>
#include<vector>
#include<deque>

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
	vector<string> split(string source, char separator, bool removeEmptyEntries = true)
	{
		string temp = "";
		vector<string> result;
		int len = source.size();
		for (int i = 0; i < len; i++)
		{
			if (source[i] == separator)
			{
				if (removeEmptyEntries)
				{
					if (temp == "")
					{
						continue;
					}
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

public:
	string serialize(TreeNode* root)
	{
		string data;
		deque<TreeNode*> buffer;
		buffer.push_back(root);
		while (!buffer.empty())
		{
			int len = buffer.size();
			for (int i = 0; i < len; i++)
			{
				if (buffer.front() == NULL)
				{
					data += '#';
					buffer.pop_front();
				}
				else
				{
					char integer[32];
					sprintf(integer, "%d", buffer.front()->val);
					data += integer;
					buffer.push_back(buffer.front()->left);
					buffer.push_back(buffer.front()->right);
					buffer.pop_front();
				}
				data += ",";
			}
		}
		return data.substr(0, data.size() - 1);
	}

	TreeNode* deserialize(string data)
	{
		vector<TreeNode*> list;
		auto datas = split(data, ',');
		int len = datas.size();
		if (len < 1)
		{
			return NULL;
		}
		for (int i = 0; i < len; i++)
		{
			if (datas[i] != "#")
			{
				list.push_back(new TreeNode(atoi(datas[i].c_str())));
			}
			else
			{
				list.push_back(NULL);
			}
		}
		auto root = list[0];
		for (int i = 0; i < len; i++)
		{
			if (list[i])
			{
				if (2 * i + 1 < len)
				{
					list[i]->left = list[2 * i + 1];
				}
				if (2 * i + 2 < len)
				{
					list[i]->right = list[2 * i + 2];
				}
			}
		}
		return root;
	}
};

int main()
{
	auto var = Codec().serialize(Codec().deserialize("5,2,3,#,#,2,4,#,#,#,#,3,1,#,#"));
	return 0;
}