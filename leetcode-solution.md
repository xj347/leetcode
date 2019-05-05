144. Binary Tree Preorder Traversal
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //recursive
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    void preorder(TreeNode* root, vector<int> &res)
    {
        if (root)
        {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }

    //iterative
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        if (root)
            nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode *cur = nodeStack.top();
            res.push_back(cur->val);
            nodeStack.pop();
            if (cur->right)
                nodeStack.push(cur->right);
            if (cur->left)
                nodeStack.push(cur->left);
        }
        return res;
    }
};
```

94. Binary Tree Inorder Traversal
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //recursive
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root)
        {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    
    //iterative
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode *cur = root;
        while (cur != NULL || !nodeStack.empty())
        {
            if (cur)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = nodeStack.top();
                res.push_back(cur->val);
                nodeStack.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};
```

145. Binary Tree Postorder Traversal
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //recursive
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode *root, vector<int> &res)
    {
        if (root)
        {
            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    }

    //iterative
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode *cur = root, *pre = NULL;
        while (cur != NULL || !nodeStack.empty())
        {
            if (cur)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *tmp = nodeStack.top();
                if (tmp->right != NULL && pre != tmp->right)
                {
                    cur = tmp->right;
                }
                else
                {
                    res.push_back(tmp->val);
                    nodeStack.pop();
                    pre = tmp;
                }
            }
        }
        return res;
    }
};
```

102. Binary Tree Level Order Traversal
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> level;
        queue<TreeNode*> nodeQue;
        nodeQue.push(root);
        while(!nodeQue.empty())
        {
            int n = nodeQue.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = nodeQue.front();
                level.push_back(cur->val);
                if (cur->left)
                    nodeQue.push(cur->left);
                if (cur->right)
                    nodeQue.push(cur->right);
                nodeQue.pop();
            }
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};
```

100. Same Tree
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

101. Symmetric Tree
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val)
            return false;
        return helper(root1->left, root2->right) && helper(root1->right, root2->left);
    }
};
```

110. Balanced Binary Tree
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
    
    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = height(root->left);
        if (left == -1)
            return -1;
        int right = height(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
```

114. Flatten Binary Tree to Linked List
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flat(root);
    }
    
    TreeNode *flat(TreeNode* root)
    {
        if (!root) return NULL;
        TreeNode *L = root->left;
        TreeNode *R = root->right;
        root->left = NULL;
        TreeNode *tail = root;
        if (L)
        {
            tail->right = L;
            tail = flat(L);
        }
        if (R)
        {
            tail->right = R;
            tail = flat(R);
        }
        return tail;
    }
}
```

116. Populating Next Right Pointers in Each Node
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    //recursive
    Node* connect(Node* root) {
        if (!root)
            return root;
        if (root->left)
            root->left->next = root->right;
        if (root->right)
            root->right->next = root->next ? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;
    }

    //iterative
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node *head = root, *cur = NULL;
        while(head->left)
        {
            cur = head;
            while(cur)
            {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            head = head->left;
        }
        return root;
    }
};
```

117. Populating Next Right Pointers in Each Node II
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *cur = root;
        while (cur)
        {
            Node *nextHead = NULL;
            Node *prevNode = NULL;
            while (cur)
            {
                if (!nextHead)
                    nextHead = cur->left ? cur->left : cur->right;
                if (cur->left)
                {
                    if (prevNode)
                        prevNode->next = cur->left;
                    prevNode = cur->left;
                }
                if (cur->right)
                {
                    if (prevNode)
                        prevNode->next = cur->right;
                    prevNode = cur->right;
                }
                cur = cur->next;
            }
            cur = nextHead;
        }
        return root;
    }
};
```

105. Construct Binary Tree from Preorder and Inorder Traversal
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd)
    {
        if (pStart > pEnd || iStart > iEnd || pEnd - pStart != iEnd - iStart)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pStart]);
        int i;
        for (i = iStart; i < iEnd; i++)
        {
            if (inorder[i] == root->val)
            {
                break;
            }
        }
        int leftLen = i - iStart;
        root->left = build(preorder, inorder, pStart+1, pStart+leftLen, iStart, i-1);
        root->right = build(preorder, inorder, pStart+leftLen+1, pEnd, i+1, iEnd);
        return root;
    }
};
```

