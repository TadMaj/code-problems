#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
void printResult(ListNode* r);

int main() {
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    ListNode* r = addTwoNumbers(l1, l2);
    printResult(r);
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* last = nullptr;
    int leftOver = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int sum = 0;
        if (l1 != nullptr) {
            int value = l1->val;
            l1 = l1->next;
            sum += value;
        }
        if (l2 != nullptr) {
            int value = l2->val;
            l2 = l2->next;
            sum += value;
        }

        sum += leftOver;
        leftOver = 0;

        if (sum > 9) {
            leftOver = sum / 10;
            sum = sum % 10;
        }

        ListNode* newNode = new ListNode(sum, nullptr);

        if (head != nullptr) {
            last->next = newNode;
            last = last->next;
        }

        if (head == nullptr) {
            head = newNode;
            last = head;
        }

    }

    if (leftOver > 0) {
        ListNode* newNode = new ListNode(leftOver, nullptr);
        last->next = newNode;
    }

    return head;
}

void printResult(ListNode* r) {
    std::cout << "[";
    while (r != nullptr) {
        std::cout << r->val;
        if (r->next != nullptr) std::cout << ",";
        r = r->next;
    }
    std::cout << "]";
}
