class Node:
    def __init__(self, letters=None, is_terminate=False):
        self.letters = letters
        self.is_terminate = is_terminate
        self.children = {}


class RadixTree:
    def __init__(self):
        self.root = Node('')

    def _get_common_prefix(self, key, word):
        l = min(len(key), len(word))
        prefix = ''
        for i in xrange(l):
            if key[i] != word[i]:
                return prefix
            prefix = prefix + word[i]
        return prefix

    def _find_key(self, node, word):
        for key in node.children:
            prefix = self._get_common_prefix(key, word)
            if len(prefix) > 0:
                return (key, prefix)
        return (None, None)

    def insert(self, word):
        node = self.root
        while word:
            key, prefix = self._find_key(node, word)
            if key is None:
                node.children[word] = Node(word)
                node = node.children[word]
                word = ''
            else:
                if prefix == key:
                    node = node.children[key]
                    word = word[len(key):]
                else:
                    child_node = node.children.pop(key)
                    child_node.letters = key[len(prefix):]
                    node.children[prefix] = Node(prefix)
                    node = node.children[prefix]
                    node.children[key[len(prefix):]] = child_node
                    word = word[len(prefix):]
        node.is_terminate = True

    def __contains__(self, word):
        node = self.root
        while word:
            key, prefix = self._find_key(node, word)
            if key is None or prefix != key:
                return False
            else:
                node = node.children[key]
                word = word[len(key):]
        return node.is_terminate

    def has_prefixes(self, word):
        candidate_prefix = ''
        prefixes = []
        node = self.root
        while word:
            key, prefix = self._find_key(node, word)
            if key is None or prefix != key:
                return prefixes
            else:
                node = node.children[key]
                candidate_prefix = candidate_prefix + prefix
                word = word[len(key):]
                if node.is_terminate:
                    prefixes.append(candidate_prefix)
        return prefixes