106. Construct Binary Tree from Inorder and Postorder Traversal
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd)
    {
        if (pStart > pEnd || iStart > iEnd || pEnd - pStart != iEnd - iStart)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pEnd]);
        int i;
        for (i = iStart; i < iEnd; i++)
        {
            if (inorder[i] == root->val)
            {
                break;
            }
        }
        int rightLen = iEnd - i;
        root->left = build(postorder, inorder, pStart, pEnd-rightLen-1, iStart, i-1);
        root->right = build(postorder, inorder, pEnd-rightLen, pEnd-1, i+1, iEnd);
        return root;
    }
};
```

96. Unique Binary Search Trees
```cpp
// Catalan number
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1, 0);
        res[0] = res[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                res[i] += (res[j] * res[i-1-j]);
        return res[n];
    }
};
```

95. Unique Binary Search Trees II
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int s, int e)
    {
        vector<TreeNode*> res;
        if (s > e)
        {
            res.push_back(NULL);
            return res;
        }
        for (int r = s; r <= e; r++)
        {
            vector<TreeNode*> leftRes = generate(s, r-1);
            vector<TreeNode*> rightRes = generate(r+1, e);
            for (int i = 0; i < leftRes.size(); i++)
                for (int j = 0; j < rightRes.size(); j++)
                {
                    TreeNode *root = new TreeNode(r);
                    root->left = leftRes[i];
                    root->right = rightRes[j];
                    res.push_back(root);
                }
        }
        return res;
    }
};
```

98. Validate Binary Search Tree
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //BST定义
    bool isValidBST(TreeNode* root) {
        return validBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
    
    bool validBST(TreeNode* root, long long lower_bound, long long upper_bound)
    {
        if (!root)
            return true;
        return root->val > lower_bound && root->val < upper_bound &&
               validBST(root->left, lower_bound, root->val) &&
               validBST(root->right, root->val, upper_bound);
    }
    
    //BST性质
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
    
    bool inorder(TreeNode* root, TreeNode* &prev)
    {
        if (!root) return true;
        bool left = inorder(root->left, prev);
        if (!left)
            return false;
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        return inorder(root->right, prev);
    }
};
```

108. Convert Sorted Array to Binary Search Tree
```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* buildBST(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid-1);
        root->right = buildBST(nums, mid+1, right);
        return root;
    }
};
```

109. Convert Sorted List to Binary Search Tree
```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode *p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        return buildBST(head, 0, len - 1);
    }
    
    TreeNode* buildBST(ListNode* &head, int left, int right)
    {
        if (!head)
            return NULL;
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *leftRoot = buildBST(head, left, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = leftRoot;
        root->right = buildBST(head, mid + 1, right);
        return root;
    }
};
```

111. Minimum Depth of Binary Tree
```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0)
            return right + 1;
        if (right == 0)
            return left + 1;
        return min(left, right) + 1;
    }
};
```

104. Maximum Depth of Binary Tree
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};
```

112. Path Sum
```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (root->left == NULL && root->right == NULL)
            return sum == root->val;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```

113. Path Sum II
```cpp
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        getPath(root, sum, path, res);
        return res;
    }
    
    void getPath(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == sum)
            {
                res.push_back(path);
            }
        }
        getPath(root->left, sum - root->val, path, res);
        getPath(root->right, sum - root->val, path, res);
        path.pop_back();
    }
};
```

124. Binary Tree Maximum Path Sum
```cpp
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
    
    int helper(TreeNode* root, int &maxSum)
    {
        if (!root)
            return 0;
        int leftMax = helper(root->left, maxSum);
        int rightMax = helper(root->right, maxSum);
        int pathSum = root->val;
        if (leftMax > 0)
            pathSum += leftMax;
        if (rightMax > 0)
            pathSum += rightMax;
        if (pathSum > maxSum)
            maxSum = pathSum;
        return max(leftMax, rightMax) > 0 ? root->val + max(leftMax, rightMax) : root->val;
    }
};
```

129. Sum Root to Leaf Numbers
```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;  
    }
    
    void helper(TreeNode* root, int num, int &sum)
    {
        if (!root)
            return;
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            sum += num;
        }
        helper(root->left, num, sum);
        helper(root->right, num, sum);
    }
};
```

88. Merge Sorted Array
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        m--;
        n--;
        while(m >= 0 && n >= 0)
        {
            if (nums1[m] >= nums2[n])
                nums1[k--] = nums1[m--];
            else
                nums1[k--] = nums2[n--];
        }
        while(n >= 0)
        {
            nums1[k--] = nums2[n--];
        }
    }
};
```

21. Merge Two Sorted Lists
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next =l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        return dummy.next;
    }
};
```

