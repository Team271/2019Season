#!/bin/sh
# Copyright (c) 2012-2013 National Instruments.
# All rights reserved.

if [ -e /proc/cpu/alignment ] ; then
       echo "3" > /proc/cpu/alignment
fi

