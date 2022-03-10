
# To-Do list
## Errors

- [x] Check for errors in Arguments:
</br>
  - [x] Arguments should not contain non-digit characters
</br>
  - [x] Arguments should not contain duplicate numbers
</br>
  - [x] Arguments should not go past the `INT_MAX` _(2147483647)_ or the  `INT_MIN` _(-2147483648)_
</br>
  - [x] Multiple arguments inside double/single quotes, e.g. `./push_swap 1 2 3 "4 5 6 " 7 8 9 `, should be treated too
</br>
  - [ ] Arguments inside a double quote splited by different types of spaces ('\t' '\n' '\v' '\f' '\r' ' ')
  - [ ] Arguments longer than int long
</br>
  - [ ] Arguments inside double quotes with multiple "-" or multiple "+"
</br>
  - [ ] 
</br>

## Algorithms
- [x] Initialize `stack_a` using a doubly linked list _(shouldn't be circular)_
</br>
- [ ] Initialize a `fake_stack` _(shouldn't allocate a new one, just use the `node_a`)_ that holds the address of the node with the smallest value whithin the `stack_a` as its head, and the node before that should be its tail, it could also be circular.
</br>
- [ ] Apply the LIS algorithm on the `fake_stack` it should change the LIS length and the index of each node accordingly
</br>
- [ ] Update the index of each node with its real index, and all the other nodes should have an index of -1.
</br>
- [ ] Push all the nodes with the index of -1 to `stack_b`
</br>
- [ ] Write a garbage Collector that collects all the allocated bytes' addresses, so they can all be freed at the end.
</br>

<!--
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
- [ ] 
-->
