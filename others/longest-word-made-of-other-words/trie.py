class Node:
    def __init__(self, letter=None, is_terminate=False):
        self.letter = letter
        self.is_terminate = is_terminate
        self.children = {}


class Trie:
    def __init__(self):
        self.root = Node('')

    def insert(self, word):
        node = self.root
        for letter in word:
            if letter not in node.children:
                node.children[letter] = Node(letter)
            node = node.children[letter]
        node.is_terminate = True

    def __contains__(self, word):
        node = self.root
        for letter in word:
            if letter not in node.children:
                return False
            node = node.children[letter]
        return node.is_terminate

    def has_prefixes(self, word):
        prefix = ''
        prefixes = []
        node = self.root
        for letter in word:
            if letter not in node.children:
                return prefixes
            prefix = prefix + letter
            node = node.children[letter]
            if node.is_terminate:
                prefixes.append(prefix)
        return prefixes
