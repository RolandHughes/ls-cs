#!/bin/sh
#
find -iname *.cpp | xargs astyle -n
find -iname *.h | xargs astyle -n
