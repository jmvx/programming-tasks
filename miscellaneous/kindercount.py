#!/usr/bin/env python

def count_to(num):
    for i in range(1, num + 1):
        print i,

def count_from_to(num, other):
    for i in range(num, other + 1):
        print i,

#count_to(100)
count_from_to(20,60)