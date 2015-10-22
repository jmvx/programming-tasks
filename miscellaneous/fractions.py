#!/usr/bin/env python

from fractions import Fraction
from decimal import *

print Fraction(Fraction(1,2),Fraction(1,4))

def equiv(f1, f2):
    if f1 == f2:
        print "The fractions are equivalent"
    else:
        print "The fractions are not equivalent"

equiv(Fraction(1,2),Fraction(2,4))

def proportional_coordinates(unit_rate):
    change_y = unit_rate.numerator
    change_x = unit_rate.denominator
    x = 0
    y = 0
    print "(0,0)",
    while x < 10:
        x = x + change_x
        y = y + change_y
        print '({},{})' .format(x,y),

    y = Decimal(Decimal(y)/Decimal(x))
    x = Decimal(Decimal(x)/Decimal(x))

    print '\nUnit Rate Coordinate: ({:.3f},{:.3f})' .format(x,y)
    print 'Unit Rate: {:.3f}' .format(y)

proportional_coordinates(Fraction(2,3))

