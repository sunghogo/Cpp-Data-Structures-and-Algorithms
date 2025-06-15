#include <iostream>
#include "linked_lists_leetcode/linked_list.h"

using namespace std;

//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+

int main() {
  // Function to convert nullptr to "0 (nullptr)"
  auto ptrToNum = [](Node* ptr) -> string {
    return (ptr == nullptr) ? "0 (nullptr)" : to_string(ptr->value);
  };

  // Helper function to check test result
  auto checkTestResult = [](bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
  };

  // Function to convert boolean to string for easy comparison
  auto boolToStr = [](bool val) -> string { return val ? "True" : "False"; };

  /* LL Find Middle Node Tests */
  // Test: EmptyList
  {
    cout << "\n------ LinkedList Test: EmptyList ------\n";

    LinkedList list(1);
    list.makeEmpty();

    list.printList();

    Node* middle = list.findMiddleNode();

    cout << "Middle node: " << ptrToNum(middle) << endl;

    checkTestResult(middle == nullptr);
  }

  // Test: SingleElement
  {
    cout << "\n------ LinkedList Test: SingleElement ------\n";

    LinkedList list(1);

    list.printList();

    Node* middle = list.findMiddleNode();

    cout << "Middle node: " << ptrToNum(middle) << endl;

    checkTestResult(middle == list.getHead());
  }

  // Test: EvenNumberOfElements
  {
    cout << "\n------ LinkedList Test: EvenNumberOfElements ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.printList();

    Node* middle = list.findMiddleNode();

    cout << "Middle node: " << ptrToNum(middle) << endl;

    checkTestResult(middle->value == 3);
  }

  // Test: OddNumberOfElements
  {
    cout << "\n------ LinkedList Test: OddNumberOfElements ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);

    list.printList();

    Node* middle = list.findMiddleNode();

    cout << "Middle node: " << ptrToNum(middle) << endl;

    checkTestResult(middle->value == 2);
  }

  /* LL Has Loop Tests */
  // Test: EmptyListHasLoop
  {
    cout << "\n------ LinkedList Test: EmptyListHasLoop ------\n";

    LinkedList list(1);
    list.makeEmpty();

    list.printList();

    bool hasLoop = list.hasLoop();

    cout << "Has loop: " << boolToStr(hasLoop) << endl;

    checkTestResult(!hasLoop);
  }

  // Test: SingleElementNoLoop
  {
    cout << "\n------ LinkedList Test: SingleElementNoLoop ------\n";

    LinkedList list(1);

    list.printList();

    bool hasLoop = list.hasLoop();

    cout << "Has loop: " << boolToStr(hasLoop) << endl;

    checkTestResult(!hasLoop);
  }

  // Test: MultipleElementsNoLoop
  {
    cout << "\n------ LinkedList Test: MultipleElementsNoLoop ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.printList();

    bool hasLoop = list.hasLoop();

    cout << "Has loop: " << boolToStr(hasLoop) << endl;

    checkTestResult(!hasLoop);
  }

  // Test: SingleElementWithLoop
  {
    cout << "\n------ LinkedList Test: SingleElementWithLoop ------\n";

    LinkedList list(1);
    Node* tail = list.getTail();
    tail->next = list.getHeadPtr();

    // Can't print the list because it has a loop!

    bool hasLoop = list.hasLoop();

    cout << "Has loop: " << boolToStr(hasLoop) << endl;

    tail->next = nullptr;  // Break the loop

    checkTestResult(hasLoop);
  }

  // Test: MultipleElementsWithLoop
  {
    cout << "\n------ LinkedList Test: MultipleElementsWithLoop ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    Node* tail = list.getTail();
    tail->next = list.getHeadPtr();

    // Can't print the list because it has a loop!

    bool hasLoop = list.hasLoop();

    cout << "Has loop: " << boolToStr(hasLoop) << endl;

    tail->next = nullptr;  // Break the loop

    checkTestResult(hasLoop);
  }

  /* LL Find Kth Node From End Tests*/
  // Test: EmptyList
  {
    cout << "\n------ LinkedList Test: EmptyList ------\n";

    LinkedList list(1);
    list.makeEmpty();

    list.printList();

    Node* result = list.findKthFromEnd(1);

    cout << "Kth from end: " << ptrToNum(result) << endl;

    checkTestResult(result == nullptr);
  }

  // Test: KGreaterThanListLength
  {
    cout << "\n------ LinkedList Test: KGreaterThanListLength ------\n";

    LinkedList list(1);
    list.append(2);

    list.printList();

    Node* result = list.findKthFromEnd(3);

    cout << "Kth from end: " << ptrToNum(result) << endl;

    checkTestResult(result == nullptr);
  }

  // Test: KEqualsListLength
  {
    cout << "\n------ LinkedList Test: KEqualsListLength ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);

    list.printList();

    Node* result = list.findKthFromEnd(3);

    cout << "Kth from end: " << ptrToNum(result) << endl;

    checkTestResult(result && result->value == 1);
  }

  // Test: KLessThanListLength
  {
    cout << "\n------ LinkedList Test: KSecondFromEnd ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    list.printList();

    Node* result = list.findKthFromEnd(2);

    cout << "Kth from end: " << ptrToNum(result) << endl;

    checkTestResult(result && result->value == 4);
  }

  /* LL Remove Duplicates Tests */
  // Test: RemoveDuplicatesEmptyList
  {
    cout << "\n------ Test: RemoveDuplicatesEmptyList ------\n";

    LinkedList list(1);
    list.makeEmpty();

    cout << "BEFORE:    ";
    list.printList();

    list.removeDuplicates();

    cout << "AFTER:     ";
    list.printList();

    Node* head = list.getHead();
    checkTestResult(head == nullptr);
  }

  // Test: RemoveDuplicatesSingleElement
  {
    cout << "\n------ Test: RemoveDuplicatesSingleElement ------\n";

    LinkedList list(1);

    cout << "BEFORE:    ";
    list.printList();

    list.removeDuplicates();

    cout << "AFTER:     ";
    list.printList();

    Node* head = list.getHead();
    checkTestResult(head && head->value == 1);
  }

  // Test: RemoveDuplicatesNoDuplicates
  {
    cout << "\n------ Test: RemoveDuplicatesNoDuplicates ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);

    cout << "BEFORE:    ";
    list.printList();

    list.removeDuplicates();

    cout << "AFTER:     ";
    list.printList();

    Node* head = list.getHead();
    checkTestResult(head && head->value == 1);
  }

  // Test: RemoveDuplicatesHasDuplicates
  {
    cout << "\n------ Test: RemoveDuplicatesHasDuplicates ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(2);
    list.append(3);

    cout << "BEFORE:    ";
    list.printList();

    list.removeDuplicates();

    cout << "AFTER:     ";
    list.printList();

    // Check for duplicates
    Node* current = list.getHead();
    bool noDuplicates = true;

    while (current && current->next) {
      if (current->value == current->next->value) {
        noDuplicates = false;
        break;
      }
      current = current->next.get();
    }

    checkTestResult(noDuplicates);
  }

  /* LL Binary to Decimal Tests */
  // Test: BinaryToDecimalEmptyList
  {
    cout << "\n------ Test: BinaryToDecimalEmptyList ------\n";

    LinkedList list(1);
    list.makeEmpty();

    cout << "BINARY:    ";
    list.printList();

    int decimal = list.binaryToDecimal();

    cout << "DECIMAL:   " << decimal << endl;

    checkTestResult(decimal == 0);
  }

  // Test: BinaryToDecimalSingleElement
  {
    cout << "\n------ Test: BinaryToDecimalSingleElement ------\n";

    LinkedList list(1);

    cout << "BINARY:    ";
    list.printList();

    int decimal = list.binaryToDecimal();

    cout << "DECIMAL:   " << decimal << endl;

    checkTestResult(decimal == 1);
  }

  // Test: BinaryToDecimalMultipleElements
  {
    cout << "\n------ Test: BinaryToDecimalMultipleElements ------\n";

    LinkedList list(1);
    list.append(0);
    list.append(1);
    list.append(1);

    cout << "BINARY:    ";
    list.printList();

    int decimal = list.binaryToDecimal();

    cout << "DECIMAL:   " << decimal << endl;

    checkTestResult(decimal == 11);
  }

  // Test: BinaryToDecimalAllZeros
  {
    cout << "\n------ Test: BinaryToDecimalAllZeros ------\n";

    LinkedList list(0);
    list.append(0);
    list.append(0);
    list.append(0);

    cout << "BINARY:    ";
    list.printList();

    int decimal = list.binaryToDecimal();

    cout << "DECIMAL:   " << decimal << endl;

    checkTestResult(decimal == 0);
  }

  // Test: BinaryToDecimalAllOnes
  {
    cout << "\n------ Test: BinaryToDecimalAllOnes ------\n";

    LinkedList list(1);
    list.append(1);
    list.append(1);
    list.append(1);

    cout << "BINARY:    ";
    list.printList();

    int decimal = list.binaryToDecimal();

    cout << "DECIMAL:   " << decimal << endl;

    checkTestResult(decimal == 15);
  }

  /* LL Partition List */
  // Test: PartitionEmptyList
  {
    cout << "\n------ Test: PartitionEmptyList ------\n";

    LinkedList list(1);
    list.makeEmpty();

    cout << "BEFORE:    ";
    list.printList();

    cout << "partitionList(3)\n";
    cout << "EXPECTED:  empty\n";

    list.partitionList(3);

    cout << "ACTUAL:    ";
    list.printList();

    Node* head = list.getHead();
    checkTestResult(head == nullptr);
  }

  // Test: PartitionSingleElement
  {
    cout << "\n------ Test: PartitionSingleElement ------\n";

    LinkedList list(1);

    cout << "BEFORE:    ";
    list.printList();

    cout << "partitionList(3)\n";
    cout << "EXPECTED:  1\n";

    list.partitionList(3);

    cout << "ACTUAL:    ";
    list.printList();

    Node* head = list.getHead();
    checkTestResult(head && head->value == 1);
  }

  // Test: PartitionAllLessThanX
  {
    cout << "\n------ Test: PartitionAllLessThanX ------\n";

    LinkedList list(1);
    list.append(2);
    list.append(3);

    cout << "BEFORE:    ";
    list.printList();

    cout << "partitionList(4)\n";
    cout << "EXPECTED:  1 -> 2 -> 3\n";

    list.partitionList(4);

    cout << "ACTUAL:    ";
    list.printList();

    Node* head = list.getHead();
    checkTestResult(head && head->value == 1);
  }

  // Test: PartitionMixedNumbers
  {
    cout << "\n------ Test: PartitionMixedNumbers ------\n";

    LinkedList list(1);
    list.append(4);
    list.append(3);
    list.append(2);
    list.append(5);
    list.append(2);

    cout << "BEFORE:    ";
    list.printList();

    cout << "partitionList(3)\n";
    cout << "EXPECTED:  1 -> 2 -> 2 -> 4 -> 3 -> 5\n";

    list.partitionList(3);

    cout << "ACTUAL:    ";
    list.printList();

    // Check if the list is partitioned correctly
    Node* current = list.getHead();
    bool isPartitioned = true;
    bool crossedPartitionValue = false;

    while (current && current->next) {
      if (current->value >= 3) {
        crossedPartitionValue = true;
      }
      if (crossedPartitionValue && current->value < 3) {
        isPartitioned = false;
        break;
      }
      current = current->next.get();
    }

    checkTestResult(isPartitioned);
  }
}
