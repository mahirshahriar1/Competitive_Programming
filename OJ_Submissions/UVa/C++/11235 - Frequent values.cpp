#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

const int MX_N = 5 + 1e5; 
int a[MX_N];

struct Node {
    int leftMost, rightMost, frLeftMost, frRightMost, ans;
    Node() {}   
    Node(int a, int b, int c, int d, int e)
    {
        leftMost = a;
        rightMost = b;
        frLeftMost = c;
        frRightMost = d;
        ans = e;
    }
} tree[4 * MX_N];

struct Node merge(struct Node leftNode, struct Node rightNode)
{
    if (leftNode.ans == 0) return rightNode;
    if (rightNode.ans == 0) return leftNode;

    struct Node cur;
    cur.leftMost = leftNode.leftMost;
    cur.rightMost = rightNode.rightMost;
    
    // All the values are same
    // [1,1,1] [1,1,1]
    if (leftNode.leftMost == rightNode.rightMost)
    {
        int tmp = leftNode.frLeftMost + rightNode.frRightMost;
        cur.frLeftMost = tmp;
        cur.frRightMost = tmp;
        cur.ans = tmp;
    }
    // the leftNode has all the same values, and the rightNode has some of them
    // [1,1,1] [1,1,2,2]
    else if (leftNode.leftMost == rightNode.leftMost)
    {
        cur.frLeftMost = leftNode.frLeftMost + rightNode.frLeftMost;
        cur.frRightMost = rightNode.frRightMost;
        cur.ans = max(cur.frLeftMost, rightNode.ans);
    }
    // the rightNode has all the same values, and the leftNode has some of them
    // [1,1,2,2] [2,2,2]
    else if (leftNode.rightMost == rightNode.rightMost)
    {
        cur.frLeftMost = leftNode.frLeftMost;
        cur.frRightMost = leftNode.frRightMost + rightNode.frLeftMost;
        cur.ans = max(cur.frRightMost, leftNode.ans);
    }
    // [1,1,2,2] [2,2,3,4]
    else if (leftNode.rightMost == rightNode.leftMost)
    {
        cur.frLeftMost = leftNode.frLeftMost;
        cur.frRightMost = rightNode.frRightMost;
        cur.ans = max({leftNode.ans, rightNode.ans, leftNode.frRightMost + rightNode.frLeftMost});
    }
    // [1,1,2,2] [3,4,5,6]
    else
    {
        cur.frLeftMost = leftNode.frLeftMost;
        cur.frRightMost = rightNode.frRightMost;
        cur.ans = max(leftNode.ans, rightNode.ans);
    }
    return cur;
}

void build(int node, int tL, int tR) {
    if (tL == tR) {
        tree[node] = Node(a[tL], a[tL], 1, 1, 1);
        return;
    }
    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    build(left, tL, mid);
    build(right, mid + 1, tR);
    tree[node] = merge(tree[left], tree[right]);
}

Node query(int node, int tL, int tR, int qL, int qR) {
    if (tL >= qL && tR <= qR) {
        return tree[node];
    }
    if (tR < qL || tL > qR) {
        return Node(0, 0, 0, 0, 0);
    }
    int mid = (tL + tR) / 2;
    Node QL = query(2 * node, tL, mid, qL, qR);
    Node QR = query(2 * node + 1, mid + 1, tR, qL, qR);
    return merge(QL, QR);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    while (cin >> n, n != 0)
    {        
        cin >> q;
        
        for (int i = 0; i < n; i++) cin >> a[i];
        build(1, 0, n - 1);
        while (q--)
        {
            int l, r;
            cin >> l >> r;
          
            cout << query(1, 0, n - 1, l - 1, r - 1).ans << endl;
        }
    }

    return 0;
}