#!/usr/bin/env python
# encoding: utf-8

import unittest
import subprocess

runCmd = "./../a.out"
testDir = "testcase"
testlist = ["example1", "example2", "example3", "invalid", "nostart", "noend"]
anslist = [4, 9, 6, -1, -1, -1]


class TestOrienteering(unittest.TestCase):
    def setUp(self):
        pass


def execute(test):
    testin = open("%s/%s" % (testDir, test))
    p = subprocess.Popen(
        runCmd.split(), stdin=testin, stdout=subprocess.PIPE)
    testin.close()
    return p.stdout.read().decode('utf-8')


def create_test(test, ans):
    def do_test(self):
        self.assertEqual(execute(test), str(ans))
    return do_test

if __name__ == '__main__':
    for test, ans in zip(testlist, anslist):
        test_method = create_test(test, ans)
        test_method.__name__ = "test_%s" % (test)
        setattr(TestOrienteering, test_method.__name__, test_method)

    unittest.main()