23. Merge k Sorted Lists
```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        return merge(lists, 0, lists.size()-1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        int mid = (left + right) / 2;
        ListNode *list1 = merge(lists, left, mid);
        ListNode *list2 = merge(lists, mid+1, right);
        return mergeTwoLists(list1, list2);
    }
};

147. Insertion Sort List
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        while (head)
        {
            ListNode *p = &dummy;
            while (p->next && p->next->val <= head->val)
            {
                p = p->next;
            }
            ListNode *tmp = head->next;
            head->next = p->next;
            p->next = head;
            head = tmp;
        }
        return dummy.next;
    }
};
```

148. Sort List
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *headRight = slow->next;
        slow->next = NULL;
        head = sortList(head);
        headRight = sortList(headRight);
        return mergeTwoLists(head, headRight);
    }
};
```

41. First Missing Positive
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
                    swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
```

75. Sort Colors
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size()-1;
        int i = 0;
        while (i <= blue)
        {
            if (nums[i] == 0)
            {
                swap(nums[red++], nums[i]);
                i++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[blue--], nums[i]);
            }
            else
                i++;
        }
    }
};
```

55. Jump Game
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        int reach = 0;
        for (int i = 0; i <= reach && i < nums.size(); i++)
        {
            reach = max(reach, nums[i] + i);
            if (reach >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
```

45. Jump Game II
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int reach = 0, lastReach = 0, step = 0;
        for (int i = 0; i <= reach && i < nums.size(); i++)
        {
            if (i > lastReach)
            {
                step++;
                lastReach = reach;
                if (reach >= nums.size() - 1)
                    return step;
            }
            reach = max(reach, nums[i] + i);
        }
        return 0;
    }
};
```

121. Best Time to Buy and Sell Stock
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
```

122. Best Time to Buy and Sell Stock II
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i-1])
                maxProfit += prices[i] - prices[i-1];
        }
        return maxProfit;     
    }
};
```

3. Longest Substring Without Repeating Characters
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector lastAppear(256, -1);
        int start = -1, maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            start = max(lastAppear[s[i]], start);
            maxLen = max(maxLen, i - start);
            lastAppear[s[i]] = i;
        }
        return maxLen;
    }
};
```

11. Container With Most Water
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0;
        while (left < right)
        {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};
```

120. Triangle
```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++)
            f[i] = triangle[n-1][i];
        for (int row = n-2; row >= 0; row--)
            for (int i = 0; i <= row; i++)
            {
                f[i] = min(f[i], f[i+1]) + triangle[row][i];
            }
        return f[0];
    }
};
```

53. Maximum Subarray
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxSum = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
```

132. Palindrome Partitioning II
```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> f(n);
        vector<vector<bool>> palind(n,vector<bool>(n,false));
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
            for (int j = 0; j <= i; j++)
            {
                if (s[i] == s[j] && (i - j <= 2 || palind[j+1][i-1]))
                {
                    f[i] = j == 0 ? 0 : min(f[i], f[j-1] + 1);
                    palind[j][i] = true;
                }
            }
        }
        return f[n-1];
    }
};
```

