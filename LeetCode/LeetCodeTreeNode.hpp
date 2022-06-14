#ifndef LEETCODE_TREE_NODE_HPP
#define LEETCODE_TREE_NODE_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val = {};
    TreeNode* left = {};
    TreeNode* right = {};
    TreeNode() = default;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool IsNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

template<typename T>
T Convert(std::string str) 
{
    T num;
    std::stringstream ss;
    ss << str;
    ss >> num;

    return num;
}

std::vector<std::string> SplitString(std::string data, char spilter)
{
    std::stringstream test;
    test << data;
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(test, segment, spilter))
    {
        seglist.push_back(segment);
    }
    return seglist;
}

std::vector<TreeNode> ConvertToTree(std::vector<std::string>& datas)
{
    auto output = std::vector<TreeNode>(datas.size() + 1);

    datas.push_back("empty");
    std::rotate(datas.rbegin(), datas.rbegin() + 1, datas.rend());


    for (size_t i = datas.size() - 1; i > 0 ; --i)
    {

        if (IsNumber(datas[i]))
        {
            output[i].val = Convert<int>(datas[i]);
            if (i % 2)
            {
                output[i / 2].right = &(output[i]);

            }
            else
            {
                output[i / 2].left = &(output[i]);
            }
        }
    }
    return output;
}

std::vector<TreeNode> LeetcodeStringToTree(std::string data)
{
    data = data.substr(1, data.size() - 2);
    auto datas = SplitString(data, ',');
    return ConvertToTree(datas);
}

#endif // !LEETCODE_TREE_NODE_HPP
