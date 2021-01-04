/* ------------------------------------------------------------------|
给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

 

示例：

输入：head = 1->4->3->2->5->2, x = 3
输出：1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了96.75%的用户
*	内存消耗：7 MB, 在所有 C++ 提交中击败了68.68%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* heads = small;
    ListNode* large = new ListNode(0);
    ListNode* headl = large;
    while (head) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        }
        else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = nullptr;
    small->next = headl->next;

    ListNode* res = heads->next;
    //实际中注意释放节点避免泄露内存
    //delete heads;
    //delete headl;
    return res;
}