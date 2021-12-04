//1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/discuss/551049/C%2B%2B-simple.-No-additional-data-structures.-Traverse-both-trees-synchronously

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

		if (original == target) return cloned;

		if (!original) 	return nullptr;

		auto left_node = getTargetCopy(original->left, cloned->left, target);
		if (left_node) {
			return left_node;
		}
		else
		{
			auto right_node = getTargetCopy(original->right, cloned->right, target);
			return right_node;
		}
    }
}