123. Best Time to Buy and Sell Stock III
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> firstBuy(n, 0);
        vector<int> secondBuy(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; i++)
        {
            firstBuy[i] = max(firstBuy[i-1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            secondBuy[i] = max(secondBuy[i+1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, firstBuy[i] + secondBuy[i]);
        }
        return maxProfit;
    }
};
```

97. Interleaving String
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3)
            return false;
        vector<vector<bool>> f(len1+1,vector<bool>(len2+1,false));
        f[0][0] = true;
        for (int i = 1; i <= len1; i++)
        {
            if (f[i-1][0] && s1[i-1] == s3[i-1])
                f[i][0] = true;
        }
        for (int i = 1; i <= len2; i++)
        {
            if (f[0][i-1] && s2[i-1] == s3[i-1])
                f[0][i] = true;
        }
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
            {
                if ((f[i-1][j] && s1[i-1] == s3[i+j-1]) || (f[i][j-1] && s2[j-1] == s3[i+j-1]))
                    f[i][j] = true;
            }
        return f[len1][len2];
    }
};
```

91. Decode Ways
```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int f = 0, f_1 = 1, f_2 = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] >= '1' && s[i] <= '9')
                f += f_1;
            if (s[i-1] == '1' || (s[i-1] == '2' && (s[i] >= '0' && s[i] <= '6')))
                f += f_2;
            f_2 = f_1;
            f_1 = f;
            f = 0;
        }
        return f_1;
    }
};
```

115. Distinct Subsequences
```cpp
class Solution {
public:
    // f(i,j)=s[i]==t[j] ? f(i-1,j)+f(i-1,j-1):f(i-1,j)
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> f(m+1, vector<long long>(n+1, 0));
        for (int i = 0; i <= m; i++)
            f[i][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                f[i][j] = s[i-1]==t[j-1] ? f[i-1][j]+f[i-1][j-1] : f[i-1][j];
            }
        return f[m][n];
    }
};
```

64. Minimum Path Sum
```cpp
class Solution {
public:
    // f[i][j]=min(f[i-1][j],f[i][j-1]) + grid[i][j]
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector f(n, 0);
        f[0] = grid[0][0];
        for (int i = 1; i < n; i++)
            f[i] = f[i-1] + grid[0][i];
        for (int i = 1; i < m; i++)
        {
            f[0] = f[0] + grid[i][0];
            for (int j = 1; j < n; j++)
                f[j] = min(f[j], f[j-1]) + grid[i][j];
        }
        return f[n-1];
    }
};
```

139. Word Break
```cpp
class Solution {
public:
    //f[i]=f[j] && str(j+1,i) in dict
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        int n = s.size();
        vector<bool> f(n+1, false);
        f[0] = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
            {
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end())
                {
                    f[i+1] = true;
                    break;
                }
            }
        return f[n];
    }
};
```

140. Word Break II
```cpp
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if (s.empty()) return res;
        int n = s.size();
        unordered_map<int, vector<string>> cache;
        res = findPath(0, s, cache, wordDict);
        return res;
    }
    
    vector<string> findPath(int pos, string &s, unordered_map<int, vector<string>> &cache, vector<string>& wordDict) {
        if (cache.find(pos) != cache.end())
        {
            return cache[pos];
        }
        vector<string> res;
        if (pos == s.size())
        {
            res.push_back("");
            return res;
        }
        for (int i = pos; i < s.size(); i++)
        {
            string sub = s.substr(pos, i-pos+1);
            if (find(wordDict.begin(), wordDict.end(), sub) != wordDict.end())
            {
                vector<string> tails = findPath(i+1, s, cache, wordDict);
                for (string tail : tails)
                    res.push_back(sub + (tail == "" ? "":" ") + tail);
            }
        }
        cache[pos] = res;
        return res;
    }
};
```

72. Edit Distance
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; i++)
            f[i][0] = i;
        for (int i = 0; i <= n; i++)
            f[0][i] = i;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1;
            }
        return f[m][n];
    }
};
```

131. Palindrome Partitioning
```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> path;
        dfs(0, path, s, res);
        return res;
    }
    
    void dfs(int index, vector<string> &path, string &s, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i-index+1));
                dfs(i+1, path, s, res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int left, int right)
    {
        while(left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};
```

62. Unique Paths
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 0);
        f[0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                f[j] = f[j] + f[j-1];
        return f[n-1];
    }
};
```

63. Unique Paths II
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<unsigned int>> f(m, vector<unsigned int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
                f[i][0] = 1;
            else
                break;
        }
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0)
                f[0][i] = 1;
            else
                break;
        }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    f[i][j] = 0;
                else
                    f[i][j] = f[i][j-1] + f[i-1][j];
            }
        return f[m-1][n-1];
    }
};
```

51. N-Queens
```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> columns(n, 0);
        dfs(0, n, columns, res);
        return res;
    }
    
    void dfs(int colIndex, int n, vector<int> &columns, vector<vector<string>> &res)
    {
        if (colIndex == n)
        {
            vector<string> solution;
            for (int i = 0; i < n; i++)
            {
                string row(n, '.');
                for (int j = 0; j < n; j++)
                {
                    if (columns[j] == i)
                        row[j] = 'Q';
                }
                solution.push_back(row);
            }
            res.push_back(solution);
            return;
        }
        
        for (int i = 0; i < n; i++)
        {
            bool valid = true;
            for (int j = 0; j < colIndex; j++)
            {
                if (columns[j] == i || abs(i - columns[j]) == colIndex - j)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                columns[colIndex] = i;
                dfs(colIndex + 1, n, columns, res);
            }
        }
    }
};
```

93. Restore IP Addresses
```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(0, 0, "", s, res);
        return res;
    }
    
    void dfs(int index, int step, string path, string &s, vector<string> &res)
    {
        if (s.size() - index < 4 - step || s.size() - index > 3 * (4 - step))
            return;
        if (step == 4)
        {
            res.push_back(path);
            return;
        }
        for (int j = 1; j <= 3 && index + j <= s.size(); j++)
        {
            string curNum = s.substr(index, j);
            if (curNum.size() == 3 && curNum > "255")
                continue;
            if (curNum.size() >= 2 && curNum[0] == '0')
                continue;
            if (index != 0)
                dfs(index+j, step+1, path + '.' + curNum, s, res);
            else
                dfs(index+j, step+1, curNum, s, res);
        }
    }
};
```

39. Combination Sum
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty() || target <= 0)
            return res;
        vector<int> path;
        dfs(0, target, path, res, candidates);
        return res;
    }
    
    void dfs(int index, int gap, vector<int> &path, vector<vector<int>> &res, vector<int>& candidates)
    {
        if (gap < 0)
            return;
        if (gap == 0)
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(i, gap - candidates[i], path, res, candidates);
            path.pop_back();
        }
    }
};
```

