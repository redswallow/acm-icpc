import sys
import unittest
from solver import solver

sys.path.append('..')


class TestSolver(unittest.TestCase):
    def setUp(self):
        pass

    def test_solver_on_small_data(self):
        data = '../data/words_small.txt'
        [largest_word, second_largest_word, count] = solver(data)
        self.assertEquals(largest_word, (11, ['catsdogcats']))
        self.assertEquals(second_largest_word, (10, ['dogcatsdog']))
        self.assertEquals(count, 3)
