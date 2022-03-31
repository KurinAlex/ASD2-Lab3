# Algorithms and data structures 2 - Lab 3

Implement the priority queue to effectively solve the problem. 
Enemies appear in sight in front of the bot. Each enemy is characterized by the level of health, possible damage, player skill, etc. 
According to a certain criterion, the bot must choose the most optimal target for itself and destroy it, then move on to the next target. 
Keep in mind that new enemies with higher priorities may appear during the game:
1. Create a structure for storing objects with characteristics according to the task:
    - choose a specific criterion to determine a higher priority object based on its characteristics
    - overload the operator "<" to compare two objects by criterion
    - overload operator "==" to determine the equality of two objects by the same criterion
2. Implement a priority queue based on a non-growing binary heap:
    1. Create a PriorityQueue structure that will contain a binary tree for the binary heap. 
       To store a binary tree you can use the usual dynamic array, which has already been implemented in previous works.
    2. Implement the basic methods of moving the binary tree:
        - getParent (index) find the index of the parent node
        - getLeftChild (index) find the index of the left child node
        - getRightChild (index) find the index of the right child node
    3. Implement internal methods to maintain the properties of non-growing heap:
        - siftUp (index) sift the element up the tree
        - siftDown (index) sift the item down the tree
    4. Implement the basic methods for the priority queue:
        - push (object) add a new element to the queue
        - top () get the top element from the queue
        - pop () remove the top item from the queue
        - size () find the number of items in the queue
        - empty () check the queue for emptiness
3. Perform the test using the testPriorityQueue () function. 
   Check the correctness and speed of work, comparing with the ready-made library solution STL priority_queue.
4. Think over realization of sorting by heap (pyramidal sorting) on the basis of a binary heap.
   
Optional extra task:
Implement batch sorting, compare it with the ready library solution STL std :: sort () or with other sorting algorithms implemented in previous works - 
conduct testing with time measurements on different input data.
