#include <vector>
#include <iostream>
#include "list_node.hpp"
using std::vector;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return nullptr;
        }
        ListNode head, *tail = &head;
        while (true)
        {
            ListNode* curMinNode;
            // find first nonempty list
            int curMinIdx = 0;
            do 
            {  
                curMinNode = lists[curMinIdx++];
            } while(!curMinNode && curMinIdx < lists.size());
            // find current min node
            int nullListNum = curMinIdx - 1; // skip null lists
            for (int i = curMinIdx - 1; i < lists.size(); ++i)
            {
                if (lists[i] == nullptr)
                {
                    nullListNum++;
                    continue;
                }
                if (lists[i]->val <= curMinNode->val)
                {
                    curMinNode = lists[i];
                    curMinIdx = i;
                }
            }
            if (nullListNum == lists.size())
            {
                // all elements is null, we've merged all
                break;
            }
            lists[curMinIdx] = curMinNode->next; // remove from array, advance;
            // insert min node
            curMinNode->next = tail->next; // reserve tail next
            tail->next = curMinNode; // insert new node
            tail = tail->next; // advance
        }
        return head.next; 
    }
};

int main()
{
    vector<vector<int>> data = {{}};
    vector<ListNode*> lists;
    for (auto & list : data)
    {
        lists.emplace_back(ListNode::constructFromVec(list));
    }
    Solution solution;
    auto mergedList = solution.mergeKLists(lists);
    std::cout << mergedList->serializeToString() << std::endl;
    system("pause");
    return 0;
}