40. Combination Sum II
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty() || target <= 0)
            return res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, path, res, candidates);
        return res;
    }
    
    void dfs(int index, int gap, vector<int> &path, vector<vector<int>> &res, vector<int>& candidates)
    {
        if (gap < 0)
            return;
        if (gap == 0)
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            dfs(i+1, gap - candidates[i], path, res, candidates);
            path.pop_back();
        }
    }
};
```

22. Generate Parentheses
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, n, "", res);
        return res;
    }
    
    void dfs(int leftNum, int rightNum, int n, string path, vector<string> &res)
    {
        if (rightNum > leftNum || leftNum > n)
            return;
        if (leftNum == n && rightNum == n)
        {
            res.push_back(path);
            return;
        }
        dfs(leftNum+1, rightNum, n, path + "(", res);
        dfs(leftNum, rightNum+1, n, path + ")", res);
    }
};
```

50. Pow(x, n)
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            return 1.0 / power(x, -(long long)n);
        }
        else
            return power(x, n);
    }
    
    double power(double x, unsigned int n)
    {
        if (n == 0)
            return 1.0;
        double half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
```

69. Sqrt(x)
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int left = 1, right = x / 2;
        int lastLeft;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (x / mid < mid) // x < mid*mid
                right = mid-1;
            else if (x / mid > mid)
            {
                left = mid+1;
                lastLeft = mid;
            }
            else
                return mid;
        }
        return lastLeft;
    }
};
```

9. Palindrome Number
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int d = 1;
        while (x / d >= 10)
        {
            d = d * 10;
        }
        while (x > 0)
        {
            int l = x / d;
            int r = x % 10;
            if (l != r)
                return false;
            x = x % d / 10;
            d = d / 100;
        }
        return true;
    }
};
```

57. Insert Interval
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        for (; i < intervals.size() && intervals[i][1] < newInterval[0]; i++)
        {
            res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        if (i < intervals.size())
            res.back()[0] = min(res.back()[0], intervals[i][0]);
        for (; i < intervals.size() && intervals[i][0] <= newInterval[1]; i++)
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        for (; i < intervals.size(); i++)
        {
            res.push_back(intervals[i]);          
        }
        return res;
    }
};
```

56. Merge Intervals
```cpp
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        int i = 1;
        while (i < intervals.size())
        {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
```

419. Battleships in a Board
```cpp
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        int m = board.size(), n = board[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'X')
                {
                    if ((i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.'))
                        res++;
                }          
            }
        return res;
    }
};
```

171. Excel Sheet Column Number
```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int curNum = s[i] - 'A' + 1;
            res = res * 26 + curNum;
        }
        return res;
    }
};
```

236. Lowest Common Ancestor of a Binary Tree
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left && left != p && left != q) return left;
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }
};
```

200. Number of Islands
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    res++;
                    dfs(i, j, visited, grid);
                }
            }
        return res;
    }
    
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>>& grid)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j])
            return;
        visited[i][j] = true;
        dfs(i-1, j, visited, grid);
        dfs(i+1, j, visited, grid);
        dfs(i, j-1, visited, grid);
        dfs(i, j+1, visited, grid);
    }
};
```

238. Product of Array Except Self
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++)
        {
            res[i] = res[i-1] * nums[i-1];
        }
        int tmp = 1;
        for (int i = n-2; i >= 0; i--)
        {
            tmp *= nums[i+1];
            res[i] *= tmp;
        }
        return res;
    }
};
```

268. Missing Number
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res = res ^ (i+1) ^ nums[i];
        }
        return res;
    }
};
```

