/*
## Assignment 14: Manual Circular Assembly to practice handling loop execution paths safely.

### Assignment Specifications:
1. **Define the Layout:** Use a classic single-direction structure blueprint:
      ```
      typedef struct circleNode {
      int data;
      struct circleNode* next;
      } CircleNode_t;
      ```
2. **Manually Allocate 3 Nodes:** In a clean main() file context, allocate node1, node2, and node3 via individual malloc() calls. Load them with payloads 10, 20, and 30.
3. **Close the Loop Engine:**
   1. Wire node1->next = node2;
   2. Wire node2->next = node3;
   3. The Circular Connection: Wire node3->next = node1; (The loop boundary wrapper).
4. **Print exactly once:**Write a safe do-while loop pattern that checks when current == node1 on its second pass to stop printing before hitting an infinite loop.
5. **Break Circle Before Deallocation:** Set node3->next = NULL; explicitly right before you call your free() functions to protect the stack from trace collapse corruption errors.

*/

