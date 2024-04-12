// level order traversal 
// https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/*
Reverse Level Order Traversal
EasyAccuracy: 62.26%Submissions: 110K+Points: 2
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.
*/
vector<int> reverseLevelOrder(Node *root)
{
    // code 
    vector<int> result;
    if (root == nullptr) return result;

    queue<Node*> q;
    stack<int> s;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        s.push(node->data); // Push node's data onto the stack

        // Enqueue right child first (if exists), then left child
        if (node->right) q.push(node->right);//right ko pehle push kiya but pop mai left ayega since LIFO
        if (node->left) q.push(node->left);
    }

    // Pop elements from the stack and add them to the result vector
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;

}
