#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 105;
int nodeNum, node[MAX], Left[MAX], Right[MAX], depth[MAX];
char tree[12][1<<13];

// cur의 subtree 사이즈를 return 해줌
// left는 현재까지 계산한 나보다 왼쪽에 있는 노드의 수
int printTree(int cur, int left, int depth) {
    int ret = 1;
    if (Left[cur] != 0) {
        int t = printTree(Left[cur], left, depth+1);
        ret += t;
    }
    tree[depth][left+ret] = node[cur];
    if (Right[cur] != 0) {
        ret += printTree(Right[cur], left+ret, depth+1);
    }
    return ret;
}

int main() {
    string s;
    cin >> s;

    memset(tree, ' ', sizeof(tree));
    int internalPathLength = 0;
    for (char c : s) {
        // 처음 글자의 경우는 아무것도 없어서 직접 루트를 넣어줘야 함
        if (nodeNum == 0) {
            node[++nodeNum] = c;
            continue;
        }

        // 루트(1)에서 시작해서 왼쪽 또는 오른쪽으로 내려가다가 자식이 없는 곳에 도착하면 새로운 노드 할당
        int cur = 1;
        while(true) {
            if (c <= node[cur]) {       // 더 작거나 같다면 왼쪽으로
                if (Left[cur] == 0) {   // 왼쪽 자식이 없다면, 새로 만들고 그 노드를 cur의 왼쪽자식으로 만들고 break
                    node[++nodeNum] = c;
                    depth[nodeNum] = depth[cur] + 1;
                    internalPathLength += depth[nodeNum];
                    Left[cur] = nodeNum;
                    break;
                }
                cur = Left[cur];        // 있다면 왼쪽으로 이동
            } else {
                if (Right[cur] == 0) {
                    node[++nodeNum] = c;
                    depth[nodeNum] = depth[cur] + 1;
                    internalPathLength += depth[nodeNum];
                    Right[cur] = nodeNum;
                    break;
                }
                cur = Right[cur];
            }
        }
    }

    int externalNum = 0, externalPathLength = 0, maxDepth = 0;
    for (int i=1; i<=nodeNum; i++) {
        if (Left[i] == 0) {
            externalPathLength += depth[i]+1;
            externalNum++;
        }
        if (Right[i] == 0) {
            externalPathLength += depth[i]+1;
            externalNum++;
        }
        maxDepth = max(maxDepth, depth[i]);
    }
    cout << "internal length: " << internalPathLength << "\n";
    cout << "external num: " << externalNum << "\n";
    cout << "external length: " << externalPathLength << "\n";
    cout << "depth: " << maxDepth << "\n";

    printTree(1, 0, 0);

    for (int i=0; i<=maxDepth; i++) {
        cout << "------------------------------------------------------\n";
        printf("Depth %02d:    ", i);
        for (int j=0; j<=nodeNum; j++) cout << tree[i][j];
        cout << "\n";
    }
}
