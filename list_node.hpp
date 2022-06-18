#ifndef _LIST_NODE_HPP_
#define _LIST_NODE_HPP_

#include <vector>
#include <string>
#include <sstream>
using std::string;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
    static ListNode* constructFromVec(std::vector<int> listVector) {
        ListNode head, *tail = &head;
        for (auto &nodeVal : listVector) {
            tail->next = new ListNode(nodeVal);
            tail = tail->next;
        }
        return head.next;
    }

    vector<int> serializeToVec()
    {
        vector<int> result;
        ListNode *ptr = this;
        while (ptr)
        {
            result.emplace_back(ptr->val);
            ptr = ptr->next;
        }
        return result;
    }

    string serializeToString()
    {
        std::ostringstream oss;
        oss << "[";
        ListNode *ptr = this;
        while (ptr)
        {
            oss << ptr->val << ",";
            ptr = ptr->next;
        }
        string result = oss.str();
        if (result.back() == ',')
        {
            result.back() = ']';
        }
        else
        {
            result += ']';
        }
        return result;
    }
};


#endif