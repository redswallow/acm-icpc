#Programming Problem - Find Longest Word Made of Other Words

##Solution:
`:!python solver.py`

>read_data: 0.020488s

>find_compound_words: 5.325372s

>sort_compound_words_by_length: 0.370444s

>solver: 5.728703s

>(27, ['ethylenediaminetetraacetate', 'electroencephalographically']) (25, ['phos
phatidylethanolamines', 'immunoelectrophoretically']) 97107


##Idea:

trie + BFS + pruning

Advantages of trie:

1. Predictable O(k) lookup time where k is the size of the key.
2. We can easily get all prefixes of a given word.

Drawbacks of tries:

1. Space-consuming, it is a trade-off between time-complexity and space complexity. We can use radix-tree to get optimized space, but in practice, it doesn't have a reasonable improvement and it takes more time than trie.

Since we have to count all compound words, I use BFS + pruning to get all possible compound words. We can also use DFS instead, which takes less space than BFS but more time. It's a trade-off.

For large data, we can split the original word list into words starting from a-d, e-g, etc. and store them in distributed servers. 

For a single word(request), for example, dogsevildog, it is sent to server a-d. 

Secondly, the server a-d returns that [dog, dogs] are two prefixes. (Here we can still use trie/hash to lookup all prefixes)

Thirdly, suffixes [sevildog, evildog] are sent to server s and e-g respectively. (Like BFS)
Repeat 2 steps above until the suffix is equal to empty string(find a compound word) or the server returns empty prefixes(not a compound word). The requesting can be done in parallel.

What's more, {words: prefixes} can be stored and cached to speedup.


## Dependency:
None

##How to use:
1. Run: `./test.sh` to make sure all testcases are passed
2. Run: `python solver.py`