#include <iostream>
#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> findFrequentTreeSum(TreeNode* root);
int scaleTree(TreeNode* root);

std::map<int, int> frequencies;

int main() {
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(-3);
    TreeNode* root = new TreeNode(5, left, right);
    std::vector<int> nums = findFrequentTreeSum(root);

    std::cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];

        if (i != nums.size()-1) std::cout << ",";
    }
    std::cout << "]" << std::endl;

    return 0;
}

std::vector<int> findFrequentTreeSum(TreeNode* root) {
    std::vector<int> res;
    int highValue = 0;
    scaleTree(root);
    for (auto i = frequencies.begin(); i != frequencies.end(); i++) {
        int key = i->first;
        int value = i->second;

        if (value > highValue) {
            res.clear();
            res.push_back(key);
            highValue = value;
            continue;
        }

        if (value == highValue) {
            res.push_back(key);
            continue;
        }
    }

    return res;
}

int scaleTree(TreeNode* root) {
    int sum = root->val;
    int val1 = 0;
    int val2 = 0;

    if (root->left != nullptr) {
        val1 = scaleTree(root->left);
    }
    if (root->right != nullptr) {
        val2 = scaleTree(root->right);
    }

    sum += val1+val2;
    if (!frequencies.count(sum)) {
        frequencies[sum] =  1;
        return sum;
    }

    frequencies[sum]++;
    return sum;
}