48. Rotate Image
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};
```

151. Reverse Words in a String
```cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, idx = 0, start, end;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
                i++;
            start = i;
            while(i < s.size() && s[i] != ' ')
                i++;
            end = i;
            if (start >= end)
                break;
            reverse(s.begin() + start, s.begin() + end);
            if (idx > 0)
                s[idx++] = ' ';
            for (int j = start; j < end && j < s.size(); j++)
                s[idx++] = s[j];
        }
        s.resize(idx);
        return s;
    }
};
```

73. Set Matrix Zeroes
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false;
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
                firstRowZero = true;
        }
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        if (firstRowZero)
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
    }
};
```

173. Binary Search Tree Iterator
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> NodeStack;
public:
    BSTIterator(TreeNode* root) {
        while (root)
        {
            NodeStack.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = NodeStack.top();
        int res = node->val;
        NodeStack.pop();
        TreeNode *cur = node->right;
        while (cur)
        {
            NodeStack.push(cur);
            cur = cur->left;
        }    
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !NodeStack.empty();
    }
};
```

208. Implement Trie (Prefix Tree)
```cpp
class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    TrieNode()
    {
        isWord = false;
        children = vector<TrieNode*>(26, NULL);
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
            delete children[i];
    }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            if (cur->children[pos] == NULL)
                cur->children[pos] = new TrieNode();
            cur = cur->children[pos];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            if (cur->children[pos] == NULL)
                return false;
            cur = cur->children[pos];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            int pos = prefix[i] - 'a';
            if (cur->children[pos] == NULL)
                return false;
            cur = cur->children[pos];
        }
        return true;
    }
};
```

212. Word Search II
```cpp
class Solution {
    struct TrieNode {
        bool isWord;
        vector<TrieNode*> children;
        TrieNode()
        {
            isWord = false;
            children = vector<TrieNode*>(26, NULL);
        }
        ~TrieNode()
        {
            for (int i = 0; i < 26; i++)
                delete children[i];
        }
    };
    
    TrieNode *buildTrie(vector<string>& words)
    {
        TrieNode *root = new TrieNode();
        for (string w : words)
        {
            TrieNode *cur = root;
            for (char c : w)
            {
                if (cur->children[c - 'a'] == NULL)
                    cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
            }
            cur->isWord = true;
        }
        return root;
    }
    
    void dfs(int i, int j, string path, TrieNode *root, vector<string> &res, vector<vector<char>>& board)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        if (board[i][j] == '#')
            return;
        if (root->children[board[i][j] - 'a'] == NULL)
            return;
        root = root->children[board[i][j] - 'a'];
        path +=  board[i][j];
        if (root->isWord)
        {
            res.push_back(path);
            root->isWord = false;
        }
        char c = board[i][j];
        board[i][j] = '#';
        dfs(i-1, j, path, root, res, board);
        dfs(i+1, j, path, root, res, board);
        dfs(i, j-1, path, root, res, board);
        dfs(i, j+1, path, root, res, board);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty()) return res;
        int m = board.size(), n = board[0].size();
        TrieNode *root = buildTrie(words);   
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                dfs(i, j, "", root, res, board);
            }
        delete root;
        return res;
    }
};
```

174. Dungeon Game
```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);
        for (int i = m-2; i >= 0; i--)
        {
            f[i][n-1] = max(1, f[i+1][n-1] - dungeon[i][n-1]);
        }
        for (int j = n-2; j >= 0; j--)
        {
            f[m-1][j] = max(1, f[m-1][j+1] - dungeon[m-1][j]);
        }
        for (int i = m-2; i >= 0; i--)
            for (int j = n-2; j >= 0; j--)
            {
                f[i][j] = max(1, min(f[i][j+1], f[i+1][j]) - dungeon[i][j]);
            }
        return f[0][0];
    }
};
```

198. House Robber
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre1 = 0, pre2 = 0, curMax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curMax = max(pre2 + nums[i], curMax);
            pre2 = pre1;
            pre1 = curMax;
        }
        return curMax;
    }
};
```

213. House Robber II
```cpp
class Solution {
public:
    int robHelper(vector<int>& nums, int left, int right) {
        int pre1 = 0, pre2 = 0, curMax = 0;
        for (int i = left; i <= right; i++)
        {
            curMax = max(pre2 + nums[i], curMax);
            pre2 = pre1;
            pre1 = curMax;
        }
        return curMax;
    }
    
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }
};
```