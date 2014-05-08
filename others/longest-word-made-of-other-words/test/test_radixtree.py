import sys
import unittest
from radixtree import RadixTree

sys.path.append('..')


class TestRadixTree(unittest.TestCase):
    def setUp(self):
        self.rt = RadixTree()
        self.rt.insert('cat')
        self.rt.insert('cats')
        self.rt.insert('dog')
        self.rt.insert('data')

    def test_insert(self):
        node = self.rt.root
        # insert 'cat'
        self.assertTrue('cat' in node.children)
        # insert 'cats'
        self.assertTrue('cat' in node.children)
        self.assertTrue('cat' == node.children['cat'].letters)
        self.assertTrue('s' in node.children['cat'].children)
        # insert 'dog'
        # insert 'data'
        self.assertTrue('dog' not in node.children)
        self.assertTrue('d' in node.children)
        self.assertTrue('og' in node.children['d'].children)
        self.assertTrue('ata' in node.children['d'].children)

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
