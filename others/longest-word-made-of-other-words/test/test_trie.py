import sys
import unittest
from trie import Trie

sys.path.append('..')


class TestTrie(unittest.TestCase):
    def setUp(self):
        self.rt = Trie()
        self.rt.insert('cat')
        self.rt.insert('cats')
        self.rt.insert('dog')
        self.rt.insert('data')

    def test_insert(self):
        node = self.rt.root
        # insert 'cat'
        self.assertTrue('c' in node.children)
        # insert 'cats'
        self.assertTrue('c' == node.children['c'].letter)
        self.assertTrue('a' in node.children['c'].children)
        # insert 'dog'
        # insert 'data'
        self.assertTrue('d' in node.children)
        self.assertTrue('o' in node.children['d'].children)
        self.assertTrue('a' in node.children['d'].children)

    def test_contains(self):
        self.assertTrue('cat' in self.rt)
        self.assertTrue('cats' in self.rt)
        self.assertTrue('dog' in self.rt)
        self.assertTrue('data' in self.rt)
        self.assertFalse('ca' in self.rt)
        self.assertFalse('c' in self.rt)
        self.assertFalse('d' in self.rt)
        self.assertFalse('dogs' in self.rt)

    def test_has_prefixes(self):
        self.assertEquals(['cat'], self.rt.has_prefixes('cat'))
        self.assertEquals(['cat', 'cats'], self.rt.has_prefixes('cats'))
        self.assertEquals(['dog'], self.rt.has_prefixes('dog'))
