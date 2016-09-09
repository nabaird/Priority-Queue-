# Priority-Queue-
My implementation of a priority queue (heap)

I implemented this priority queue using an array, taking advantage of the fact that by concieving of the heap as a balanced tree one can reach a parent or child node by dividing the index of the node in question by 2 or by multiplying it by 2 respectively. In the case of insertion a 'hole' is created at the very bottom of the heap and gradually shifted upward until a suitable location has been reached for the inserted value. In the case of removal a hole is created at the root of the tree (index 1) and the hole is gradually bumped down the tree until all members are properly stored in the structure. 
