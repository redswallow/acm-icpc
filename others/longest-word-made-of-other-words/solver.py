import collections
from trie import Trie
from radixtree import RadixTree
from timer import timer


@timer
def read_data(filename):
    return open(filename).read().split()


@timer
def find_compound_words(words):
    ''' trie + BFS + pruning
    Advantages of trie:
    1. Predictable O(k) lookup time where k is the size of the key.
    2. We can easily get all prefixes of a given word.
    Drawbacks of tries:
    1. Space-consuming, it is a trade-off between time-complexity and space\
    complexity. We can use radix-tree to get optimized space, but in \
    practice, it doesn't have a reasonable improvement and it takes more\
    time than trie.
    '''
    compound_words = set([])
    trie = Trie()
    queue = collections.deque()
    prefixes_dict = {}
    for word in words:
        prefixes = trie.has_prefixes(word)
        for prefix in prefixes:
            queue.append((word, word[len(prefix):]))
        trie.insert(word)
    while queue:
        word, suffix = queue.popleft()
        # pruning
        if word in compound_words:
            continue
        # find a compund word
        if suffix in trie:
            compound_words.add(word)
        else:
            prefixes = trie.has_prefixes(suffix)
            for prefix in prefixes:
                queue.append((word, suffix[len(prefix):]))
    return compound_words


@timer
def sort_compound_words_by_length(words):
    length_dict = {}
    for word in words:
        if len(word) not in length_dict:
            length_dict[len(word)] = [word]
        else:
            length_dict[len(word)].append(word)
    return sorted(length_dict.iteritems(),
                  key=lambda item: item[0],
                  reverse=True)


@timer
def solver(filename):
    words = read_data(filename)
    compound_words = find_compound_words(words)
    sorted_compound_words = sort_compound_words_by_length(compound_words)
    return [sorted_compound_words[1],
            sorted_compound_words[2],
            len(compound_words)]


if __name__ == '__main__':
    data = 'data/wordsforproblem.txt'
    [largest_word, second_largest_word, count] = solver(data)
    print largest_word, second_largest_word, count
