#define _CRT_SECURE_NO_WARNINGS 1

//LCR 194. 二叉树的最近公共祖先
class Solution
{
public:
    bool Find(TreeNode* root, TreeNode* val)
    {
        if (root == NULL)
            return false;

        return root == val
            || Find(root->left, val)
            || Find(root->right, val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        bool pinleft, pinright, qinleft, qinright;
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
        {
            return root;
        }

        pinleft = Find(root->left, p);
        pinright = !pinleft;
        qinleft = Find(root->left, q);
        qinright = !qinleft;

        if (pinleft && qinleft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (pinright && qinright)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};

//JZ36 二叉搜索树与双向链表
class Solution {
public:
    void Inorder(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == nullptr)
            return;

        Inorder(cur->left, prev);
        cur->left = prev;
        if (prev)
            prev->right = cur;
        prev = cur;
        Inorder(cur->right, prev);

    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
        Inorder(pRootOfTree, prev);
        TreeNode* head = pRootOfTree;
        while (head && head->left)
        {
            head = head->left;
        }
        return head;
    }
};

//105. 从前序与中序遍历序列构造二叉树
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend)
    {
        if (inbegin > inend)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[prei]);
        int rooti = inbegin;
        while (rooti <= inend)
        {
            if (preorder[prei] == inorder[rooti])
            {
                break;
            }
            ++rooti;
        }
        ++prei;
        //[inbegin][rooti-1]rooti[rooti+1][intend]
        root->left = _buildTree(preorder, inorder, prei, inbegin, rooti - 1);
        root->right = _buildTree(preorder, inorder, prei, rooti + 1, inend);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);

    }
};

//144. 二叉树的前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        vector<int> v;
        while (cur || !st.empty())
        {
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            st.pop();

            cur = top->right;

        }

        return v;

    }
};